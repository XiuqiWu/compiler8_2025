# CACT compile

## 零、 运行
```bash
grammar目录下：
java -jar ../deps/antlr-4.13.1-complete.jar -Dlanguage=Cpp CACT.g4 -no-visitor -listener
```

```bash
根目录下：
./run.sh
输出到out目录下
```


## 一、项目概述

本项目实现了一个编译器的核心部分。

## 二、主要功能模块

### 1. 语义分析

- 语义分析的主要实现文件为 `SemanticAnalysis.cpp` 和 `semanticAnalysis.h`。
- 该模块负责对源程序进行语义检查，包括变量声明、类型检查、作用域管理、函数调用等。
- 通过符号表（`symbolTable.cpp` 和 `symbolTable.h`）管理变量和函数的作用域与类型信息，确保程序的语义正确性。
- 语义分析阶段能够有效捕捉诸如未声明变量、类型不匹配、重复定义等常见语义错误。

### 2. 中间代码生成

- 中间代码生成的主要实现文件为 `IRGenerator.cpp`、`IRGenerator.h`、`IRCode.cpp`、`IRCode.h`、`IR.cpp`、`IR.h` 以及 `IROperand.hpp`。
- 该模块在语法分析和语义分析的基础上，将源程序转换为中间表示（IR, Intermediate Representation）。
- IR设计为三地址码形式，便于后续优化和目标代码生成。
- 支持表达式求值、条件跳转、函数调用、参数传递等多种语句和表达式的中间代码生成。

### 3. RISC-V汇编代码生成

- 在中间代码生成的基础上，进一步将IR翻译为RISC-V汇编代码。
- 汇编代码生成过程主要在 `IRCode.cpp`、`IRCode.h` 等文件中实现。
- 生成的RISC-V汇编代码可直接用于RISC-V架构的模拟器或硬件平台进行测试和运行。
- 支持基本的算术运算、条件跳转、函数调用、内存访问等指令的生成。

## 三、项目结构

- `SemanticAnalysis.cpp` / `semanticAnalysis.h`：语义分析相关实现与接口。
- `symbolTable.cpp` / `symbolTable.h`：符号表管理。
- `IRGenerator.cpp` / `IRGenerator.h`：中间代码生成器。
- `IRCode.cpp` / `IRCode.h`：中间代码及其到汇编的转换。
- `IR.cpp` / `IR.h`、 `IROperand.hpp `  ： 中间代码及操作数的定义。
- `main.cpp`：主程序入口，负责编译流程的调度。

## 四、实现成效

- 已实现完整的语义分析，能够检测并报告常见语义错误。
- 成功生成类llvm-ir的三地址码形式的中间代码，便于后续优化和目标代码生成。
- 能够将中间代码正确翻译为RISC-V汇编代码，支持基本的程序运行需求。
-使用riscv64-linux-gnu-gcc交叉编译，qemu运行，通过样例28/32.

## 五、后续展望

- 可以进一步完善优化中间代码和汇编代码的生成效率。
- 增加更多高级语言特性的支持。
```
