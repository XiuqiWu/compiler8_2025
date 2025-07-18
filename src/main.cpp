#include <iostream>
#include <string>
#include <fstream>

#include "antlr4-runtime.h"
#include "../grammar/CACTLexer.h"
#include "../grammar/CACTParser.h"
#include "../grammar/CACTBaseListener.h"

#include "semanticAnalysis.h"
#include "symbolTable.h"
#include "IR.h"

using namespace antlr4;

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Missing input source file." << std::endl;
        return 1;
    }

    const std::string sourceName = argv[1];
    std::string asmName = (argc == 3) ? argv[2] : sourceName.substr(0, sourceName.find_last_of(".")) + ".s";

    std::ifstream sourceStream(sourceName);
    if (!sourceStream.is_open()) {
        std::cerr << "Error: Cannot open source file: " << sourceName << std::endl;
        return 1;
    }

    ANTLRInputStream input(sourceStream);
    CACTLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CACTParser parser(&tokens);
    
    tree::ParseTree* parseTreeRoot = parser.compUnit();

    const int lexErrs = lexer.getNumberOfSyntaxErrors();
    const int parseErrs = parser.getNumberOfSyntaxErrors();

    if (lexErrs > 0 || parseErrs > 0) {
        if (lexErrs > 0) {
            std::cout << "Error: There are " << lexErrs << " syntax errors detected by lexer." << std::endl;
        }
        if (parseErrs > 0) {
            std::cout << "Error: There are " << parseErrs << " syntax errors detected by parser." << std::endl;
        }
        return 1;
    }

    BlockInfo globalInfo(nullptr);
    IRProgram ir(sourceName);
    IRGenerator irGen(&ir);
    SemanticAnalysis semanticChecker(&globalInfo, &irGen);

    try {
        tree::ParseTreeWalker::DEFAULT.walk(&semanticChecker, parseTreeRoot);
    } catch (const std::exception& ex) {
        std::cerr << "Semantic Error: " << ex.what() << std::endl;
        return 1;
    }

    ir.print();

    TargetCodeList targetCode;
    ir.generatetg(&targetCode);

    std::ofstream asmOutFile(asmName);
    if (!asmOutFile) {
        std::cerr << "Error: Could not create output file: " << asmName << std::endl;
        return 1;
    }

    asmOutFile << targetCode;

    return 0;
}
