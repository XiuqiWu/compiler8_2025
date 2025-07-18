#include <iostream>
#include "IRCode.h"

IRCode::IRCode(IROperation new_op, IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: operation(new_op), result(new_result), arg1(new_arg1), arg2(new_arg2) { }

IROperation IRCode::get_op() {
    return operation;
}

IROperand * IRCode::get_a1() {
    return arg1;
}

IROperand * IRCode::get_a2() {
    return arg2;
}

IROperand * IRCode::get_ans() {
    return result;
}
static void printAssign(const std::string& result, const std::string& arg1, const std::string& op = "", const std::string& arg2 = "") {
    std::cout << result << " := ";
    if (!op.empty()) {
        std::cout << arg1 << " " << op << " " << arg2;
    } else {
        std::cout << arg1;
    }
    std::cout << ";" << std::endl;
}

// 辅助函数：打印带索引的赋值
static void printIndexedAssign(const std::string& result, const std::string& arg1, const std::string& index, bool isLoad) {
    if (isLoad) {
        std::cout << result << " := " << arg1 << " [ " << index << " ] ;" << std::endl;
    } else {
        std::cout << arg1 << " [ " << index << " ] := " << result << ";" << std::endl;
    }
}

// 辅助函数：打印条件跳转
static void printConditionalJump(const std::string& cond, const std::string& arg1, const std::string& arg2, const std::string& label) {
    std::cout << "If " << arg1 << " " << cond << " " << arg2 << " Goto " << label << ";" << std::endl;
}

// 标签与跳转相关
IR_lab::IR_lab(IROperand * new_arg1) : IRCode(LABEL_HERE, nullptr, new_arg1, nullptr) { }
IR_jump::IR_jump(IROperand * new_result) : IRCode(GOTO, new_result, nullptr, nullptr) { }

// 参数相关
IR_para_w::IR_para_w(IROperand * new_arg1) : IRCode(PARAM_W, nullptr, new_arg1, nullptr) { }
IR_para_f::IR_para_f(IROperand * new_arg1) : IRCode(PARAM_F, nullptr, new_arg1, nullptr) { }
IR_para_d::IR_para_d(IROperand * new_arg1) : IRCode(PARAM_D, nullptr, new_arg1, nullptr) { }
IR_para_w_get::IR_para_w_get(IROperand * new_result) : IRCode(GET_PARAM_W, new_result, nullptr, nullptr) { }
IR_para_f_get::IR_para_f_get(IROperand * new_result) : IRCode(GET_PARAM_F, new_result, nullptr, nullptr) { }
IR_para_d_get::IR_para_d_get(IROperand * new_result) : IRCode(GET_PARAM_D, new_result, nullptr, nullptr) { }

// 函数调用与返回相关
IR_call::IR_call(IROperand * new_arg1) : IRCode(CALL, nullptr, new_arg1, nullptr) { }
IR_w_return::IR_w_return(IROperand * new_arg1) : IRCode(RETURN_W, nullptr, new_arg1, nullptr) { }
IR_f_return::IR_f_return(IROperand * new_arg1) : IRCode(RETURN_F, nullptr, new_arg1, nullptr) { }
IR_d_return::IR_d_return(IROperand * new_arg1) : IRCode(RETURN_D, nullptr, new_arg1, nullptr) { }
IR_w_return_get::IR_w_return_get(IROperand * new_result) : IRCode(GET_RETURN_W, new_result, nullptr, nullptr) { }
IR_f_return_get::IR_f_return_get(IROperand * new_result) : IRCode(GET_RETURN_F, new_result, nullptr, nullptr) { }
IR_d_return_get::IR_d_return_get(IROperand * new_result) : IRCode(GET_RETURN_D, new_result, nullptr, nullptr) { }

// 赋值相关
IR_w_Copy::IR_w_Copy(IROperand * new_result, IROperand * new_arg1) : IRCode(COPY_W, new_result, new_arg1, nullptr) { }
IR_f_Copy::IR_f_Copy(IROperand * new_result, IROperand * new_arg1) : IRCode(COPY_F, new_result, new_arg1, nullptr) { }
IR_d_Copy::IR_d_Copy(IROperand * new_result, IROperand * new_arg1) : IRCode(COPY_D, new_result, new_arg1, nullptr) { }
IR_w_indexed_copyfrom::IR_w_indexed_copyfrom(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(COPY_FROM_INDEXED_W, new_result, new_arg1, new_arg2) { }
IR_f_indexed_copyfrom::IR_f_indexed_copyfrom(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(COPY_FROM_INDEXED_F, new_result, new_arg1, new_arg2) { }
IR_d_indexed_copyfrom::IR_d_indexed_copyfrom(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(COPY_FROM_INDEXED_D, new_result, new_arg1, new_arg2) { }
IR_w_indexed_copy::IR_w_indexed_copy(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(COPY_TO_INDEXED_W, new_result, new_arg1, new_arg2) { }
IR_f_indexed_copy::IR_f_indexed_copy(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(COPY_TO_INDEXED_F, new_result, new_arg1, new_arg2) { }
IR_d_indexed_copy::IR_d_indexed_copy(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(COPY_TO_INDEXED_D, new_result, new_arg1, new_arg2) { }

// 算术运算相关
IR_int_add::IR_int_add(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(ADD_INT, new_result, new_arg1, new_arg2) { }
IR_float_add::IR_float_add(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(ADD_FLOAT, new_result, new_arg1, new_arg2) { }
IR_double_add::IR_double_add(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(ADD_DOUBEL, new_result, new_arg1, new_arg2) { }
IR_int_sub::IR_int_sub(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(SUB_INT, new_result, new_arg1, new_arg2) { }
IR_float_sub::IR_float_sub(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(SUB_FLOAT, new_result, new_arg1, new_arg2) { }
IR_double_sub::IR_double_sub(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(SUB_DOUBEL, new_result, new_arg1, new_arg2) { }
IR_int_neg::IR_int_neg(IROperand * new_result, IROperand * new_arg1) : IRCode(NEG_INT, new_result, new_arg1, nullptr) { }
IR_float_neg::IR_float_neg(IROperand * new_result, IROperand * new_arg1) : IRCode(NEG_FLOAT, new_result, new_arg1, nullptr) { }
IR_double_neg::IR_double_neg(IROperand * new_result, IROperand * new_arg1) : IRCode(NEG_DOUBLE, new_result, new_arg1, nullptr) { }
IR_int_mul::IR_int_mul(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(MUL_INT, new_result, new_arg1, new_arg2) { }
IR_float_mul::IR_float_mul(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(MUL_FLOAT, new_result, new_arg1, new_arg2) { }
IR_double_mul::IR_double_mul(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(MUL_DOUBLE, new_result, new_arg1, new_arg2) { }
IR_int_div::IR_int_div(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(DIV_INT, new_result, new_arg1, new_arg2) { }
IR_float_div::IR_float_div(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(DIV_FLOAT, new_result, new_arg1, new_arg2) { }
IR_double_div::IR_double_div(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(DIV_DOUBLE, new_result, new_arg1, new_arg2) { }
IR_int_mod::IR_int_mod(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(DIV_INT, new_result, new_arg1, new_arg2) { }
IR_bool_not::IR_bool_not(IROperand * new_result, IROperand * new_arg1) : IRCode(DIV_INT, new_result, new_arg1, nullptr) { }

// 条件跳转相关
IR_greater_than_zero_goto_if::IR_greater_than_zero_goto_if(IROperand * new_result, IROperand * new_arg1) : IRCode(IF_GREATER_THAN_ZERO_GOTO, new_result, new_arg1, nullptr) { }
IR_w_equal_goto_if::IR_w_equal_goto_if(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(IF_EQUAL_GOTO_W, new_result, new_arg1, new_arg2) { }
IR_f_equal_goto_if::IR_f_equal_goto_if(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(IF_EQUAL_GOTO_F, new_result, new_arg1, new_arg2) { }
IR_d_equal_goto_if::IR_d_equal_goto_if(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(IF_EQUAL_GOTO_D, new_result, new_arg1, new_arg2) { }
IR_w_greater_than_goto_if::IR_w_greater_than_goto_if(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(IF_GREATER_THAN_GOTO_W, new_result, new_arg1, new_arg2) { }
IR_f_greater_than_goto_if::IR_f_greater_than_goto_if(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(IF_GREATER_THAN_GOTO_F, new_result, new_arg1, new_arg2) { }
IR_d_greater_than_goto_if::IR_d_greater_than_goto_if(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(IF_GREATER_THAN_GOTO_D, new_result, new_arg1, new_arg2) { }
IR_w_greater_equal_than_goto_if::IR_w_greater_equal_than_goto_if(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(IF_GREATER_EQUAL_THAN_GOTO_W, new_result, new_arg1, new_arg2) { }
IR_f_greater_equal_than_goto_if::IR_f_greater_equal_than_goto_if(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(IF_GREATER_EQUAL_THAN_GOTO_F, new_result, new_arg1, new_arg2) { }
IR_d_greater_equal_than_goto_if::IR_d_greater_equal_than_goto_if(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(IF_GREATER_EQUAL_THAN_GOTO_D, new_result, new_arg1, new_arg2) { }
IR_w_less_than_goto_if::IR_w_less_than_goto_if(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(IF_LESS_THAN_GOTO_W, new_result, new_arg1, new_arg2) { }
IR_f_less_than_goto_if::IR_f_less_than_goto_if(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(IF_LESS_THAN_GOTO_F, new_result, new_arg1, new_arg2) { }
IR_d_less_than_goto_if::IR_d_less_than_goto_if(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(IF_LESS_THAN_GOTO_D, new_result, new_arg1, new_arg2) { }
IR_w_less_equal_than_goto_if::IR_w_less_equal_than_goto_if(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(IF_LESS_EQUAL_THAN_GOTO_W, new_result, new_arg1, new_arg2) { }
IR_f_less_equal_than_goto_if::IR_f_less_equal_than_goto_if(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(IF_LESS_EQUAL_THAN_GOTO_F, new_result, new_arg1, new_arg2) { }
IR_d_less_equal_than_goto_if::IR_d_less_equal_than_goto_if(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2) : IRCode(IF_LESS_EQUAL_THAN_GOTO_D, new_result, new_arg1, new_arg2) { }

void IR_lab::print() {
    std::cout << get_a1()->getName() << ":" << std::endl;
}

// 统一参数打印
static void printParam(IROperand* op) {
    std::cout << "param " << op->getName() << ";" << std::endl;
}

void IR_para_w::print() { printParam(get_a1()); }
void IR_para_f::print() { printParam(get_a1()); }
void IR_para_d::print() { printParam(get_a1()); }

// 统一获取参数打印
static void printGetParam(IROperand* op) {
    std::cout << op->getName() << " = param;" << std::endl;
}

void IR_para_w_get::print() { printGetParam(get_ans()); }
void IR_para_f_get::print() { printGetParam(get_ans()); }
void IR_para_d_get::print() { printGetParam(get_ans()); }

void IR_call::print() {
    std::cout << "call " << get_a1()->getName() << "; " << std::endl;
}

// 统一返回打印
static void printReturn(IROperand* op) {
    std::cout << "return " << op->getName() << ";" << std::endl;
}

void IR_w_return::print() { printReturn(get_a1()); }
void IR_f_return::print() { printReturn(get_a1()); }
void IR_d_return::print() { printReturn(get_a1()); }

// 统一获取返回值打印
static void printGetReturn(IROperand* op) {
    std::cout << op->getName() << " = return;" << std::endl;
}

void IR_w_return_get::print() { printGetReturn(get_ans()); }
void IR_f_return_get::print() { printGetReturn(get_ans()); }
void IR_d_return_get::print() { printGetReturn(get_ans()); }

// 统一赋值打印
static void printCopy(IROperand* result, IROperand* source) {
    printAssign(result->getName(), source->getName());
}

void IR_w_Copy::print() { printCopy(get_ans(), get_a1()); }
void IR_f_Copy::print() { printCopy(get_ans(), get_a1()); }
void IR_d_Copy::print() { printCopy(get_ans(), get_a1()); }

// 统一索引加载打印
static void printIndexedLoad(IROperand* result, IROperand* base, IROperand* index) {
    printIndexedAssign(result->getName(), base->getName(), index->getName(), true);
}

void IR_w_indexed_copyfrom::print() { printIndexedLoad(get_ans(), get_a1(), get_a2()); }
void IR_f_indexed_copyfrom::print() { printIndexedLoad(get_ans(), get_a1(), get_a2()); }
void IR_d_indexed_copyfrom::print() { printIndexedLoad(get_ans(), get_a1(), get_a2()); }

// 统一索引存储打印
static void printIndexedStore(IROperand* base, IROperand* value, IROperand* index) {
    printIndexedAssign(value->getName(), base->getName(), index->getName(), false);
}

void IR_w_indexed_copy::print() { printIndexedStore(get_ans(), get_a1(), get_a2()); }
void IR_f_indexed_copy::print() { printIndexedStore(get_ans(), get_a1(), get_a2()); }
void IR_d_indexed_copy::print() { printIndexedStore(get_ans(), get_a1(), get_a2()); }

// 统一二元运算打印
static void printBinaryOp(IROperand* result, IROperand* arg1, IROperand* arg2, const std::string& op) {
    printAssign(result->getName(), arg1->getName(), op, arg2->getName());
}

void IR_int_add::print() { printBinaryOp(get_ans(), get_a1(), get_a2(), "+"); }
void IR_float_add::print() { printBinaryOp(get_ans(), get_a1(), get_a2(), "+"); }
void IR_double_add::print() { printBinaryOp(get_ans(), get_a1(), get_a2(), "+"); }

void IR_int_sub::print() { printBinaryOp(get_ans(), get_a1(), get_a2(), "-"); }
void IR_float_sub::print() { printBinaryOp(get_ans(), get_a1(), get_a2(), "-"); }
void IR_double_sub::print() { printBinaryOp(get_ans(), get_a1(), get_a2(), "-"); }

void IR_int_mul::print() { printBinaryOp(get_ans(), get_a1(), get_a2(), "*"); }
void IR_float_mul::print() { printBinaryOp(get_ans(), get_a1(), get_a2(), "*"); }
void IR_double_mul::print() { printBinaryOp(get_ans(), get_a1(), get_a2(), "*"); }

void IR_int_div::print() { printBinaryOp(get_ans(), get_a1(), get_a2(), "/"); }
void IR_float_div::print() { printBinaryOp(get_ans(), get_a1(), get_a2(), "/"); }
void IR_double_div::print() { printBinaryOp(get_ans(), get_a1(), get_a2(), "/"); }

void IR_int_mod::print() { printBinaryOp(get_ans(), get_a1(), get_a2(), "%"); }

// 统一一元运算打印
static void printUnaryOp(IROperand* result, IROperand* arg, const std::string& op) {
    printAssign(result->getName(), op + arg->getName());
}

void IR_int_neg::print() { printUnaryOp(get_ans(), get_a1(), "-"); }
void IR_float_neg::print() { printUnaryOp(get_ans(), get_a1(), "-"); }
void IR_double_neg::print() { printUnaryOp(get_ans(), get_a1(), "-"); }

void IR_bool_not::print() { printUnaryOp(get_ans(), get_a1(), "not"); }

void IR_greater_than_zero_goto_if::print() {
    std::cout << "If " << get_a1()->getName() << " >= 0 Goto " << get_ans()->getName() << ";" << std::endl;
}

// 统一条件跳转打印
static void printConditionalJump(IROperand* label, IROperand* arg1, IROperand* arg2, const std::string& cond) {
    printConditionalJump(cond, arg1->getName(), arg2->getName(), label->getName());
}

void IR_w_equal_goto_if::print() { printConditionalJump(get_ans(), get_a1(), get_a2(), "=="); }
void IR_f_equal_goto_if::print() { printConditionalJump(get_ans(), get_a1(), get_a2(), "=="); }
void IR_d_equal_goto_if::print() { printConditionalJump(get_ans(), get_a1(), get_a2(), "=="); }

void IR_w_greater_than_goto_if::print() { printConditionalJump(get_ans(), get_a1(), get_a2(), ">"); }
void IR_f_greater_than_goto_if::print() { printConditionalJump(get_ans(), get_a1(), get_a2(), ">"); }
void IR_d_greater_than_goto_if::print() { printConditionalJump(get_ans(), get_a1(), get_a2(), ">"); }

void IR_w_greater_equal_than_goto_if::print() { printConditionalJump(get_ans(), get_a1(), get_a2(), ">="); }
void IR_f_greater_equal_than_goto_if::print() { printConditionalJump(get_ans(), get_a1(), get_a2(), ">="); }
void IR_d_greater_equal_than_goto_if::print() { printConditionalJump(get_ans(), get_a1(), get_a2(), ">="); }

void IR_w_less_than_goto_if::print() { printConditionalJump(get_ans(), get_a1(), get_a2(), "<"); }
void IR_f_less_than_goto_if::print() { printConditionalJump(get_ans(), get_a1(), get_a2(), "<"); }
void IR_d_less_than_goto_if::print() { printConditionalJump(get_ans(), get_a1(), get_a2(), "<"); }

void IR_w_less_equal_than_goto_if::print() { printConditionalJump(get_ans(), get_a1(), get_a2(), "<="); }
void IR_f_less_equal_than_goto_if::print() { printConditionalJump(get_ans(), get_a1(), get_a2(), "<="); }
void IR_d_less_equal_than_goto_if::print() { printConditionalJump(get_ans(), get_a1(), get_a2(), "<="); }

void IR_jump::print() {
    std::cout << "Goto " << get_ans()->getName() << ";" << std::endl;
}

// 目标代码生成辅助函数
static void genIndexedCopy(TargetCodeList* t, IROperand* result, IROperand* base, IROperand* index, 
                          const std::string& loadCmd, const std::string& storeCmd, bool isLoad) 
{
    base->loadAddrTo(t, "t5");
    index->loadTo(t, "t6");
    t->add("\tadd\tt5, t5, t6");
    
    if (isLoad) {
        t->add("\t" + loadCmd + " t4, 0(t5)");
        result->storeFrom(t, "t4");
    } else {
        result->loadTo(t, "t4");
        t->add("\t" + storeCmd + " t4, 0(t5)");
    }
}

static void genBinaryOp(TargetCodeList* t, IROperand* result, IROperand* arg1, IROperand* arg2, 
                       const std::string& opCode, const std::string& regType = "t") 
{
    std::string reg1 = regType + "5";
    std::string reg2 = regType + "6";
    std::string dest = regType + "4";
    
    arg1->loadTo(t, reg1);
    arg2->loadTo(t, reg2);
    t->add("\t" + opCode + " " + dest + ", " + reg1 + ", " + reg2);
    result->storeFrom(t, dest);
}

static void genUnaryOp(TargetCodeList* t, IROperand* result, IROperand* arg, 
                      const std::string& opCode, const std::string& regType = "t") 
{
    std::string src = regType + "5";
    std::string dest = regType + "4";
    
    arg->loadTo(t, src);
    t->add("\t" + opCode + " " + dest + ", " + src);
    result->storeFrom(t, dest);
}

static void genFloatCondition(TargetCodeList* t, IROperand* result, IROperand* arg1, IROperand* arg2,
                            const std::string& condOp, const std::string& floatType) 
{
    arg1->loadTo(t, "ft5");
    arg2->loadTo(t, "ft6");
    t->add("\t" + condOp + "." + floatType + " t4, ft5, ft6");
    t->add("\tbnez\tt4, " + result->getImme());
}

// 目标代码生成实现
void IR_lab::genTargetCode(TargetCodeList * t) {
    t->add(get_a1()->getImme() + ":");
}

void IR_para_w::genTargetCode(TargetCodeList * t) {
    get_a1()->loadTo(t, t->getRegParamX());
}

void IR_para_f::genTargetCode(TargetCodeList * t) {
    get_a1()->loadTo(t, t->getRegParamF());
}

void IR_para_d::genTargetCode(TargetCodeList * t) {
    get_a1()->loadTo(t, t->getRegParamF()); // 双精度使用相同寄存器
}

void IR_para_w_get::genTargetCode(TargetCodeList * t) {
    get_ans()->storeFrom(t, t->getRegGetParamX());
}

void IR_para_f_get::genTargetCode(TargetCodeList * t) {
    get_ans()->storeFrom(t, t->getRegGetParamF());
}

void IR_para_d_get::genTargetCode(TargetCodeList * t) {
    get_ans()->storeFrom(t, t->getRegGetParamF());
}

void IR_call::genTargetCode(TargetCodeList * t) {
    t->resetRegParam();
    t->add("\tcall\t" + get_a1()->getImme());
}

void IR_w_return::genTargetCode(TargetCodeList * t) {
    get_a1()->loadTo(t, "a0");
}

void IR_f_return::genTargetCode(TargetCodeList * t) {
    get_a1()->loadTo(t, "fa0");
}

void IR_d_return::genTargetCode(TargetCodeList * t) {
    get_a1()->loadTo(t, "fa0");
}

void IR_w_return_get::genTargetCode(TargetCodeList * t) {
    get_ans()->storeFrom(t, "a0");
}

void IR_f_return_get::genTargetCode(TargetCodeList * t) {
    get_ans()->storeFrom(t, "fa0");
}

void IR_d_return_get::genTargetCode(TargetCodeList * t) {
    get_ans()->storeFrom(t, "fa0"); 
}

void IR_w_Copy::genTargetCode(TargetCodeList * t) {
    get_a1()->loadTo(t, "t4");
    get_ans()->storeFrom(t, "t4");
}

void IR_f_Copy::genTargetCode(TargetCodeList * t) {
    get_a1()->loadTo(t, "ft4");
    get_ans()->storeFrom(t, "ft4");
}

void IR_d_Copy::genTargetCode(TargetCodeList * t) {
    get_a1()->loadTo(t, "ft4");
    get_ans()->storeFrom(t, "ft4");
}

void IR_w_indexed_copyfrom::genTargetCode(TargetCodeList * t) {
    genIndexedCopy(t, get_ans(), get_a1(), get_a2(), "lw", "", true);
}

void IR_f_indexed_copyfrom::genTargetCode(TargetCodeList * t) {
    genIndexedCopy(t, get_ans(), get_a1(), get_a2(), "flw", "", true);
}

void IR_d_indexed_copyfrom::genTargetCode(TargetCodeList * t) {
    genIndexedCopy(t, get_ans(), get_a1(), get_a2(), "fld", "", true);
}

void IR_w_indexed_copy::genTargetCode(TargetCodeList * t) {
    genIndexedCopy(t, get_a1(), get_ans(), get_a2(), "", "sw", false);
}

void IR_f_indexed_copy::genTargetCode(TargetCodeList * t) {
    genIndexedCopy(t, get_a1(), get_ans(), get_a2(), "", "fsw", false);
}

void IR_d_indexed_copy::genTargetCode(TargetCodeList * t) {
    genIndexedCopy(t, get_a1(), get_ans(), get_a2(), "", "fsd", false);
}

void IR_int_add::genTargetCode(TargetCodeList * t) {
    genBinaryOp(t, get_ans(), get_a1(), get_a2(), "add");
}

void IR_float_add::genTargetCode(TargetCodeList * t) {
    genBinaryOp(t, get_ans(), get_a1(), get_a2(), "fadd.s", "f");
}

void IR_double_add::genTargetCode(TargetCodeList * t) {
    genBinaryOp(t, get_ans(), get_a1(), get_a2(), "fadd.d", "f");
}

void IR_int_sub::genTargetCode(TargetCodeList * t) {
    genBinaryOp(t, get_ans(), get_a1(), get_a2(), "sub");
}

void IR_float_sub::genTargetCode(TargetCodeList * t) {
    genBinaryOp(t, get_ans(), get_a1(), get_a2(), "fsub.s", "f");
}

void IR_double_sub::genTargetCode(TargetCodeList * t) {
    genBinaryOp(t, get_ans(), get_a1(), get_a2(), "fsub.d", "f");
}

void IR_int_neg::genTargetCode(TargetCodeList * t) {
    genUnaryOp(t, get_ans(), get_a1(), "neg");
}

void IR_float_neg::genTargetCode(TargetCodeList * t) {
    genUnaryOp(t, get_ans(), get_a1(), "fneg.s", "f");
}

void IR_double_neg::genTargetCode(TargetCodeList * t) {
    genUnaryOp(t, get_ans(), get_a1(), "fneg.d", "f");
}

void IR_int_mul::genTargetCode(TargetCodeList * t) {
    genBinaryOp(t, get_ans(), get_a1(), get_a2(), "mul");
}

void IR_float_mul::genTargetCode(TargetCodeList * t) {
    genBinaryOp(t, get_ans(), get_a1(), get_a2(), "fmul.s", "f");
}

void IR_double_mul::genTargetCode(TargetCodeList * t) {
    genBinaryOp(t, get_ans(), get_a1(), get_a2(), "fmul.d", "f");
}

void IR_int_div::genTargetCode(TargetCodeList * t) {
    genBinaryOp(t, get_ans(), get_a1(), get_a2(), "div");
}

void IR_float_div::genTargetCode(TargetCodeList * t) {
    genBinaryOp(t, get_ans(), get_a1(), get_a2(), "fdiv.s", "f");
}

void IR_double_div::genTargetCode(TargetCodeList * t) {
    genBinaryOp(t, get_ans(), get_a1(), get_a2(), "fdiv.d", "f");
}

void IR_int_mod::genTargetCode(TargetCodeList * t) {
    genBinaryOp(t, get_ans(), get_a1(), get_a2(), "rem");
}

void IR_bool_not::genTargetCode(TargetCodeList * t) {
    genUnaryOp(t, get_ans(), get_a1(), "not");
}

void IR_greater_than_zero_goto_if::genTargetCode(TargetCodeList * t) {
    get_a1()->loadTo(t, "t5");
    t->add("\tbgtz\tt5, " + get_ans()->getImme());
}

void IR_w_equal_goto_if::genTargetCode(TargetCodeList * t) {
    get_a1()->loadTo(t, "t5");
    get_a2()->loadTo(t, "t6");
    t->add("\tbeq\tt5, t6, " + get_ans()->getImme());
}

void IR_f_equal_goto_if::genTargetCode(TargetCodeList * t) {
    genFloatCondition(t, get_ans(), get_a1(), get_a2(), "feq", "s");
}

void IR_d_equal_goto_if::genTargetCode(TargetCodeList * t) {
    genFloatCondition(t, get_ans(), get_a1(), get_a2(), "feq", "d");
}

void IR_w_greater_than_goto_if::genTargetCode(TargetCodeList * t) {
    get_a1()->loadTo(t, "t5");
    get_a2()->loadTo(t, "t6");
    t->add("\tbgt\tt5, t6, " + get_ans()->getImme());
}

void IR_f_greater_than_goto_if::genTargetCode(TargetCodeList * t) {
    genFloatCondition(t, get_ans(), get_a1(), get_a2(), "fgt", "s");
}

void IR_d_greater_than_goto_if::genTargetCode(TargetCodeList * t) {
    genFloatCondition(t, get_ans(), get_a1(), get_a2(), "fgt", "d");
}

void IR_w_greater_equal_than_goto_if::genTargetCode(TargetCodeList * t) {
    get_a1()->loadTo(t, "t5");
    get_a2()->loadTo(t, "t6");
    t->add("\tbge\tt5, t6, " + get_ans()->getImme());
}

void IR_f_greater_equal_than_goto_if::genTargetCode(TargetCodeList * t) {
    genFloatCondition(t, get_ans(), get_a1(), get_a2(), "fge", "s");
}

void IR_d_greater_equal_than_goto_if::genTargetCode(TargetCodeList * t) {
    genFloatCondition(t, get_ans(), get_a1(), get_a2(), "fge", "d");
}

void IR_w_less_than_goto_if::genTargetCode(TargetCodeList * t) {
    get_a1()->loadTo(t, "t5");
    get_a2()->loadTo(t, "t6");
    t->add("\tblt\tt5, t6, " + get_ans()->getImme());
}

void IR_f_less_than_goto_if::genTargetCode(TargetCodeList * t) {
    genFloatCondition(t, get_ans(), get_a1(), get_a2(), "flt", "s");
}

void IR_d_less_than_goto_if::genTargetCode(TargetCodeList * t) {
    genFloatCondition(t, get_ans(), get_a1(), get_a2(), "flt", "d");
}

void IR_w_less_equal_than_goto_if::genTargetCode(TargetCodeList * t) {
    get_a1()->loadTo(t, "t5");
    get_a2()->loadTo(t, "t6");
    t->add("\tble\tt5, t6, " + get_ans()->getImme());
}

void IR_f_less_equal_than_goto_if::genTargetCode(TargetCodeList * t) {
    genFloatCondition(t, get_ans(), get_a1(), get_a2(), "fle", "s");
}

void IR_d_less_equal_than_goto_if::genTargetCode(TargetCodeList * t) {
    genFloatCondition(t, get_ans(), get_a1(), get_a2(), "fle", "d");
}

void IR_jump::genTargetCode(TargetCodeList * t) {
    t->add("\tj\t" + get_ans()->getImme());
}