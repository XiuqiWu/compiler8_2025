
    #include <vector>
    #include <string>
    #include "../src/CACT.h"
    #include "../src/symbolTable.h"
    #include "../src/IR.h"


// Generated from CACT.g4 by ANTLR 4.13.1


#include "CACTListener.h"

#include "CACTParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CACTParserStaticData final {
  CACTParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CACTParserStaticData(const CACTParserStaticData&) = delete;
  CACTParserStaticData(CACTParserStaticData&&) = delete;
  CACTParserStaticData& operator=(const CACTParserStaticData&) = delete;
  CACTParserStaticData& operator=(CACTParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag cactParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
CACTParserStaticData *cactParserStaticData = nullptr;

void cactParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (cactParserStaticData != nullptr) {
    return;
  }
#else
  assert(cactParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CACTParserStaticData>(
    std::vector<std::string>{
      "compUnit", "bType", "decl", "constDecl", "constDef", "varDecl", "varDef", 
      "funcDef", "funcType", "funcFParams", "funcFParam", "block", "blockItem", 
      "stmt", "exp", "cond", "primaryExp", "unaryExp", "unaryOp", "mulExp", 
      "mulOp", "addExp", "addOp", "relExp", "relOp", "eqExp", "eqOp", "lAndExp", 
      "lOrExp", "constArrExp", "constExp", "numVal", "boolVal", "lVal", 
      "rVal", "funcVal", "funcRParams"
    },
    std::vector<std::string>{
      "", "'int'", "'bool'", "'double'", "'float'", "'const'", "','", "';'", 
      "'='", "'['", "']'", "'('", "')'", "'void'", "'{'", "'}'", "'if'", 
      "'else'", "'while'", "'break'", "'continue'", "'return'", "'+'", "'-'", 
      "'!'", "'*'", "'/'", "'%'", "'<'", "'>'", "'<='", "'>='", "'=='", 
      "'!='", "'&&'", "'||'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "BoolConst", "Ident", "IntConst", "FloatConst", "DoubleConst", 
      "ArraySymbol", "NewLine", "WhiteSpace", "BlockComment", "LineComment"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,45,375,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,1,0,1,0,5,0,77,8,0,10,0,12,0,80,9,0,1,0,1,0,1,1,1,1,1,2,
  	1,2,3,2,88,8,2,1,3,1,3,1,3,1,3,1,3,5,3,95,8,3,10,3,12,3,98,9,3,1,3,1,
  	3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,111,8,4,1,5,1,5,1,5,1,5,5,5,
  	117,8,5,10,5,12,5,120,9,5,1,5,1,5,1,6,1,6,1,6,3,6,127,8,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,3,6,135,8,6,3,6,137,8,6,1,7,1,7,1,7,1,7,3,7,143,8,7,1,7,1,
  	7,1,7,1,8,1,8,1,9,1,9,1,9,5,9,153,8,9,10,9,12,9,156,9,9,1,10,1,10,1,10,
  	3,10,161,8,10,1,11,1,11,5,11,165,8,11,10,11,12,11,168,9,11,1,11,1,11,
  	1,12,1,12,3,12,174,8,12,1,13,1,13,1,13,1,13,1,13,1,13,3,13,182,8,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,
  	13,212,8,13,1,13,3,13,215,8,13,1,14,1,14,3,14,219,8,14,1,15,1,15,1,16,
  	1,16,1,16,1,16,1,16,1,16,3,16,229,8,16,1,17,1,17,1,17,1,17,1,17,3,17,
  	236,8,17,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,5,19,247,8,19,10,
  	19,12,19,250,9,19,1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,5,21,261,
  	8,21,10,21,12,21,264,9,21,1,22,1,22,1,23,1,23,1,23,3,23,271,8,23,1,23,
  	1,23,1,23,1,23,5,23,277,8,23,10,23,12,23,280,9,23,1,24,1,24,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,5,25,291,8,25,10,25,12,25,294,9,25,1,26,1,26,
  	1,27,1,27,1,27,1,27,1,27,1,27,5,27,304,8,27,10,27,12,27,307,9,27,1,28,
  	1,28,1,28,1,28,1,28,1,28,5,28,315,8,28,10,28,12,28,318,9,28,1,29,1,29,
  	1,29,1,29,5,29,324,8,29,10,29,12,29,327,9,29,3,29,329,8,29,1,29,1,29,
  	1,30,1,30,3,30,335,8,30,1,31,1,31,1,31,3,31,340,8,31,1,32,1,32,1,33,1,
  	33,1,33,1,33,1,33,1,33,3,33,350,8,33,1,34,1,34,1,34,1,34,1,34,1,34,3,
  	34,358,8,34,1,35,1,35,1,35,3,35,363,8,35,1,35,1,35,1,36,1,36,1,36,5,36,
  	370,8,36,10,36,12,36,373,9,36,1,36,0,6,38,42,46,50,54,56,37,0,2,4,6,8,
  	10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,
  	56,58,60,62,64,66,68,70,72,0,7,1,0,1,4,2,0,1,4,13,13,1,0,22,24,1,0,25,
  	27,1,0,22,23,1,0,28,31,1,0,32,33,382,0,78,1,0,0,0,2,83,1,0,0,0,4,87,1,
  	0,0,0,6,89,1,0,0,0,8,110,1,0,0,0,10,112,1,0,0,0,12,136,1,0,0,0,14,138,
  	1,0,0,0,16,147,1,0,0,0,18,149,1,0,0,0,20,157,1,0,0,0,22,162,1,0,0,0,24,
  	173,1,0,0,0,26,214,1,0,0,0,28,218,1,0,0,0,30,220,1,0,0,0,32,228,1,0,0,
  	0,34,235,1,0,0,0,36,237,1,0,0,0,38,239,1,0,0,0,40,251,1,0,0,0,42,253,
  	1,0,0,0,44,265,1,0,0,0,46,270,1,0,0,0,48,281,1,0,0,0,50,283,1,0,0,0,52,
  	295,1,0,0,0,54,297,1,0,0,0,56,308,1,0,0,0,58,319,1,0,0,0,60,334,1,0,0,
  	0,62,339,1,0,0,0,64,341,1,0,0,0,66,349,1,0,0,0,68,357,1,0,0,0,70,359,
  	1,0,0,0,72,366,1,0,0,0,74,77,3,4,2,0,75,77,3,14,7,0,76,74,1,0,0,0,76,
  	75,1,0,0,0,77,80,1,0,0,0,78,76,1,0,0,0,78,79,1,0,0,0,79,81,1,0,0,0,80,
  	78,1,0,0,0,81,82,5,0,0,1,82,1,1,0,0,0,83,84,7,0,0,0,84,3,1,0,0,0,85,88,
  	3,6,3,0,86,88,3,10,5,0,87,85,1,0,0,0,87,86,1,0,0,0,88,5,1,0,0,0,89,90,
  	5,5,0,0,90,91,3,2,1,0,91,96,3,8,4,0,92,93,5,6,0,0,93,95,3,8,4,0,94,92,
  	1,0,0,0,95,98,1,0,0,0,96,94,1,0,0,0,96,97,1,0,0,0,97,99,1,0,0,0,98,96,
  	1,0,0,0,99,100,5,7,0,0,100,7,1,0,0,0,101,102,5,37,0,0,102,103,5,8,0,0,
  	103,111,3,60,30,0,104,105,5,37,0,0,105,106,5,9,0,0,106,107,5,38,0,0,107,
  	108,5,10,0,0,108,109,5,8,0,0,109,111,3,58,29,0,110,101,1,0,0,0,110,104,
  	1,0,0,0,111,9,1,0,0,0,112,113,3,2,1,0,113,118,3,12,6,0,114,115,5,6,0,
  	0,115,117,3,12,6,0,116,114,1,0,0,0,117,120,1,0,0,0,118,116,1,0,0,0,118,
  	119,1,0,0,0,119,121,1,0,0,0,120,118,1,0,0,0,121,122,5,7,0,0,122,11,1,
  	0,0,0,123,126,5,37,0,0,124,125,5,8,0,0,125,127,3,60,30,0,126,124,1,0,
  	0,0,126,127,1,0,0,0,127,137,1,0,0,0,128,129,5,37,0,0,129,130,5,9,0,0,
  	130,131,5,38,0,0,131,134,5,10,0,0,132,133,5,8,0,0,133,135,3,58,29,0,134,
  	132,1,0,0,0,134,135,1,0,0,0,135,137,1,0,0,0,136,123,1,0,0,0,136,128,1,
  	0,0,0,137,13,1,0,0,0,138,139,3,16,8,0,139,140,5,37,0,0,140,142,5,11,0,
  	0,141,143,3,18,9,0,142,141,1,0,0,0,142,143,1,0,0,0,143,144,1,0,0,0,144,
  	145,5,12,0,0,145,146,3,22,11,0,146,15,1,0,0,0,147,148,7,1,0,0,148,17,
  	1,0,0,0,149,154,3,20,10,0,150,151,5,6,0,0,151,153,3,20,10,0,152,150,1,
  	0,0,0,153,156,1,0,0,0,154,152,1,0,0,0,154,155,1,0,0,0,155,19,1,0,0,0,
  	156,154,1,0,0,0,157,158,3,2,1,0,158,160,5,37,0,0,159,161,5,41,0,0,160,
  	159,1,0,0,0,160,161,1,0,0,0,161,21,1,0,0,0,162,166,5,14,0,0,163,165,3,
  	24,12,0,164,163,1,0,0,0,165,168,1,0,0,0,166,164,1,0,0,0,166,167,1,0,0,
  	0,167,169,1,0,0,0,168,166,1,0,0,0,169,170,5,15,0,0,170,23,1,0,0,0,171,
  	174,3,4,2,0,172,174,3,26,13,0,173,171,1,0,0,0,173,172,1,0,0,0,174,25,
  	1,0,0,0,175,176,3,66,33,0,176,177,5,8,0,0,177,178,3,28,14,0,178,179,5,
  	7,0,0,179,215,1,0,0,0,180,182,3,28,14,0,181,180,1,0,0,0,181,182,1,0,0,
  	0,182,183,1,0,0,0,183,215,5,7,0,0,184,215,3,22,11,0,185,186,5,16,0,0,
  	186,187,5,11,0,0,187,188,3,30,15,0,188,189,5,12,0,0,189,190,3,26,13,0,
  	190,215,1,0,0,0,191,192,5,16,0,0,192,193,5,11,0,0,193,194,3,30,15,0,194,
  	195,5,12,0,0,195,196,3,26,13,0,196,197,5,17,0,0,197,198,3,26,13,0,198,
  	215,1,0,0,0,199,200,5,18,0,0,200,201,5,11,0,0,201,202,3,30,15,0,202,203,
  	5,12,0,0,203,204,3,26,13,0,204,215,1,0,0,0,205,206,5,19,0,0,206,215,5,
  	7,0,0,207,208,5,20,0,0,208,215,5,7,0,0,209,211,5,21,0,0,210,212,3,28,
  	14,0,211,210,1,0,0,0,211,212,1,0,0,0,212,213,1,0,0,0,213,215,5,7,0,0,
  	214,175,1,0,0,0,214,181,1,0,0,0,214,184,1,0,0,0,214,185,1,0,0,0,214,191,
  	1,0,0,0,214,199,1,0,0,0,214,205,1,0,0,0,214,207,1,0,0,0,214,209,1,0,0,
  	0,215,27,1,0,0,0,216,219,3,42,21,0,217,219,3,64,32,0,218,216,1,0,0,0,
  	218,217,1,0,0,0,219,29,1,0,0,0,220,221,3,56,28,0,221,31,1,0,0,0,222,223,
  	5,11,0,0,223,224,3,28,14,0,224,225,5,12,0,0,225,229,1,0,0,0,226,229,3,
  	68,34,0,227,229,3,62,31,0,228,222,1,0,0,0,228,226,1,0,0,0,228,227,1,0,
  	0,0,229,33,1,0,0,0,230,236,3,32,16,0,231,236,3,70,35,0,232,233,3,36,18,
  	0,233,234,3,34,17,0,234,236,1,0,0,0,235,230,1,0,0,0,235,231,1,0,0,0,235,
  	232,1,0,0,0,236,35,1,0,0,0,237,238,7,2,0,0,238,37,1,0,0,0,239,240,6,19,
  	-1,0,240,241,3,34,17,0,241,248,1,0,0,0,242,243,10,1,0,0,243,244,3,40,
  	20,0,244,245,3,34,17,0,245,247,1,0,0,0,246,242,1,0,0,0,247,250,1,0,0,
  	0,248,246,1,0,0,0,248,249,1,0,0,0,249,39,1,0,0,0,250,248,1,0,0,0,251,
  	252,7,3,0,0,252,41,1,0,0,0,253,254,6,21,-1,0,254,255,3,38,19,0,255,262,
  	1,0,0,0,256,257,10,1,0,0,257,258,3,44,22,0,258,259,3,38,19,0,259,261,
  	1,0,0,0,260,256,1,0,0,0,261,264,1,0,0,0,262,260,1,0,0,0,262,263,1,0,0,
  	0,263,43,1,0,0,0,264,262,1,0,0,0,265,266,7,4,0,0,266,45,1,0,0,0,267,268,
  	6,23,-1,0,268,271,3,42,21,0,269,271,3,64,32,0,270,267,1,0,0,0,270,269,
  	1,0,0,0,271,278,1,0,0,0,272,273,10,2,0,0,273,274,3,48,24,0,274,275,3,
  	42,21,0,275,277,1,0,0,0,276,272,1,0,0,0,277,280,1,0,0,0,278,276,1,0,0,
  	0,278,279,1,0,0,0,279,47,1,0,0,0,280,278,1,0,0,0,281,282,7,5,0,0,282,
  	49,1,0,0,0,283,284,6,25,-1,0,284,285,3,46,23,0,285,292,1,0,0,0,286,287,
  	10,1,0,0,287,288,3,52,26,0,288,289,3,46,23,0,289,291,1,0,0,0,290,286,
  	1,0,0,0,291,294,1,0,0,0,292,290,1,0,0,0,292,293,1,0,0,0,293,51,1,0,0,
  	0,294,292,1,0,0,0,295,296,7,6,0,0,296,53,1,0,0,0,297,298,6,27,-1,0,298,
  	299,3,50,25,0,299,305,1,0,0,0,300,301,10,1,0,0,301,302,5,34,0,0,302,304,
  	3,50,25,0,303,300,1,0,0,0,304,307,1,0,0,0,305,303,1,0,0,0,305,306,1,0,
  	0,0,306,55,1,0,0,0,307,305,1,0,0,0,308,309,6,28,-1,0,309,310,3,54,27,
  	0,310,316,1,0,0,0,311,312,10,1,0,0,312,313,5,35,0,0,313,315,3,54,27,0,
  	314,311,1,0,0,0,315,318,1,0,0,0,316,314,1,0,0,0,316,317,1,0,0,0,317,57,
  	1,0,0,0,318,316,1,0,0,0,319,328,5,14,0,0,320,325,3,60,30,0,321,322,5,
  	6,0,0,322,324,3,60,30,0,323,321,1,0,0,0,324,327,1,0,0,0,325,323,1,0,0,
  	0,325,326,1,0,0,0,326,329,1,0,0,0,327,325,1,0,0,0,328,320,1,0,0,0,328,
  	329,1,0,0,0,329,330,1,0,0,0,330,331,5,15,0,0,331,59,1,0,0,0,332,335,3,
  	62,31,0,333,335,3,64,32,0,334,332,1,0,0,0,334,333,1,0,0,0,335,61,1,0,
  	0,0,336,340,5,38,0,0,337,340,5,40,0,0,338,340,5,39,0,0,339,336,1,0,0,
  	0,339,337,1,0,0,0,339,338,1,0,0,0,340,63,1,0,0,0,341,342,5,36,0,0,342,
  	65,1,0,0,0,343,350,5,37,0,0,344,345,5,37,0,0,345,346,5,9,0,0,346,347,
  	3,28,14,0,347,348,5,10,0,0,348,350,1,0,0,0,349,343,1,0,0,0,349,344,1,
  	0,0,0,350,67,1,0,0,0,351,358,5,37,0,0,352,353,5,37,0,0,353,354,5,9,0,
  	0,354,355,3,28,14,0,355,356,5,10,0,0,356,358,1,0,0,0,357,351,1,0,0,0,
  	357,352,1,0,0,0,358,69,1,0,0,0,359,360,5,37,0,0,360,362,5,11,0,0,361,
  	363,3,72,36,0,362,361,1,0,0,0,362,363,1,0,0,0,363,364,1,0,0,0,364,365,
  	5,12,0,0,365,71,1,0,0,0,366,371,3,28,14,0,367,368,5,6,0,0,368,370,3,28,
  	14,0,369,367,1,0,0,0,370,373,1,0,0,0,371,369,1,0,0,0,371,372,1,0,0,0,
  	372,73,1,0,0,0,373,371,1,0,0,0,35,76,78,87,96,110,118,126,134,136,142,
  	154,160,166,173,181,211,214,218,228,235,248,262,270,278,292,305,316,325,
  	328,334,339,349,357,362,371
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  cactParserStaticData = staticData.release();
}

}

CACTParser::CACTParser(TokenStream *input) : CACTParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CACTParser::CACTParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CACTParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *cactParserStaticData->atn, cactParserStaticData->decisionToDFA, cactParserStaticData->sharedContextCache, options);
}

