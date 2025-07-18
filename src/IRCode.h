#pragma once

#include <string>
#include <vector>
#include <map>

#include "CACT.h"
#include "IROperand.hpp"

enum IROperation {
    PARAM_W,
    PARAM_F,
    PARAM_D,
    GET_PARAM_W,
    GET_PARAM_F,
    GET_PARAM_D,
    LABEL_HERE,
    CALL,
    RETURN_W,
    RETURN_F,
    RETURN_D,
    GET_RETURN_W,
    GET_RETURN_F,
    GET_RETURN_D,
    COPY_W,
    COPY_F,
    COPY_D,
    COPY_FROM_INDEXED_W,
    COPY_FROM_INDEXED_F,
    COPY_FROM_INDEXED_D,
    COPY_TO_INDEXED_W,
    COPY_TO_INDEXED_F,
    COPY_TO_INDEXED_D,
    ADD_INT,
    ADD_FLOAT,
    ADD_DOUBEL,
    SUB_INT,
    SUB_FLOAT,
    SUB_DOUBEL,
    NEG_INT,
    NEG_FLOAT,
    NEG_DOUBLE,
    MUL_INT,
    MUL_FLOAT,
    MUL_DOUBLE,
    DIV_INT,
    DIV_FLOAT,
    DIV_DOUBLE,
    MOD_INT,
    NOT_BOOL,
    IF_GREATER_THAN_ZERO_GOTO,
    IF_EQUAL_GOTO_W,
    IF_EQUAL_GOTO_F,
    IF_EQUAL_GOTO_D,
    IF_GREATER_THAN_GOTO_W,
    IF_GREATER_THAN_GOTO_F,
    IF_GREATER_THAN_GOTO_D,
    IF_GREATER_EQUAL_THAN_GOTO_W,
    IF_GREATER_EQUAL_THAN_GOTO_F,
    IF_GREATER_EQUAL_THAN_GOTO_D,
    IF_LESS_THAN_GOTO_W,
    IF_LESS_THAN_GOTO_F,
    IF_LESS_THAN_GOTO_D,
    IF_LESS_EQUAL_THAN_GOTO_W,
    IF_LESS_EQUAL_THAN_GOTO_F,
    IF_LESS_EQUAL_THAN_GOTO_D,
    GOTO,
};

class IRCode {
private:
    IROperation operation;
    IROperand * result;
    IROperand * arg1;
    IROperand * arg2;

public:
    IRCode(IROperation new_op, IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    IROperation get_op();
    IROperand * get_a1();
    IROperand * get_a2();
    IROperand * get_ans();

    virtual void print() = 0;
    virtual void genTargetCode(TargetCodeList * t) = 0;
};

// 标签与跳转相关
class IR_lab : public IRCode {
public:
    IR_lab(IROperand * new_arg1);
    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IR_jump : public IRCode {
public:
    IR_jump(IROperand * new_result);
    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

// 宏定义用于生成参数、返回和赋值相关类
#define DECLARE_PARAM_CLASS(name, type) \
class IR_##name : public IRCode { \
public: \
    IR_##name(IROperand * operand); \
    virtual void print(); \
    void genTargetCode(TargetCodeList * t); \
};

DECLARE_PARAM_CLASS(para_w, PARAM_W)
DECLARE_PARAM_CLASS(para_f, PARAM_F)
DECLARE_PARAM_CLASS(para_d, PARAM_D)

#define DECLARE_GET_PARAM_CLASS(name, type) \
class IR_##name : public IRCode { \
public: \
    IR_##name(IROperand * operand); \
    virtual void print(); \
    void genTargetCode(TargetCodeList * t); \
};

DECLARE_GET_PARAM_CLASS(para_w_get, GET_PARAM_W)
DECLARE_GET_PARAM_CLASS(para_f_get, GET_PARAM_F)
DECLARE_GET_PARAM_CLASS(para_d_get, GET_PARAM_D)

// 函数调用与返回相关
class IR_call : public IRCode {
public:
    IR_call(IROperand * new_arg1);
    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

#define DECLARE_RETURN_CLASS(name, type) \
class IR_##name : public IRCode { \
public: \
    IR_##name(IROperand * operand); \
    virtual void print(); \
    void genTargetCode(TargetCodeList * t); \
};

DECLARE_RETURN_CLASS(w_return, RETURN_W)
DECLARE_RETURN_CLASS(f_return, RETURN_F)
DECLARE_RETURN_CLASS(d_return, RETURN_D)

#define DECLARE_RETURN_GET_CLASS(name, type) \
class IR_##name : public IRCode { \
public: \
    IR_##name(IROperand * operand); \
    virtual void print(); \
    void genTargetCode(TargetCodeList * t); \
};

DECLARE_RETURN_GET_CLASS(w_return_get, GET_RETURN_W)
DECLARE_RETURN_GET_CLASS(f_return_get, GET_RETURN_F)
DECLARE_RETURN_GET_CLASS(d_return_get, GET_RETURN_D)

// 赋值相关
#define DECLARE_COPY_CLASS(name, type) \
class IR_##name : public IRCode { \
public: \
    IR_##name(IROperand * result, IROperand * source); \
    virtual void print(); \
    void genTargetCode(TargetCodeList * t); \
};

DECLARE_COPY_CLASS(w_Copy, COPY_W)
DECLARE_COPY_CLASS(f_Copy, COPY_F)
DECLARE_COPY_CLASS(d_Copy, COPY_D)

#define DECLARE_INDEXED_COPYFROM_CLASS(name, type) \
class IR_##name : public IRCode { \
public: \
    IR_##name(IROperand * result, IROperand * base, IROperand * index); \
    virtual void print(); \
    void genTargetCode(TargetCodeList * t); \
};

