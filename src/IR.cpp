#include <iostream>

#include "IR.h"

IRFunction::IRFunction(std::string newFunctionName)
: functionName(newFunctionName) { }

void IRFunction::print() {
    std::cout << "function " << functionName << ":" << std::endl;

    for (auto p : codes) {
        p->print();
    }

    std::cout << std::endl;
    std::cout << std::endl;
}

void IRFunction::generatetg(TargetCodeList * t) {
    int stack_off = -16;

    for (auto var : localVariables) {
        int align = var->getAlign();

        stack_off -= var->getSize();
        stack_off &= ~((1 << align) - 1);

        var->setMemOff(stack_off);
    }

    stack_off >>= 4;
    stack_off <<= 4;

    frameSize = -stack_off;

    t->add(std::string("\t.text"));
    t->add(std::string("\t.align\t1"));
    t->add(std::string("\t.globl\t") + functionName);
    t->add(std::string("\t.type\t") + functionName + std::string(", @function"));
    t->add(functionName + std::string(":"));

    t->add(std::string("\taddi\tsp, sp, ") + std::to_string(-frameSize));
    t->add(std::string("\tsd\tra, ") + std::to_string(frameSize - 8) + std::string("(sp)"));
    t->add(std::string("\tsd\ts0, ") + std::to_string(frameSize - 16) + std::string("(sp)"));
    t->add(std::string("\taddi\ts0, sp, ") + std::to_string(frameSize));

    for (auto oneCode : codes) {
        oneCode->genTargetCode(t);
    }

    t->add(std::string("\tld\tra, ") + std::to_string(frameSize - 8) + std::string("(sp)"));
    t->add(std::string("\tld\ts0, ") + std::to_string(frameSize - 16) + std::string("(sp)"));
    t->add(std::string("\taddi\tsp, sp, ") + std::to_string(frameSize));
    t->add(std::string("\tjr\tra"));
}

IRProgram::IRProgram(std::string newFilename)
: filename(newFilename) { }

void IRProgram::print() {
    std::cout << "------------------------- IR -------------------------" << std::endl;
    std::cout << "data: " << std::endl;

    for (auto p : globalValues) {
        std::cout << p->getName() << std::endl;
    }

    std::cout << "text: " << std::endl;

    for (auto p : functions) {
        p->print();
    }

    std::cout << "========================= IR =========================" << std::endl;
}

void IRProgram::generatetg(TargetCodeList * t) {
    for (auto oneValue : globalValues) {
        oneValue->alloc(t);
    }
    for (auto oneFunc : functions) {
        oneFunc->generatetg(t);
    }
}