CACTParser::~CACTParser() {
  delete _interpreter;
}

const atn::ATN& CACTParser::getATN() const {
  return *cactParserStaticData->atn;
}

std::string CACTParser::getGrammarFileName() const {
  return "CACT.g4";
}

const std::vector<std::string>& CACTParser::getRuleNames() const {
  return cactParserStaticData->ruleNames;
}

const dfa::Vocabulary& CACTParser::getVocabulary() const {
  return cactParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CACTParser::getSerializedATN() const {
  return cactParserStaticData->serializedATN;
}


//----------------- CompUnitContext ------------------------------------------------------------------

CACTParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::CompUnitContext::EOF() {
  return getToken(CACTParser::EOF, 0);
}

std::vector<CACTParser::DeclContext *> CACTParser::CompUnitContext::decl() {
  return getRuleContexts<CACTParser::DeclContext>();
}

CACTParser::DeclContext* CACTParser::CompUnitContext::decl(size_t i) {
  return getRuleContext<CACTParser::DeclContext>(i);
}

std::vector<CACTParser::FuncDefContext *> CACTParser::CompUnitContext::funcDef() {
  return getRuleContexts<CACTParser::FuncDefContext>();
}

CACTParser::FuncDefContext* CACTParser::CompUnitContext::funcDef(size_t i) {
  return getRuleContext<CACTParser::FuncDefContext>(i);
}


size_t CACTParser::CompUnitContext::getRuleIndex() const {
  return CACTParser::RuleCompUnit;
}

void CACTParser::CompUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompUnit(this);
}

