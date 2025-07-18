#include "IRGenerator.h"

// 构造函数，初始化IR生成器
IRGenerator::IRGenerator(IRProgram * newIR)
  : ir(newIR), currentIRFunc(nullptr), currentIRVal(nullptr), tempCount(1), labelCount(1), valueCount(1), funcEndLabel(nullptr), arrRepeatLabel(nullptr), arrRepeatVar(nullptr) {}

void IRGenerator::enterFunc(std::string name) {
    currentIRFunc = new IRFunction(name);
    funcEndLabel = newLabel(".END_" + name);
    ir->functions.push_back(currentIRFunc);
    tempCount = 1;
}

void IRGenerator::exitFunc() {
    addCode(new IR_lab(funcEndLabel));
    currentIRFunc = nullptr;
    funcEndLabel = nullptr;
}

IRValue * IRGenerator::newValue(DataType dataType) {
    std::string name = ".Value" + std::to_string(valueCount++);
    auto * val = new IRValue(name, dataType);
    ir->globalValues.push_back(val);
    return val;
}

IRValue * IRGenerator::newValue(DataType dataType, std::string value) {
    std::string name = ".Val" + std::to_string(valueCount++);
    auto * val = new IRValue(name, dataType);
    val->addValue(value);
    ir->globalValues.push_back(val);
    return val;
}

void IRGenerator::removeValues(int cnt) {
    while (cnt-- > 0 && !ir->globalValues.empty()) {
        ir->globalValues.pop_back();
    }
}

IRVariable * IRGenerator::newVar(std::string name, DataType dataType) {
    auto * var = new IRVariable(name, dataType);
    if (currentIRFunc) {
        currentIRFunc->localVariables.push_back(var);
    } else {
        throw std::runtime_error("are you sure you want to add new var globally???");
    }
    return var;
}

IRVariable * IRGenerator::newVar(std::string name, DataType dataType, int len) {
    auto * var = new IRVariable(name, dataType, len);
    if (currentIRFunc) {
        currentIRFunc->localVariables.push_back(var);
    } else {
        throw std::runtime_error("are you sure you want to add new var globally???");
    }
    return var;
}

IRLabel * IRGenerator::newLabel(std::string name) {
    auto * label = new IRLabel(name);
    ir->labels.push_back(label);
    return label;
}

IRLabel * IRGenerator::newLabel() {
    std::string name = ".Label" + std::to_string(labelCount++);
    auto * label = new IRLabel(name);
    ir->labels.push_back(label);
    return label;
}

IRValue * IRGenerator::newInt(int intVal) {
    return new IRValue(intVal);
}

IRVariable * IRGenerator::newTemp(DataType dataType) {
    std::string name = ".Temp" + std::to_string(tempCount++);
    auto * temp = new IRVariable(name, dataType);
    if (currentIRFunc) {
        currentIRFunc->localVariables.push_back(temp);
    }
    return temp;
}

void IRGenerator::startArrOp(DataType datatype, int len) {
    int cellSize = SizeOfDataType(datatype);
    auto * ir_cs = newInt(cellSize);
    auto * ir_len = newInt(len);
    arrRepeatVar = newTemp(INT);
    arrRepeatLabel = newLabel();
    addCode(new IR_int_mul(arrRepeatVar, ir_cs, ir_len));
    addCode(new IR_lab(arrRepeatLabel));
    addCode(new IR_int_sub(arrRepeatVar, arrRepeatVar, ir_cs));
}

void IRGenerator::endArrOp() {
    if (arrRepeatVar) {
        addCode(new IR_greater_than_zero_goto_if(arrRepeatLabel, arrRepeatVar));
        arrRepeatLabel = nullptr;
        arrRepeatVar = nullptr;
    }
}

IROperand * IRGenerator::getArrRepeatVar() {
    if (!arrRepeatVar) throw std::runtime_error("no repeat var");
    return arrRepeatVar;
}

void IRGenerator::addCode(IRCode * newCode) {
    if (!currentIRFunc) throw std::runtime_error("not in any function, cannot add code");
    currentIRFunc->codes.push_back(newCode);
}

void IRGenerator::addCode(std::vector<IRCode *> newCodes) {
    if (!currentIRFunc) throw std::runtime_error("not in any function, cannot add code");
    for (auto * oneCode : newCodes) {
        currentIRFunc->codes.push_back(oneCode);
    }
}

void IRGenerator::addReturn() {
    addCode(new IR_jump(funcEndLabel));
}

void IRGenerator::assignBasic(DataType datatype, IROperand * d, IROperand * s) {
    switch (datatype) {
        case INT:
        case BOOL:
            addCode(new IR_w_Copy(d, s));
            break;
        case FLOAT:
            addCode(new IR_f_Copy(d, s));
            break;
        case DOUBLE:
            addCode(new IR_d_Copy(d, s));
            break;
        default:
            break;
    }
}

void IRGenerator::assignArray(DataType datatype, int len, IROperand * d, IROperand * s) {
    startArrOp(datatype, len);
    IROperand * getA = getArrRepeatVar();
    IROperand * wzh = newTemp(datatype);
    switch (datatype) {
        case INT:
            addCode(new IR_w_indexed_copyfrom(wzh, s, getA));
            addCode(new IR_w_indexed_copy(d, wzh, getA));
            endArrOp();
            return;
        case FLOAT:
            addCode(new IR_f_indexed_copyfrom(wzh, s, getA));
            addCode(new IR_f_indexed_copy(wzh, wzh, getA));
            endArrOp();
            return;
        case DOUBLE:
            addCode(new IR_d_indexed_copyfrom(wzh, s, getA));
            addCode(new IR_d_indexed_copy(d, wzh, getA));
            endArrOp();
            return;
        default:
            endArrOp();
            break;
    }
}

void IRGenerator::enterLoop(IRLabel * labelBegin, IRLabel * labelEnd) {
    loopLabels.push({labelBegin, labelEnd});
}

void IRGenerator::exitLoop() {
    if (!loopLabels.empty()) loopLabels.pop();
}

IRLabel * IRGenerator::getLoopBegin() {
    return loopLabels.top().first;
}

IRLabel * IRGenerator::getLoopEnd() {
    return loopLabels.top().second;
}