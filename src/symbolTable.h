#pragma once

#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "CACT.h"

std::string ToString(DataType x);
int SizeOfDataType(DataType x);

class IROperand;

class SymbolInfo {
private:
    std::string name;
    IROperand* operand;

public:
    std::string getName();
    void setOp(IROperand* op);
    IROperand* getOp();

    virtual DataType getDataType() = 0;
    virtual int getArraySize() = 0;
    virtual SymbolType getSymbolType() = 0;

    SymbolInfo(const std::string& name);
};

class ConstSymbolInfo : public SymbolInfo {
private:
    DataType dataType; 

public:
    virtual DataType getDataType() { return dataType; }
    virtual int getArraySize() { return -1; }
    virtual SymbolType getSymbolType() { return SymbolType::CONST; }

    ConstSymbolInfo(const std::string& name, DataType dataType);
};

class VarSymbolInfo : public SymbolInfo {
private:
    DataType dataType;

public:
    virtual DataType getDataType() { return dataType; }
    virtual int getArraySize() { return -1; }
    virtual SymbolType getSymbolType() { return SymbolType::VAR; }

    VarSymbolInfo(const std::string& name, DataType dataType);
};

class ConstArraySymbolInfo : public SymbolInfo {
private:
    DataType dataType;
    int arraySize;

public:
    virtual DataType getDataType() { return dataType; }
    virtual int getArraySize() { return arraySize; }
    virtual SymbolType getSymbolType() { return SymbolType::CONST_ARRAY; }

    ConstArraySymbolInfo(const std::string& name, DataType dataType, int arraySize);
};

class VarArraySymbolInfo : public SymbolInfo {
private:
    DataType dataType;
    int arraySize;

public:
    virtual DataType getDataType() { return dataType; }
    virtual int getArraySize() { return arraySize; }
    virtual SymbolType getSymbolType() { return SymbolType::VAR_ARRAY; }

    VarArraySymbolInfo(const std::string& name, DataType dataType, int arraySize);
};

class BlockInfo;

class FuncSymbolInfo : public SymbolInfo {
private:
    DataType returnType;
    std::vector<SymbolInfo*> paramList;
    BlockInfo* blockInfo;

public:
    virtual DataType getDataType() { return returnType; }
    virtual int getArraySize() { return paramList.size(); }
    virtual SymbolType getSymbolType() { return SymbolType::FUNC; }
    std::vector<SymbolInfo*> getparamList() { return paramList; }
    int getparamNum() { return paramList.size(); }

    SymbolInfo* addParamVar(const std::string& name, DataType dataType);
    SymbolInfo* addParamArray(const std::string& name, DataType dataType);

    FuncSymbolInfo(const std::string& name, DataType returnType);
};

class BlockInfo {
public:
    BlockInfo* getParentBlock() { return parentBlock; }
    SymbolInfo* lookUpSymbol(std::string symbolName);
    FuncSymbolInfo* lookUpFunc(std::string symbolName);

    ConstSymbolInfo* addNewConst(const std::string& name, DataType dataType);
    VarSymbolInfo* addNewVar(const std::string& name, DataType dataType);
    ConstArraySymbolInfo* addNewConstArray(const std::string& name, DataType dataType, int arraySize);
    VarArraySymbolInfo* addNewVarArray(const std::string& name, DataType dataType, int arraySize);

    FuncSymbolInfo* addNewFunc(const std::string& name, DataType returnType);

    BlockInfo* addNewBlock();
    BlockInfo* addNewBlock(FuncSymbolInfo* belongTo);

    BlockInfo(BlockInfo* parentBlock);
    BlockInfo(BlockInfo* parentBlock, FuncSymbolInfo* belongTo, const std::vector<SymbolInfo*>& paramList);
private:
    BlockInfo* parentBlock;
    FuncSymbolInfo* belongTo;
    std::map<std::string, SymbolInfo*> symbolTable;
    std::map<std::string, FuncSymbolInfo*> funcTable;
    std::vector<BlockInfo*> blockTable;


};
