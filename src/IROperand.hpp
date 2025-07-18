// IROperand.hpp
#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "CACT.h"
#include "symbolTable.h"

// TargetCodeList class definition and implementation
class TargetCodeList {
private:
    std::vector<std::string> list;

    int countParamX = 0;
    int countParamF = 0;
    int countGetParamX = 0;
    int countGetParamF = 0;

public:
    void add(std::string code) {
        list.push_back(code);
    }

    friend std::ostream& operator<<(std::ostream& os, const TargetCodeList& obj) {
        for (auto code : obj.list) {
            os << code << std::endl;
        }
        return os;
    }

    std::string getRegParamX() {
        std::string name = std::string("a") + std::to_string(countParamX);
        countParamX += 1;
        return name;
    }

    std::string getRegParamF() {
        std::string name = std::string("fa") + std::to_string(countParamF);
        countParamF += 1;
        return name;
    }

    void resetRegParam() {
        countParamX = 0;
        countParamF = 0;
    }

    std::string getRegGetParamX() {
        std::string name = std::string("a") + std::to_string(countGetParamX);
        countGetParamX += 1;
        return name;
    }

    std::string getRegGetParamF() {
        std::string name = std::string("fa") + std::to_string(countGetParamF);
        countGetParamF += 1;
        return name;
    }
};

enum MemBase { STACK,DATA,RODATA};

class IROperand {
public:
    virtual ~IROperand() {}

    virtual bool isVariable() = 0;
    virtual void setName(std::string) = 0;
    virtual std::string getName() = 0;
    virtual int getSize() = 0;

    virtual std::string getImme() = 0;
    virtual void alloc(TargetCodeList* t) = 0;
    virtual void loadTo(TargetCodeList* t, std::string reg) = 0;
    virtual void storeFrom(TargetCodeList* t, std::string reg) = 0;
    virtual void loadAddrTo(TargetCodeList* t, std::string reg) = 0;
};

/* =========================
         IRLabel
   ========================= */
class IRLabel : public IROperand {
private:
    std::string name;

public:
    IRLabel(std::string newName) : name(newName) {}

    bool isVariable() override { return true; }
    void setName(std::string newName) override { name = newName; }
    std::string getName() override { return name; }
    int getSize() override { return 0; }

    std::string getImme() override { return name; }

    void alloc(TargetCodeList* t) override {
        // labels do not allocate space
    }

    void loadTo(TargetCodeList* t, std::string reg) override {
        throw std::runtime_error("target gen: label is not allowed to loadTo");
    }

    void storeFrom(TargetCodeList* t, std::string reg) override {
        throw std::runtime_error("target gen: label is not allowed to storeFrom");
    }

    void loadAddrTo(TargetCodeList* t, std::string reg) override {
        throw std::runtime_error("target gen: label is not allowed to loadAddrTo");
    }
};

/* =========================
         IRVariable
   ========================= */
class IRVariable : public IROperand {
private:
    std::string name;
    DataType dataType;
    int length;
    int memOffset = 0;

public:
    IRVariable(std::string newName, DataType dt, int len)
        : name(newName), dataType(dt), length(len) {}
    IRVariable(std::string newName, DataType dt)
        : name(newName), dataType(dt), length(1) {}

    bool isVariable() override { return true; }
    void setName(std::string newName) override { name = newName; }
    std::string getName() override { return name; }
    int getSize() override { return SizeOfDataType(dataType) * length; }

    std::string getImme() override { return ""; }

    void alloc(TargetCodeList* t) override {
        // allocation handled by IRFunction::targetGen
    }

    void loadTo(TargetCodeList* t, std::string reg) override {
        if (dataType == INT || dataType == BOOL) {
            t->add("\tlw\t" + reg + ", " + std::to_string(getMemOff()) + "(s0)");
        } else if (dataType == FLOAT) {
            t->add("\tflw\t" + reg + ", " + std::to_string(getMemOff()) + "(s0)");
        } else if (dataType == DOUBLE) {
            t->add("\tfld\t" + reg + ", " + std::to_string(getMemOff()) + "(s0)");
        }
    }

    void storeFrom(TargetCodeList* t, std::string reg) override {
        if (dataType == INT || dataType == BOOL) {
            t->add("\tsw\t" + reg + ", " + std::to_string(getMemOff()) + "(s0)");
        } else if (dataType == FLOAT) {
            t->add("\tfsw\t" + reg + ", " + std::to_string(getMemOff()) + "(s0)");
        } else if (dataType == DOUBLE) {
            t->add("\tfsd\t" + reg + ", " + std::to_string(getMemOff()) + "(s0)");
        }
    }