void CACTParser::CompUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompUnit(this);
}

CACTParser::CompUnitContext* CACTParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, CACTParser::RuleCompUnit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8254) != 0)) {
      setState(76);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(74);
        decl();
        break;
      }

      case 2: {
        setState(75);
        funcDef();
        break;
      }

      default:
        break;
      }
      setState(80);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(81);
    match(CACTParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

CACTParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::BTypeContext::getRuleIndex() const {
  return CACTParser::RuleBType;
}

void CACTParser::BTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBType(this);
}

void CACTParser::BTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBType(this);
}

CACTParser::BTypeContext* CACTParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 2, CACTParser::RuleBType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 30) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

CACTParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::ConstDeclContext* CACTParser::DeclContext::constDecl() {
  return getRuleContext<CACTParser::ConstDeclContext>(0);
}

CACTParser::VarDeclContext* CACTParser::DeclContext::varDecl() {
  return getRuleContext<CACTParser::VarDeclContext>(0);
}


size_t CACTParser::DeclContext::getRuleIndex() const {
  return CACTParser::RuleDecl;
}

void CACTParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void CACTParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}

CACTParser::DeclContext* CACTParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 4, CACTParser::RuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(87);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(85);
        constDecl();
        break;
      }

      case CACTParser::T__0:
      case CACTParser::T__1:
      case CACTParser::T__2:
      case CACTParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(86);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

CACTParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::ConstDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::ConstDefContext *> CACTParser::ConstDeclContext::constDef() {
  return getRuleContexts<CACTParser::ConstDefContext>();
}

CACTParser::ConstDefContext* CACTParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<CACTParser::ConstDefContext>(i);
}


size_t CACTParser::ConstDeclContext::getRuleIndex() const {
  return CACTParser::RuleConstDecl;
}

void CACTParser::ConstDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDecl(this);
}

void CACTParser::ConstDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDecl(this);
}

CACTParser::ConstDeclContext* CACTParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, CACTParser::RuleConstDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    match(CACTParser::T__4);
    setState(90);
    bType();
    setState(91);
    constDef();
    setState(96);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__5) {
      setState(92);
      match(CACTParser::T__5);
      setState(93);
      constDef();
      setState(98);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(99);
    match(CACTParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

CACTParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstDefContext::getRuleIndex() const {
  return CACTParser::RuleConstDef;
}

void CACTParser::ConstDefContext::copyFrom(ConstDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->thisSymbolInfo = ctx->thisSymbolInfo;
}

//----------------- ConstDefArrayContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ConstDefArrayContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::ConstDefArrayContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

CACTParser::ConstArrExpContext* CACTParser::ConstDefArrayContext::constArrExp() {
  return getRuleContext<CACTParser::ConstArrExpContext>(0);
}

CACTParser::ConstDefArrayContext::ConstDefArrayContext(ConstDefContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstDefArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDefArray(this);
}
void CACTParser::ConstDefArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDefArray(this);
}
//----------------- ConstDefBasicContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ConstDefBasicContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ConstExpContext* CACTParser::ConstDefBasicContext::constExp() {
  return getRuleContext<CACTParser::ConstExpContext>(0);
}

CACTParser::ConstDefBasicContext::ConstDefBasicContext(ConstDefContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstDefBasicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDefBasic(this);
}
void CACTParser::ConstDefBasicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDefBasic(this);
}
CACTParser::ConstDefContext* CACTParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 8, CACTParser::RuleConstDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(110);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CACTParser::ConstDefBasicContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(101);
      match(CACTParser::Ident);
      setState(102);
      match(CACTParser::T__7);
      setState(103);
      constExp();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CACTParser::ConstDefArrayContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(104);
      match(CACTParser::Ident);
      setState(105);
      match(CACTParser::T__8);
      setState(106);
      match(CACTParser::IntConst);
      setState(107);
      match(CACTParser::T__9);
      setState(108);
      match(CACTParser::T__7);
      setState(109);
      constArrExp();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

CACTParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::VarDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::VarDefContext *> CACTParser::VarDeclContext::varDef() {
  return getRuleContexts<CACTParser::VarDefContext>();
}

CACTParser::VarDefContext* CACTParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<CACTParser::VarDefContext>(i);
}


size_t CACTParser::VarDeclContext::getRuleIndex() const {
  return CACTParser::RuleVarDecl;
}

void CACTParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void CACTParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}

CACTParser::VarDeclContext* CACTParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 10, CACTParser::RuleVarDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    bType();
    setState(113);
    varDef();
    setState(118);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__5) {
      setState(114);
      match(CACTParser::T__5);
      setState(115);
      varDef();
      setState(120);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(121);
    match(CACTParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

CACTParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::VarDefContext::getRuleIndex() const {
  return CACTParser::RuleVarDef;
}

void CACTParser::VarDefContext::copyFrom(VarDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->thisSymbolInfo = ctx->thisSymbolInfo;
}

//----------------- VarDefBasicContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::VarDefBasicContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ConstExpContext* CACTParser::VarDefBasicContext::constExp() {
  return getRuleContext<CACTParser::ConstExpContext>(0);
}

CACTParser::VarDefBasicContext::VarDefBasicContext(VarDefContext *ctx) { copyFrom(ctx); }

void CACTParser::VarDefBasicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDefBasic(this);
}
void CACTParser::VarDefBasicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDefBasic(this);
}
//----------------- VarDefArrayContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::VarDefArrayContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::VarDefArrayContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

