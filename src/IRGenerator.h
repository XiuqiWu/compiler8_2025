#pragma once

#include <vector>
#include <stack>
#include "symbolTable.h"
#include "IR.h"
#include "CACT.h"

// IR生成器，负责中间代码的构建与管理
class IRGenerator {
private:
    IRProgram * ir;
    IRFunction * currentIRFunc;
    IRValue * currentIRVal;
    int tempCount;
    int labelCount;
    int valueCount;
    IRLabel * funcEndLabel;
    IRLabel * arrRepeatLabel;
    IROperand * arrRepeatVar;
    std::stack<std::pair<IRLabel *, IRLabel *>> loopLabels;

public:
    explicit IRGenerator(IRProgram * newIR);

    // 函数相关
    void enterFunc(std::string name);
    void exitFunc();

    // 常量数组相关
    void startConstArr();
    void endConstArr();

    // 循环相关
    void enterLoop(IRLabel * labelBegin, IRLabel * labelEnd);
    void exitLoop();
    IRLabel * getLoopBegin();
    IRLabel * getLoopEnd();

    // Value/Var/Label 生成
    IRValue * newValue(DataType dataType);
    IRValue * newValue(DataType dataType, std::string value);
    void removeValues(int cnt);
    IRVariable * newVar(std::string name, DataType dataType);
    IRVariable * newVar(std::string name, DataType dataType, int len);
    IRLabel * newLabel(std::string name);
    IRLabel * newLabel();
    IRValue * newInt(int intVal);
    IRVariable * newTemp(DataType dataType);

    // 数组操作
    void startArrOp(DataType datatype, int len);
    void endArrOp();
    IROperand * getArrRepeatVar();

    // IR代码添加
    void addCode(IRCode * newCode);
    void addCode(std::vector<IRCode *> newCodes);
    void addReturn();

    // 赋值相关
    void assignBasic(DataType datatype, IROperand * d, IROperand * s);
    void assignArray(DataType datatype, int len, IROperand * d, IROperand * s);
};