DECLARE_INDEXED_COPYFROM_CLASS(w_indexed_copyfrom, COPY_FROM_INDEXED_W)
DECLARE_INDEXED_COPYFROM_CLASS(f_indexed_copyfrom, COPY_FROM_INDEXED_F)
DECLARE_INDEXED_COPYFROM_CLASS(d_indexed_copyfrom, COPY_FROM_INDEXED_D)

#define DECLARE_INDEXED_COPY_CLASS(name, type) \
class IR_##name : public IRCode { \
public: \
    IR_##name(IROperand * result, IROperand * value, IROperand * index); \
    virtual void print(); \
    void genTargetCode(TargetCodeList * t); \
};

DECLARE_INDEXED_COPY_CLASS(w_indexed_copy, COPY_TO_INDEXED_W)
DECLARE_INDEXED_COPY_CLASS(f_indexed_copy, COPY_TO_INDEXED_F)
DECLARE_INDEXED_COPY_CLASS(d_indexed_copy, COPY_TO_INDEXED_D)

// 算术运算相关
#define DECLARE_BINARY_OP_CLASS(name, op_type) \
class IR_##name : public IRCode { \
public: \
    IR_##name(IROperand * result, IROperand * arg1, IROperand * arg2); \
    virtual void print(); \
    void genTargetCode(TargetCodeList * t); \
};

DECLARE_BINARY_OP_CLASS(int_add, ADD_INT)
DECLARE_BINARY_OP_CLASS(float_add, ADD_FLOAT)
DECLARE_BINARY_OP_CLASS(double_add, ADD_DOUBEL)
DECLARE_BINARY_OP_CLASS(int_sub, SUB_INT)
DECLARE_BINARY_OP_CLASS(float_sub, SUB_FLOAT)
DECLARE_BINARY_OP_CLASS(double_sub, SUB_DOUBEL)
DECLARE_BINARY_OP_CLASS(int_mul, MUL_INT)
DECLARE_BINARY_OP_CLASS(float_mul, MUL_FLOAT)
DECLARE_BINARY_OP_CLASS(double_mul, MUL_DOUBLE)
DECLARE_BINARY_OP_CLASS(int_div, DIV_INT)
DECLARE_BINARY_OP_CLASS(float_div, DIV_FLOAT)
DECLARE_BINARY_OP_CLASS(double_div, DIV_DOUBLE)
DECLARE_BINARY_OP_CLASS(int_mod, MOD_INT)

#define DECLARE_UNARY_OP_CLASS(name, op_type) \
class IR_##name : public IRCode { \
public: \
    IR_##name(IROperand * result, IROperand * arg); \
    virtual void print(); \
    void genTargetCode(TargetCodeList * t); \
};

DECLARE_UNARY_OP_CLASS(int_neg, NEG_INT)
DECLARE_UNARY_OP_CLASS(float_neg, NEG_FLOAT)
DECLARE_UNARY_OP_CLASS(double_neg, NEG_DOUBLE)
DECLARE_UNARY_OP_CLASS(bool_not, NOT_BOOL)

// 条件跳转相关
class IR_greater_than_zero_goto_if : public IRCode {
public:
    IR_greater_than_zero_goto_if(IROperand * result, IROperand * arg);
    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

#define DECLARE_CONDITIONAL_JUMP_CLASS(name, op_type) \
class IR_##name : public IRCode { \
public: \
    IR_##name(IROperand * result, IROperand * arg1, IROperand * arg2); \
    virtual void print(); \
    void genTargetCode(TargetCodeList * t); \
};

DECLARE_CONDITIONAL_JUMP_CLASS(w_equal_goto_if, IF_EQUAL_GOTO_W)
DECLARE_CONDITIONAL_JUMP_CLASS(f_equal_goto_if, IF_EQUAL_GOTO_F)
DECLARE_CONDITIONAL_JUMP_CLASS(d_equal_goto_if, IF_EQUAL_GOTO_D)
DECLARE_CONDITIONAL_JUMP_CLASS(w_greater_than_goto_if, IF_GREATER_THAN_GOTO_W)
DECLARE_CONDITIONAL_JUMP_CLASS(f_greater_than_goto_if, IF_GREATER_THAN_GOTO_F)
DECLARE_CONDITIONAL_JUMP_CLASS(d_greater_than_goto_if, IF_GREATER_THAN_GOTO_D)
DECLARE_CONDITIONAL_JUMP_CLASS(w_greater_equal_than_goto_if, IF_GREATER_EQUAL_THAN_GOTO_W)
DECLARE_CONDITIONAL_JUMP_CLASS(f_greater_equal_than_goto_if, IF_GREATER_EQUAL_THAN_GOTO_F)
DECLARE_CONDITIONAL_JUMP_CLASS(d_greater_equal_than_goto_if, IF_GREATER_EQUAL_THAN_GOTO_D)
DECLARE_CONDITIONAL_JUMP_CLASS(w_less_than_goto_if, IF_LESS_THAN_GOTO_W)
DECLARE_CONDITIONAL_JUMP_CLASS(f_less_than_goto_if, IF_LESS_THAN_GOTO_F)
DECLARE_CONDITIONAL_JUMP_CLASS(d_less_than_goto_if, IF_LESS_THAN_GOTO_D)
DECLARE_CONDITIONAL_JUMP_CLASS(w_less_equal_than_goto_if, IF_LESS_EQUAL_THAN_GOTO_W)
DECLARE_CONDITIONAL_JUMP_CLASS(f_less_equal_than_goto_if, IF_LESS_EQUAL_THAN_GOTO_F)
DECLARE_CONDITIONAL_JUMP_CLASS(d_less_equal_than_goto_if, IF_LESS_EQUAL_THAN_GOTO_D)