CACTParser::ConstArrExpContext* CACTParser::VarDefArrayContext::constArrExp() {
  return getRuleContext<CACTParser::ConstArrExpContext>(0);
}

CACTParser::VarDefArrayContext::VarDefArrayContext(VarDefContext *ctx) { copyFrom(ctx); }

void CACTParser::VarDefArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDefArray(this);
}
void CACTParser::VarDefArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDefArray(this);
}
CACTParser::VarDefContext* CACTParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 12, CACTParser::RuleVarDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(136);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CACTParser::VarDefBasicContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(123);
      match(CACTParser::Ident);
      setState(126);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CACTParser::T__7) {
        setState(124);
        match(CACTParser::T__7);
        setState(125);
        constExp();
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CACTParser::VarDefArrayContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(128);
      match(CACTParser::Ident);
      setState(129);
      match(CACTParser::T__8);
      setState(130);
      match(CACTParser::IntConst);
      setState(131);
      match(CACTParser::T__9);
      setState(134);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CACTParser::T__7) {
        setState(132);
        match(CACTParser::T__7);
        setState(133);
        constArrExp();
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

CACTParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::FuncTypeContext* CACTParser::FuncDefContext::funcType() {
  return getRuleContext<CACTParser::FuncTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncDefContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::BlockContext* CACTParser::FuncDefContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::FuncFParamsContext* CACTParser::FuncDefContext::funcFParams() {
  return getRuleContext<CACTParser::FuncFParamsContext>(0);
}


size_t CACTParser::FuncDefContext::getRuleIndex() const {
  return CACTParser::RuleFuncDef;
}

void CACTParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void CACTParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
}

CACTParser::FuncDefContext* CACTParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 14, CACTParser::RuleFuncDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    funcType();
    setState(139);
    match(CACTParser::Ident);
    setState(140);
    match(CACTParser::T__10);
    setState(142);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 30) != 0)) {
      setState(141);
      funcFParams();
    }
    setState(144);
    match(CACTParser::T__11);
    setState(145);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

CACTParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::FuncTypeContext::getRuleIndex() const {
  return CACTParser::RuleFuncType;
}

void CACTParser::FuncTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncType(this);
}

void CACTParser::FuncTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncType(this);
}

CACTParser::FuncTypeContext* CACTParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 16, CACTParser::RuleFuncType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8222) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamsContext ------------------------------------------------------------------

CACTParser::FuncFParamsContext::FuncFParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::FuncFParamContext *> CACTParser::FuncFParamsContext::funcFParam() {
  return getRuleContexts<CACTParser::FuncFParamContext>();
}

CACTParser::FuncFParamContext* CACTParser::FuncFParamsContext::funcFParam(size_t i) {
  return getRuleContext<CACTParser::FuncFParamContext>(i);
}


size_t CACTParser::FuncFParamsContext::getRuleIndex() const {
  return CACTParser::RuleFuncFParams;
}

void CACTParser::FuncFParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParams(this);
}

void CACTParser::FuncFParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParams(this);
}

CACTParser::FuncFParamsContext* CACTParser::funcFParams() {
  FuncFParamsContext *_localctx = _tracker.createInstance<FuncFParamsContext>(_ctx, getState());
  enterRule(_localctx, 18, CACTParser::RuleFuncFParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    funcFParam();
    setState(154);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__5) {
      setState(150);
      match(CACTParser::T__5);
      setState(151);
      funcFParam();
      setState(156);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamContext ------------------------------------------------------------------

CACTParser::FuncFParamContext::FuncFParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::FuncFParamContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncFParamContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::FuncFParamContext::ArraySymbol() {
  return getToken(CACTParser::ArraySymbol, 0);
}


size_t CACTParser::FuncFParamContext::getRuleIndex() const {
  return CACTParser::RuleFuncFParam;
}

void CACTParser::FuncFParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParam(this);
}

void CACTParser::FuncFParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParam(this);
}

CACTParser::FuncFParamContext* CACTParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 20, CACTParser::RuleFuncFParam);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    bType();
    setState(158);
    match(CACTParser::Ident);
    setState(160);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::ArraySymbol) {
      setState(159);
      match(CACTParser::ArraySymbol);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

CACTParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::BlockItemContext *> CACTParser::BlockContext::blockItem() {
  return getRuleContexts<CACTParser::BlockItemContext>();
}

CACTParser::BlockItemContext* CACTParser::BlockContext::blockItem(size_t i) {
  return getRuleContext<CACTParser::BlockItemContext>(i);
}


size_t CACTParser::BlockContext::getRuleIndex() const {
  return CACTParser::RuleBlock;
}

void CACTParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void CACTParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

CACTParser::BlockContext* CACTParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 22, CACTParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    match(CACTParser::T__13);
    setState(166);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2130337155262) != 0)) {
      setState(163);
      blockItem();
      setState(168);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(169);
    match(CACTParser::T__14);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

CACTParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::DeclContext* CACTParser::BlockItemContext::decl() {
  return getRuleContext<CACTParser::DeclContext>(0);
}

CACTParser::StmtContext* CACTParser::BlockItemContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}


size_t CACTParser::BlockItemContext::getRuleIndex() const {
  return CACTParser::RuleBlockItem;
}

void CACTParser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void CACTParser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
}

CACTParser::BlockItemContext* CACTParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 24, CACTParser::RuleBlockItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(173);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0:
      case CACTParser::T__1:
      case CACTParser::T__2:
      case CACTParser::T__3:
      case CACTParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(171);
        decl();
        break;
      }

      case CACTParser::T__6:
      case CACTParser::T__10:
      case CACTParser::T__13:
      case CACTParser::T__15:
      case CACTParser::T__17:
      case CACTParser::T__18:
      case CACTParser::T__19:
      case CACTParser::T__20:
      case CACTParser::T__21:
      case CACTParser::T__22:
      case CACTParser::T__23:
      case CACTParser::BoolConst:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        enterOuterAlt(_localctx, 2);
        setState(172);
        stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

CACTParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::StmtContext::getRuleIndex() const {
  return CACTParser::RuleStmt;
}

void CACTParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->flowNext = ctx->flowNext;
  this->flowEnd = ctx->flowEnd;
  this->codeBefore = ctx->codeBefore;
}

//----------------- StmtCtrlBreakContext ------------------------------------------------------------------

CACTParser::StmtCtrlBreakContext::StmtCtrlBreakContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtCtrlBreakContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtCtrlBreak(this);
}
void CACTParser::StmtCtrlBreakContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtCtrlBreak(this);
}
//----------------- StmtExpContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::StmtExpContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::StmtExpContext::StmtExpContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtExp(this);
}
void CACTParser::StmtExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtExp(this);
}
//----------------- StmtBlockContext ------------------------------------------------------------------

CACTParser::BlockContext* CACTParser::StmtBlockContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::StmtBlockContext::StmtBlockContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtBlock(this);
}
void CACTParser::StmtBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtBlock(this);
}
//----------------- StmtCtrlContinueContext ------------------------------------------------------------------

CACTParser::StmtCtrlContinueContext::StmtCtrlContinueContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtCtrlContinueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtCtrlContinue(this);
}
void CACTParser::StmtCtrlContinueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtCtrlContinue(this);
}
//----------------- StmtCtrlWhileContext ------------------------------------------------------------------

CACTParser::CondContext* CACTParser::StmtCtrlWhileContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}

CACTParser::StmtContext* CACTParser::StmtCtrlWhileContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::StmtCtrlWhileContext::StmtCtrlWhileContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtCtrlWhileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtCtrlWhile(this);
}
void CACTParser::StmtCtrlWhileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtCtrlWhile(this);
}
//----------------- StmtReturnContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::StmtReturnContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::StmtReturnContext::StmtReturnContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtReturn(this);
}
void CACTParser::StmtReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtReturn(this);
}
//----------------- StmtAssignContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::StmtAssignContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::ExpContext* CACTParser::StmtAssignContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::StmtAssignContext::StmtAssignContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtAssign(this);
}
void CACTParser::StmtAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtAssign(this);
}
//----------------- StmtCtrlIfContext ------------------------------------------------------------------