    void loadAddrTo(TargetCodeList* t, std::string reg) override {
        t->add("\tli\t" + reg + ", " + std::to_string(getMemOff()));
        t->add("\tadd\t" + reg + ", " + reg + ", s0");
    }

    int getAlign() {
        return (dataType == DOUBLE) ? 3 : 2;
    }

    void setMemOff(int off) { memOffset = off; }
    int  getMemOff()        { return memOffset; }
};

/* =========================
           IRValue
   ========================= */
class IRValue : public IROperand {
private:
    std::string name;
    DataType dataType;
    bool isVar = false;
    std::vector<std::string> values;

public:
    IRValue(std::string newName, DataType newDataType)
        : name(newName), dataType(newDataType) {}

    IRValue(int newVal)
        : name(std::to_string(newVal)), dataType(INT) {
        values.emplace_back(std::to_string(newVal));
    }

    void setVariable(bool newIsVar) { isVar = newIsVar; }
    bool isVariable() override { return isVar; }
    std::string getName() override { return name; }
    void setName(std::string newName) override { name = newName; }
    int getSize() override { return SizeOfDataType(dataType) * static_cast<int>(values.size()); }

    std::string getImme() override {
        return (values.empty() || values[0].empty()) ? "0" : values[0];
    }

    void alloc(TargetCodeList* t) override {
        if ((dataType == INT || dataType == BOOL) && values.size() == 1 && !isVar) {
            // constant folded, no allocation
            return;
        }

        int size = getSize();
        t->add("\t.text");
        t->add("\t.globl\t" + name);
        t->add(isVar ? "\t.data" : "\t.section\t.rodata");
        t->add("\t.align\t3");
        t->add("\t.type\t" + name + ", @object");
        t->add("\t.size\t" + name + ", " + std::to_string(size));
        t->add(name + ":");

        std::string type;
        switch (dataType) {
            case BOOL:
            case INT:   type = ".word";   break;
            case FLOAT: type = ".float";  break;
            case DOUBLE:type = ".double"; break;
            default:    type = ".zero";   break;
        }

        for (const std::string& v : values) {
            if (v.empty()) {
                t->add("\t.zero\t" + std::to_string(size));
                break;
            }
            t->add("\t" + type + "\t" + v);
            size -= SizeOfDataType(dataType);
        }
    }

    void loadTo(TargetCodeList* t, std::string reg) override {
        if (values.size() != 1)
            throw std::runtime_error("only single-value IRValue can load to reg");

        if (dataType == INT || dataType == BOOL) {
            if (isVar) {
                t->add("\tlui\tt1, %hi(" + name + ")");
                t->add("\tlw\t" + reg + ", %lo(" + name + ")(t1)");
            } else {
                t->add("\tli\t" + reg + ", " + getImme());
            }
        } else if (dataType == FLOAT) {
            t->add("\tlui\tt1, %hi(" + name + ")");
            t->add("\tflw\t" + reg + ", %lo(" + name + ")(t1)");
        } else if (dataType == DOUBLE) {
            t->add("\tlui\tt1, %hi(" + name + ")");
            t->add("\tfld\t" + reg + ", %lo(" + name + ")(t1)");
        }
    }

    void storeFrom(TargetCodeList* t, std::string reg) override {
        if (values.size() != 1)
            throw std::runtime_error("only single-value IRValue can store from reg");
        if (!isVar)
            throw std::runtime_error("cannot store to const");

        if (dataType == INT || dataType == BOOL) {
            t->add("\tlui\tt1, %hi(" + name + ")");
            t->add("\tsw\t" + reg + ", %lo(" + name + ")(t1)");
        } else if (dataType == FLOAT) {
            t->add("\tlui\tt1, %hi(" + name + ")");
            t->add("\tfsw\t" + reg + ", %lo(" + name + ")(t1)");
        } else if (dataType == DOUBLE) {
            t->add("\tlui\tt1, %hi(" + name + ")");
            t->add("\tfsd\t" + reg + ", %lo(" + name + ")(t1)");
        }
    }

    void loadAddrTo(TargetCodeList* t, std::string reg) override {
        t->add("\tlui\t" + reg + ", %hi(" + name + ")");
        t->add("\taddi\t" + reg + ", " + reg + ", %lo(" + name + ")");
    }

    void addValue(std::string newValue) { values.push_back(newValue); }

    std::string getValue(int x) {
        if (x >= static_cast<int>(values.size()))
            throw std::runtime_error("irGen: wrong index");
        return values[x];
    }

    std::vector<std::string> getValue() { return values; }

    void fillValue(int len) {
        while (static_cast<int>(values.size()) < len) values.emplace_back("");
    }
};