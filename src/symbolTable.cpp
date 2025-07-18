#include "symbolTable.h"
#include <iostream>

std::string ToString(DataType x) {
    switch (x) {
        case VOID: return "void";
        case BOOL: return "bool";
        case INT: return "int";
        case FLOAT: return "float";
        case DOUBLE: return "double";
        default: return "unknown";
    }
}

int SizeOfDataType(DataType x) {
    switch (x) {
        case BOOL:
        case INT:
        case FLOAT:
            return 4;
        case DOUBLE:
            return 8;
        default:
            return 0;
    }
}

// ------------------ SymbolInfo --------------------

SymbolInfo::SymbolInfo(const std::string & name)
    : name(name) {
    operand = nullptr;
}

std::string SymbolInfo::getName() {
    return name;
}

void SymbolInfo::setOp(IROperand * op) {
    operand = op;
}

IROperand * SymbolInfo::getOp() {
    if (!operand) {
        throw std::runtime_error("try to get null op");
    }
    return operand;
}

// ------------------ Const / Var Symbol --------------------

ConstSymbolInfo::ConstSymbolInfo(const std::string & name, DataType type)
    : SymbolInfo(name), dataType(type) {}

VarSymbolInfo::VarSymbolInfo(const std::string & name, DataType type)
    : SymbolInfo(name), dataType(type) {}

ConstArraySymbolInfo::ConstArraySymbolInfo(const std::string & name, DataType type, int size)
    : SymbolInfo(name), dataType(type), arraySize(size) {}

VarArraySymbolInfo::VarArraySymbolInfo(const std::string & name, DataType type, int size)
    : SymbolInfo(name), dataType(type), arraySize(size) {}

// ------------------ Function --------------------

FuncSymbolInfo::FuncSymbolInfo(const std::string & name, DataType retType)
    : SymbolInfo(name), returnType(retType), blockInfo(nullptr) {}

SymbolInfo * FuncSymbolInfo::addParamVar(const std::string & name, DataType type) {
    auto * param = new VarSymbolInfo(name, type);
    paramList.push_back(param);
    return param;
}

SymbolInfo * FuncSymbolInfo::addParamArray(const std::string & name, DataType type) {
    auto * param = new VarArraySymbolInfo(name, type, 0);
    paramList.push_back(param);
    return param;
}

// ------------------ BlockInfo lookup --------------------

SymbolInfo * BlockInfo::lookUpSymbol(std::string symbolName) {
    if (symbolTable.count(symbolName)) {
        return symbolTable[symbolName];
    }
    return parentBlock ? parentBlock->lookUpSymbol(symbolName) : nullptr;
}

FuncSymbolInfo * BlockInfo::lookUpFunc(std::string symbolName) {
    if (parentBlock || belongTo) {
        throw std::runtime_error("cannot find func here");
    }

    if (funcTable.count(symbolName)) {
        auto * func = funcTable[symbolName];
        if (func->getSymbolType() != SymbolType::FUNC) {
            throw std::runtime_error("this is not a func");
        }
        return func;
    }
    return nullptr;
}

// ------------------ Symbol Add --------------------

#define DUP_CHECK(tbl, name) \
    if (tbl.count(name)) { throw std::runtime_error("duplicate name of symbol"); return nullptr; }

ConstSymbolInfo * BlockInfo::addNewConst(const std::string & name, DataType type) {
    DUP_CHECK(symbolTable, name);
    auto * sym = new ConstSymbolInfo(name, type);
    symbolTable[name] = sym;
    return sym;
}

VarSymbolInfo * BlockInfo::addNewVar(const std::string & name, DataType type) {
    DUP_CHECK(symbolTable, name);
    auto * sym = new VarSymbolInfo(name, type);
    symbolTable[name] = sym;
    return sym;
}

ConstArraySymbolInfo * BlockInfo::addNewConstArray(const std::string & name, DataType type, int size) {
    DUP_CHECK(symbolTable, name);
    auto * sym = new ConstArraySymbolInfo(name, type, size);
    symbolTable[name] = sym;
    return sym;
}

VarArraySymbolInfo * BlockInfo::addNewVarArray(const std::string & name, DataType type, int size) {
    DUP_CHECK(symbolTable, name);
    auto * sym = new VarArraySymbolInfo(name, type, size);
    symbolTable[name] = sym;
    return sym;
}

FuncSymbolInfo * BlockInfo::addNewFunc(const std::string & name, DataType retType) {
    if (parentBlock || belongTo) {
        throw std::runtime_error("cannot declare a function in other function or block");
    }
    if (funcTable.count(name)) {
        throw std::runtime_error("duplicate name of function");
    }
    auto * fn = new FuncSymbolInfo(name, retType);
    funcTable[name] = fn;
    return fn;
}

// ------------------ Block Add --------------------

BlockInfo * BlockInfo::addNewBlock(FuncSymbolInfo * func) {
    auto * blk = new BlockInfo(this, func, func->getparamList());
    blockTable.push_back(blk);
    return blk;
}

BlockInfo * BlockInfo::addNewBlock() {
    auto * blk = new BlockInfo(this);
    blockTable.push_back(blk);
    return blk;
}

// ------------------ BlockInfo Constructors --------------------

BlockInfo::BlockInfo(BlockInfo * parent)
    : parentBlock(parent), belongTo(nullptr) {}

BlockInfo::BlockInfo(BlockInfo * parent, FuncSymbolInfo * owner, const std::vector<SymbolInfo *> & params)
    : parentBlock(parent), belongTo(owner) {
    for (auto * p : params) {
        const auto & pname = p->getName();
        if (symbolTable.count(pname)) {
            throw std::runtime_error("dupliacte name of parameters");
        }
        symbolTable[pname] = p;
    }
}