CACTParser::CondContext* CACTParser::StmtCtrlIfContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}

CACTParser::StmtContext* CACTParser::StmtCtrlIfContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::StmtCtrlIfContext::StmtCtrlIfContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtCtrlIfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtCtrlIf(this);
}
void CACTParser::StmtCtrlIfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtCtrlIf(this);
}
//----------------- StmtCtrlIfElseContext ------------------------------------------------------------------

CACTParser::CondContext* CACTParser::StmtCtrlIfElseContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}

std::vector<CACTParser::StmtContext *> CACTParser::StmtCtrlIfElseContext::stmt() {
  return getRuleContexts<CACTParser::StmtContext>();
}

CACTParser::StmtContext* CACTParser::StmtCtrlIfElseContext::stmt(size_t i) {
  return getRuleContext<CACTParser::StmtContext>(i);
}

CACTParser::StmtCtrlIfElseContext::StmtCtrlIfElseContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::StmtCtrlIfElseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtCtrlIfElse(this);
}
void CACTParser::StmtCtrlIfElseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtCtrlIfElse(this);
}
CACTParser::StmtContext* CACTParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 26, CACTParser::RuleStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(214);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CACTParser::StmtAssignContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(175);
      lVal();
      setState(176);
      match(CACTParser::T__7);
      setState(177);
      exp();
      setState(178);
      match(CACTParser::T__6);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CACTParser::StmtExpContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(181);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2130333140992) != 0)) {
        setState(180);
        exp();
      }
      setState(183);
      match(CACTParser::T__6);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CACTParser::StmtBlockContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(184);
      block();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CACTParser::StmtCtrlIfContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(185);
      match(CACTParser::T__15);
      setState(186);
      match(CACTParser::T__10);
      setState(187);
      cond();
      setState(188);
      match(CACTParser::T__11);
      setState(189);
      stmt();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CACTParser::StmtCtrlIfElseContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(191);
      match(CACTParser::T__15);
      setState(192);
      match(CACTParser::T__10);
      setState(193);
      cond();
      setState(194);
      match(CACTParser::T__11);
      setState(195);
      stmt();
      setState(196);
      match(CACTParser::T__16);
      setState(197);
      stmt();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CACTParser::StmtCtrlWhileContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(199);
      match(CACTParser::T__17);
      setState(200);
      match(CACTParser::T__10);
      setState(201);
      cond();
      setState(202);
      match(CACTParser::T__11);
      setState(203);
      stmt();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<CACTParser::StmtCtrlBreakContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(205);
      match(CACTParser::T__18);
      setState(206);
      match(CACTParser::T__6);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<CACTParser::StmtCtrlContinueContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(207);
      match(CACTParser::T__19);
      setState(208);
      match(CACTParser::T__6);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<CACTParser::StmtReturnContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(209);
      match(CACTParser::T__20);
      setState(211);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2130333140992) != 0)) {
        setState(210);
        exp();
      }
      setState(213);
      match(CACTParser::T__6);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

CACTParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ExpContext::getRuleIndex() const {
  return CACTParser::RuleExp;
}

void CACTParser::ExpContext::copyFrom(ExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- ExpAddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::ExpAddExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::ExpAddExpContext::ExpAddExpContext(ExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ExpAddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpAddExp(this);
}
void CACTParser::ExpAddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpAddExp(this);
}
//----------------- ExpBoolConstContext ------------------------------------------------------------------

CACTParser::BoolValContext* CACTParser::ExpBoolConstContext::boolVal() {
  return getRuleContext<CACTParser::BoolValContext>(0);
}

CACTParser::ExpBoolConstContext::ExpBoolConstContext(ExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ExpBoolConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpBoolConst(this);
}
void CACTParser::ExpBoolConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpBoolConst(this);
}
CACTParser::ExpContext* CACTParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 28, CACTParser::RuleExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(218);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__10:
      case CACTParser::T__21:
      case CACTParser::T__22:
      case CACTParser::T__23:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = _tracker.createInstance<CACTParser::ExpAddExpContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(216);
        addExp(0);
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = _tracker.createInstance<CACTParser::ExpBoolConstContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(217);
        boolVal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

CACTParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::LOrExpContext* CACTParser::CondContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}


size_t CACTParser::CondContext::getRuleIndex() const {
  return CACTParser::RuleCond;
}

void CACTParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void CACTParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}

CACTParser::CondContext* CACTParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 30, CACTParser::RuleCond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    lOrExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExpContext ------------------------------------------------------------------

CACTParser::PrimaryExpContext::PrimaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::PrimaryExpContext::getRuleIndex() const {
  return CACTParser::RulePrimaryExp;
}

void CACTParser::PrimaryExpContext::copyFrom(PrimaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- PrimaryExpExpContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::PrimaryExpExpContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::PrimaryExpExpContext::PrimaryExpExpContext(PrimaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::PrimaryExpExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpExp(this);
}
void CACTParser::PrimaryExpExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpExp(this);
}
//----------------- PrimaryExpRValContext ------------------------------------------------------------------

CACTParser::RValContext* CACTParser::PrimaryExpRValContext::rVal() {
  return getRuleContext<CACTParser::RValContext>(0);
}

CACTParser::PrimaryExpRValContext::PrimaryExpRValContext(PrimaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::PrimaryExpRValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpRVal(this);
}
void CACTParser::PrimaryExpRValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpRVal(this);
}
//----------------- PrimaryNumValContext ------------------------------------------------------------------

CACTParser::NumValContext* CACTParser::PrimaryNumValContext::numVal() {
  return getRuleContext<CACTParser::NumValContext>(0);
}

CACTParser::PrimaryNumValContext::PrimaryNumValContext(PrimaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::PrimaryNumValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryNumVal(this);
}
void CACTParser::PrimaryNumValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryNumVal(this);
}
CACTParser::PrimaryExpContext* CACTParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 32, CACTParser::RulePrimaryExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(228);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__10: {
        _localctx = _tracker.createInstance<CACTParser::PrimaryExpExpContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(222);
        match(CACTParser::T__10);
        setState(223);
        exp();
        setState(224);
        match(CACTParser::T__11);
        break;
      }

      case CACTParser::Ident: {
        _localctx = _tracker.createInstance<CACTParser::PrimaryExpRValContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(226);
        rVal();
        break;
      }

      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = _tracker.createInstance<CACTParser::PrimaryNumValContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(227);
        numVal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExpContext ------------------------------------------------------------------

CACTParser::UnaryExpContext::UnaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::UnaryExpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryExp;
}

void CACTParser::UnaryExpContext::copyFrom(UnaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- UnaryExpFuncContext ------------------------------------------------------------------

CACTParser::FuncValContext* CACTParser::UnaryExpFuncContext::funcVal() {
  return getRuleContext<CACTParser::FuncValContext>(0);
}

CACTParser::UnaryExpFuncContext::UnaryExpFuncContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::UnaryExpFuncContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpFunc(this);
}
void CACTParser::UnaryExpFuncContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpFunc(this);
}
//----------------- UnaryExpUnaryOpContext ------------------------------------------------------------------

CACTParser::UnaryOpContext* CACTParser::UnaryExpUnaryOpContext::unaryOp() {
  return getRuleContext<CACTParser::UnaryOpContext>(0);
}

CACTParser::UnaryExpContext* CACTParser::UnaryExpUnaryOpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::UnaryExpUnaryOpContext::UnaryExpUnaryOpContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::UnaryExpUnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpUnaryOp(this);
}
void CACTParser::UnaryExpUnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpUnaryOp(this);
}
//----------------- UnaryExpPrimaryExpContext ------------------------------------------------------------------

CACTParser::PrimaryExpContext* CACTParser::UnaryExpPrimaryExpContext::primaryExp() {
  return getRuleContext<CACTParser::PrimaryExpContext>(0);
}

CACTParser::UnaryExpPrimaryExpContext::UnaryExpPrimaryExpContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::UnaryExpPrimaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpPrimaryExp(this);
}
void CACTParser::UnaryExpPrimaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpPrimaryExp(this);
}
CACTParser::UnaryExpContext* CACTParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 34, CACTParser::RuleUnaryExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(235);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CACTParser::UnaryExpPrimaryExpContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(230);
      primaryExp();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CACTParser::UnaryExpFuncContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(231);
      funcVal();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CACTParser::UnaryExpUnaryOpContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(232);
      unaryOp();
      setState(233);
      unaryExp();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOpContext ------------------------------------------------------------------

CACTParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::UnaryOpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryOp;
}

void CACTParser::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}

void CACTParser::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}

CACTParser::UnaryOpContext* CACTParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 36, CACTParser::RuleUnaryOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 29360128) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext::MulExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::MulExpContext::getRuleIndex() const {
  return CACTParser::RuleMulExp;
}

void CACTParser::MulExpContext::copyFrom(MulExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- MulExpMulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext* CACTParser::MulExpMulExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::MulOpContext* CACTParser::MulExpMulExpContext::mulOp() {
  return getRuleContext<CACTParser::MulOpContext>(0);
}

CACTParser::UnaryExpContext* CACTParser::MulExpMulExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::MulExpMulExpContext::MulExpMulExpContext(MulExpContext *ctx) { copyFrom(ctx); }

void CACTParser::MulExpMulExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExpMulExp(this);
}
void CACTParser::MulExpMulExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExpMulExp(this);
}
//----------------- MulExpUnaryExpContext ------------------------------------------------------------------

CACTParser::UnaryExpContext* CACTParser::MulExpUnaryExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::MulExpUnaryExpContext::MulExpUnaryExpContext(MulExpContext *ctx) { copyFrom(ctx); }

void CACTParser::MulExpUnaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExpUnaryExp(this);
}
void CACTParser::MulExpUnaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExpUnaryExp(this);
}

CACTParser::MulExpContext* CACTParser::mulExp() {
   return mulExp(0);
}

CACTParser::MulExpContext* CACTParser::mulExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, parentState);
  CACTParser::MulExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, CACTParser::RuleMulExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<MulExpUnaryExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(240);
    unaryExp();
    _ctx->stop = _input->LT(-1);
    setState(248);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MulExpMulExpContext>(_tracker.createInstance<MulExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleMulExp);
        setState(242);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(243);
        mulOp();
        setState(244);
        unaryExp(); 
      }
      setState(250);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MulOpContext ------------------------------------------------------------------

CACTParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::MulOpContext::getRuleIndex() const {
  return CACTParser::RuleMulOp;
}

void CACTParser::MulOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulOp(this);
}

void CACTParser::MulOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulOp(this);
}

CACTParser::MulOpContext* CACTParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 40, CACTParser::RuleMulOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 234881024) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::AddExpContext::getRuleIndex() const {
  return CACTParser::RuleAddExp;
}

void CACTParser::AddExpContext::copyFrom(AddExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- AddExpAddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::AddExpAddExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::AddOpContext* CACTParser::AddExpAddExpContext::addOp() {
  return getRuleContext<CACTParser::AddOpContext>(0);
}

CACTParser::MulExpContext* CACTParser::AddExpAddExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::AddExpAddExpContext::AddExpAddExpContext(AddExpContext *ctx) { copyFrom(ctx); }

void CACTParser::AddExpAddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExpAddExp(this);
}
void CACTParser::AddExpAddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExpAddExp(this);
}
//----------------- AddExpMulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext* CACTParser::AddExpMulExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::AddExpMulExpContext::AddExpMulExpContext(AddExpContext *ctx) { copyFrom(ctx); }

void CACTParser::AddExpMulExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExpMulExp(this);
}
void CACTParser::AddExpMulExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExpMulExp(this);
}

CACTParser::AddExpContext* CACTParser::addExp() {
   return addExp(0);
}

CACTParser::AddExpContext* CACTParser::addExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, parentState);
  CACTParser::AddExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 42;
  enterRecursionRule(_localctx, 42, CACTParser::RuleAddExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<AddExpMulExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(254);
    mulExp(0);
    _ctx->stop = _input->LT(-1);
    setState(262);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<AddExpAddExpContext>(_tracker.createInstance<AddExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleAddExp);
        setState(256);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(257);
        addOp();
        setState(258);
        mulExp(0); 
      }
      setState(264);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AddOpContext ------------------------------------------------------------------

CACTParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::AddOpContext::getRuleIndex() const {
  return CACTParser::RuleAddOp;
}

void CACTParser::AddOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddOp(this);
}

void CACTParser::AddOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddOp(this);
}

CACTParser::AddOpContext* CACTParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 44, CACTParser::RuleAddOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
    _la = _input->LA(1);
    if (!(_la == CACTParser::T__21

    || _la == CACTParser::T__22)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::RelExpContext::getRuleIndex() const {
  return CACTParser::RuleRelExp;
}

void CACTParser::RelExpContext::copyFrom(RelExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->flowTrue = ctx->flowTrue;
  this->flowFalse = ctx->flowFalse;
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- RelExpRelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext* CACTParser::RelExpRelExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::RelOpContext* CACTParser::RelExpRelExpContext::relOp() {
  return getRuleContext<CACTParser::RelOpContext>(0);
}

CACTParser::AddExpContext* CACTParser::RelExpRelExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::RelExpRelExpContext::RelExpRelExpContext(RelExpContext *ctx) { copyFrom(ctx); }

void CACTParser::RelExpRelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExpRelExp(this);
}
void CACTParser::RelExpRelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExpRelExp(this);
}
//----------------- RelExpBoolValContext ------------------------------------------------------------------

CACTParser::BoolValContext* CACTParser::RelExpBoolValContext::boolVal() {
  return getRuleContext<CACTParser::BoolValContext>(0);
}

CACTParser::RelExpBoolValContext::RelExpBoolValContext(RelExpContext *ctx) { copyFrom(ctx); }

void CACTParser::RelExpBoolValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExpBoolVal(this);
}
void CACTParser::RelExpBoolValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExpBoolVal(this);
}
//----------------- RelExpAddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext* CACTParser::RelExpAddExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

CACTParser::RelExpAddExpContext::RelExpAddExpContext(RelExpContext *ctx) { copyFrom(ctx); }

void CACTParser::RelExpAddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExpAddExp(this);
}
void CACTParser::RelExpAddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExpAddExp(this);
}

CACTParser::RelExpContext* CACTParser::relExp() {
   return relExp(0);
}

CACTParser::RelExpContext* CACTParser::relExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, parentState);
  CACTParser::RelExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, CACTParser::RuleRelExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(270);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__10:
      case CACTParser::T__21:
      case CACTParser::T__22:
      case CACTParser::T__23:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = _tracker.createInstance<RelExpAddExpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(268);
        addExp(0);
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = _tracker.createInstance<RelExpBoolValContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(269);
        boolVal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(278);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<RelExpRelExpContext>(_tracker.createInstance<RelExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleRelExp);
        setState(272);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(273);
        relOp();
        setState(274);
        addExp(0); 
      }
      setState(280);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelOpContext ------------------------------------------------------------------

CACTParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::RelOpContext::getRuleIndex() const {
  return CACTParser::RuleRelOp;
}

void CACTParser::RelOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelOp(this);
}

void CACTParser::RelOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelOp(this);
}

CACTParser::RelOpContext* CACTParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 48, CACTParser::RuleRelOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4026531840) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::EqExpContext::getRuleIndex() const {
  return CACTParser::RuleEqExp;
}

void CACTParser::EqExpContext::copyFrom(EqExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->codeBefore = ctx->codeBefore;
  this->flowTrue = ctx->flowTrue;
  this->flowFalse = ctx->flowFalse;
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- EqExpRelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext* CACTParser::EqExpRelExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::EqExpRelExpContext::EqExpRelExpContext(EqExpContext *ctx) { copyFrom(ctx); }

void CACTParser::EqExpRelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExpRelExp(this);
}
void CACTParser::EqExpRelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExpRelExp(this);
}
//----------------- EqExpEqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext* CACTParser::EqExpEqExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::EqOpContext* CACTParser::EqExpEqExpContext::eqOp() {
  return getRuleContext<CACTParser::EqOpContext>(0);
}

CACTParser::RelExpContext* CACTParser::EqExpEqExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::EqExpEqExpContext::EqExpEqExpContext(EqExpContext *ctx) { copyFrom(ctx); }

void CACTParser::EqExpEqExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExpEqExp(this);
}
void CACTParser::EqExpEqExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExpEqExp(this);
}

CACTParser::EqExpContext* CACTParser::eqExp() {
   return eqExp(0);
}

CACTParser::EqExpContext* CACTParser::eqExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, parentState);
  CACTParser::EqExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, CACTParser::RuleEqExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<EqExpRelExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(284);
    relExp(0);
    _ctx->stop = _input->LT(-1);
    setState(292);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<EqExpEqExpContext>(_tracker.createInstance<EqExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleEqExp);
        setState(286);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(287);
        eqOp();
        setState(288);
        relExp(0); 
      }
      setState(294);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqOpContext ------------------------------------------------------------------

CACTParser::EqOpContext::EqOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::EqOpContext::getRuleIndex() const {
  return CACTParser::RuleEqOp;
}

void CACTParser::EqOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqOp(this);
}

void CACTParser::EqOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqOp(this);
}

CACTParser::EqOpContext* CACTParser::eqOp() {
  EqOpContext *_localctx = _tracker.createInstance<EqOpContext>(_ctx, getState());
  enterRule(_localctx, 52, CACTParser::RuleEqOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(295);
    _la = _input->LA(1);
    if (!(_la == CACTParser::T__31

    || _la == CACTParser::T__32)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::LAndExpContext::getRuleIndex() const {
  return CACTParser::RuleLAndExp;
}

void CACTParser::LAndExpContext::copyFrom(LAndExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->codeBefore = ctx->codeBefore;
  this->label = ctx->label;
  this->flowTrue = ctx->flowTrue;
  this->flowFalse = ctx->flowFalse;
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- LAndExpLAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext* CACTParser::LAndExpLAndExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::EqExpContext* CACTParser::LAndExpLAndExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::LAndExpLAndExpContext::LAndExpLAndExpContext(LAndExpContext *ctx) { copyFrom(ctx); }

void CACTParser::LAndExpLAndExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLAndExpLAndExp(this);
}
void CACTParser::LAndExpLAndExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLAndExpLAndExp(this);
}
//----------------- LAndExpEqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext* CACTParser::LAndExpEqExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::LAndExpEqExpContext::LAndExpEqExpContext(LAndExpContext *ctx) { copyFrom(ctx); }

void CACTParser::LAndExpEqExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLAndExpEqExp(this);
}
void CACTParser::LAndExpEqExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLAndExpEqExp(this);
}

CACTParser::LAndExpContext* CACTParser::lAndExp() {
   return lAndExp(0);
}

CACTParser::LAndExpContext* CACTParser::lAndExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, parentState);
  CACTParser::LAndExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 54;
  enterRecursionRule(_localctx, 54, CACTParser::RuleLAndExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<LAndExpEqExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(298);
    eqExp(0);
    _ctx->stop = _input->LT(-1);
    setState(305);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<LAndExpLAndExpContext>(_tracker.createInstance<LAndExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleLAndExp);
        setState(300);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(301);
        match(CACTParser::T__33);
        setState(302);
        eqExp(0); 
      }
      setState(307);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LOrExpContext ------------------------------------------------------------------

CACTParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::LOrExpContext::getRuleIndex() const {
  return CACTParser::RuleLOrExp;
}

void CACTParser::LOrExpContext::copyFrom(LOrExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->flowTrue = ctx->flowTrue;
  this->flowFalse = ctx->flowFalse;
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- LOrExpLAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext* CACTParser::LOrExpLAndExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::LOrExpLAndExpContext::LOrExpLAndExpContext(LOrExpContext *ctx) { copyFrom(ctx); }

void CACTParser::LOrExpLAndExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLOrExpLAndExp(this);
}
void CACTParser::LOrExpLAndExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLOrExpLAndExp(this);
}
//----------------- LOrExpLOrExpContext ------------------------------------------------------------------

CACTParser::LOrExpContext* CACTParser::LOrExpLOrExpContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}

CACTParser::LAndExpContext* CACTParser::LOrExpLOrExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::LOrExpLOrExpContext::LOrExpLOrExpContext(LOrExpContext *ctx) { copyFrom(ctx); }

void CACTParser::LOrExpLOrExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLOrExpLOrExp(this);
}
void CACTParser::LOrExpLOrExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLOrExpLOrExp(this);
}

CACTParser::LOrExpContext* CACTParser::lOrExp() {
   return lOrExp(0);
}

CACTParser::LOrExpContext* CACTParser::lOrExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, parentState);
  CACTParser::LOrExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, CACTParser::RuleLOrExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<LOrExpLAndExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(309);
    lAndExp(0);
    _ctx->stop = _input->LT(-1);
    setState(316);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<LOrExpLOrExpContext>(_tracker.createInstance<LOrExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleLOrExp);
        setState(311);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(312);
        match(CACTParser::T__34);
        setState(313);
        lAndExp(0); 
      }
      setState(318);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstArrExpContext ------------------------------------------------------------------

CACTParser::ConstArrExpContext::ConstArrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::ConstExpContext *> CACTParser::ConstArrExpContext::constExp() {
  return getRuleContexts<CACTParser::ConstExpContext>();
}

CACTParser::ConstExpContext* CACTParser::ConstArrExpContext::constExp(size_t i) {
  return getRuleContext<CACTParser::ConstExpContext>(i);
}


size_t CACTParser::ConstArrExpContext::getRuleIndex() const {
  return CACTParser::RuleConstArrExp;
}

void CACTParser::ConstArrExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstArrExp(this);
}

void CACTParser::ConstArrExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstArrExp(this);
}

CACTParser::ConstArrExpContext* CACTParser::constArrExp() {
  ConstArrExpContext *_localctx = _tracker.createInstance<ConstArrExpContext>(_ctx, getState());
  enterRule(_localctx, 58, CACTParser::RuleConstArrExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    match(CACTParser::T__13);
    setState(328);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1992864825344) != 0)) {
      setState(320);
      constExp();
      setState(325);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CACTParser::T__5) {
        setState(321);
        match(CACTParser::T__5);
        setState(322);
        constExp();
        setState(327);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(330);
    match(CACTParser::T__14);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstExpContext ------------------------------------------------------------------

CACTParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstExpContext::getRuleIndex() const {
  return CACTParser::RuleConstExp;
}

void CACTParser::ConstExpContext::copyFrom(ConstExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- ConstExpNumValContext ------------------------------------------------------------------

CACTParser::NumValContext* CACTParser::ConstExpNumValContext::numVal() {
  return getRuleContext<CACTParser::NumValContext>(0);
}

CACTParser::ConstExpNumValContext::ConstExpNumValContext(ConstExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstExpNumValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExpNumVal(this);
}
void CACTParser::ConstExpNumValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExpNumVal(this);
}
//----------------- ConstExpBoolValContext ------------------------------------------------------------------

CACTParser::BoolValContext* CACTParser::ConstExpBoolValContext::boolVal() {
  return getRuleContext<CACTParser::BoolValContext>(0);
}

CACTParser::ConstExpBoolValContext::ConstExpBoolValContext(ConstExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstExpBoolValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExpBoolVal(this);
}
void CACTParser::ConstExpBoolValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExpBoolVal(this);
}
CACTParser::ConstExpContext* CACTParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 60, CACTParser::RuleConstExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(334);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::IntConst:
      case CACTParser::FloatConst:
      case CACTParser::DoubleConst: {
        _localctx = _tracker.createInstance<CACTParser::ConstExpNumValContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(332);
        numVal();
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = _tracker.createInstance<CACTParser::ConstExpBoolValContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(333);
        boolVal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumValContext ------------------------------------------------------------------

CACTParser::NumValContext::NumValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::NumValContext::getRuleIndex() const {
  return CACTParser::RuleNumVal;
}

void CACTParser::NumValContext::copyFrom(NumValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
}

//----------------- NumValDoubleConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::NumValDoubleConstContext::DoubleConst() {
  return getToken(CACTParser::DoubleConst, 0);
}

CACTParser::NumValDoubleConstContext::NumValDoubleConstContext(NumValContext *ctx) { copyFrom(ctx); }

void CACTParser::NumValDoubleConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumValDoubleConst(this);
}
void CACTParser::NumValDoubleConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumValDoubleConst(this);
}
//----------------- NumValIntConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::NumValIntConstContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

CACTParser::NumValIntConstContext::NumValIntConstContext(NumValContext *ctx) { copyFrom(ctx); }

void CACTParser::NumValIntConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumValIntConst(this);
}
void CACTParser::NumValIntConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumValIntConst(this);
}
//----------------- NumValFloatConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::NumValFloatConstContext::FloatConst() {
  return getToken(CACTParser::FloatConst, 0);
}

CACTParser::NumValFloatConstContext::NumValFloatConstContext(NumValContext *ctx) { copyFrom(ctx); }

void CACTParser::NumValFloatConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumValFloatConst(this);
}
void CACTParser::NumValFloatConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumValFloatConst(this);
}
CACTParser::NumValContext* CACTParser::numVal() {
  NumValContext *_localctx = _tracker.createInstance<NumValContext>(_ctx, getState());
  enterRule(_localctx, 62, CACTParser::RuleNumVal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(339);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::IntConst: {
        _localctx = _tracker.createInstance<CACTParser::NumValIntConstContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(336);
        match(CACTParser::IntConst);
        break;
      }

      case CACTParser::DoubleConst: {
        _localctx = _tracker.createInstance<CACTParser::NumValDoubleConstContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(337);
        match(CACTParser::DoubleConst);
        break;
      }

      case CACTParser::FloatConst: {
        _localctx = _tracker.createInstance<CACTParser::NumValFloatConstContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(338);
        match(CACTParser::FloatConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolValContext ------------------------------------------------------------------

CACTParser::BoolValContext::BoolValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::BoolValContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}


size_t CACTParser::BoolValContext::getRuleIndex() const {
  return CACTParser::RuleBoolVal;
}

void CACTParser::BoolValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolVal(this);
}

void CACTParser::BoolValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolVal(this);
}

CACTParser::BoolValContext* CACTParser::boolVal() {
  BoolValContext *_localctx = _tracker.createInstance<BoolValContext>(_ctx, getState());
  enterRule(_localctx, 64, CACTParser::RuleBoolVal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(341);
    match(CACTParser::BoolConst);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

CACTParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::LValContext::getRuleIndex() const {
  return CACTParser::RuleLVal;
}

void CACTParser::LValContext::copyFrom(LValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
  this->index = ctx->index;
  this->thisSymbol = ctx->thisSymbol;
}

//----------------- LValBasicContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::LValBasicContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::LValBasicContext::LValBasicContext(LValContext *ctx) { copyFrom(ctx); }

void CACTParser::LValBasicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLValBasic(this);
}
void CACTParser::LValBasicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLValBasic(this);
}
//----------------- LValIndexedContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::LValIndexedContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ExpContext* CACTParser::LValIndexedContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::LValIndexedContext::LValIndexedContext(LValContext *ctx) { copyFrom(ctx); }

void CACTParser::LValIndexedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLValIndexed(this);
}
void CACTParser::LValIndexedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLValIndexed(this);
}
CACTParser::LValContext* CACTParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 66, CACTParser::RuleLVal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(349);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CACTParser::LValBasicContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(343);
      match(CACTParser::Ident);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CACTParser::LValIndexedContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(344);
      match(CACTParser::Ident);
      setState(345);
      match(CACTParser::T__8);
      setState(346);
      exp();
      setState(347);
      match(CACTParser::T__9);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RValContext ------------------------------------------------------------------

CACTParser::RValContext::RValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::RValContext::getRuleIndex() const {
  return CACTParser::RuleRVal;
}

void CACTParser::RValContext::copyFrom(RValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->arraySize = ctx->arraySize;
  this->dataType = ctx->dataType;
  this->result = ctx->result;
  this->thisSymbol = ctx->thisSymbol;
}

//----------------- RValBasicContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::RValBasicContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::RValBasicContext::RValBasicContext(RValContext *ctx) { copyFrom(ctx); }

void CACTParser::RValBasicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRValBasic(this);
}
void CACTParser::RValBasicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRValBasic(this);
}
//----------------- RValIndexedContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::RValIndexedContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ExpContext* CACTParser::RValIndexedContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::RValIndexedContext::RValIndexedContext(RValContext *ctx) { copyFrom(ctx); }

void CACTParser::RValIndexedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRValIndexed(this);
}
void CACTParser::RValIndexedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRValIndexed(this);
}
CACTParser::RValContext* CACTParser::rVal() {
  RValContext *_localctx = _tracker.createInstance<RValContext>(_ctx, getState());
  enterRule(_localctx, 68, CACTParser::RuleRVal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(357);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CACTParser::RValBasicContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(351);
      match(CACTParser::Ident);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CACTParser::RValIndexedContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(352);
      match(CACTParser::Ident);
      setState(353);
      match(CACTParser::T__8);
      setState(354);
      exp();
      setState(355);
      match(CACTParser::T__9);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncValContext ------------------------------------------------------------------

CACTParser::FuncValContext::FuncValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::FuncValContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::FuncRParamsContext* CACTParser::FuncValContext::funcRParams() {
  return getRuleContext<CACTParser::FuncRParamsContext>(0);
}


size_t CACTParser::FuncValContext::getRuleIndex() const {
  return CACTParser::RuleFuncVal;
}

void CACTParser::FuncValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncVal(this);
}

void CACTParser::FuncValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncVal(this);
}

CACTParser::FuncValContext* CACTParser::funcVal() {
  FuncValContext *_localctx = _tracker.createInstance<FuncValContext>(_ctx, getState());
  enterRule(_localctx, 70, CACTParser::RuleFuncVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(359);
    match(CACTParser::Ident);
    setState(360);
    match(CACTParser::T__10);
    setState(362);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2130333140992) != 0)) {
      setState(361);
      funcRParams();
    }
    setState(364);
    match(CACTParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncRParamsContext ------------------------------------------------------------------

CACTParser::FuncRParamsContext::FuncRParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::ExpContext *> CACTParser::FuncRParamsContext::exp() {
  return getRuleContexts<CACTParser::ExpContext>();
}

CACTParser::ExpContext* CACTParser::FuncRParamsContext::exp(size_t i) {
  return getRuleContext<CACTParser::ExpContext>(i);
}


size_t CACTParser::FuncRParamsContext::getRuleIndex() const {
  return CACTParser::RuleFuncRParams;
}

void CACTParser::FuncRParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncRParams(this);
}

void CACTParser::FuncRParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncRParams(this);
}

CACTParser::FuncRParamsContext* CACTParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 72, CACTParser::RuleFuncRParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(366);
    exp();
    setState(371);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__5) {
      setState(367);
      match(CACTParser::T__5);
      setState(368);
      exp();
      setState(373);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool CACTParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 19: return mulExpSempred(antlrcpp::downCast<MulExpContext *>(context), predicateIndex);
    case 21: return addExpSempred(antlrcpp::downCast<AddExpContext *>(context), predicateIndex);
    case 23: return relExpSempred(antlrcpp::downCast<RelExpContext *>(context), predicateIndex);
    case 25: return eqExpSempred(antlrcpp::downCast<EqExpContext *>(context), predicateIndex);
    case 27: return lAndExpSempred(antlrcpp::downCast<LAndExpContext *>(context), predicateIndex);
    case 28: return lOrExpSempred(antlrcpp::downCast<LOrExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CACTParser::mulExpSempred(MulExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::addExpSempred(AddExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::relExpSempred(RelExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CACTParser::eqExpSempred(EqExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void CACTParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  cactParserInitialize();
#else
  ::antlr4::internal::call_once(cactParserOnceFlag, cactParserInitialize);
#endif
}
