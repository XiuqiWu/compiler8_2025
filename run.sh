#!/bin/bash

# 清理构建目录
echo "步骤 1/7: 清理旧构建文件..."
rm -rf build

# 创建构建目录
echo "步骤 2/7: 创建构建目录..."
mkdir build || { echo "创建 build 目录失败"; exit 1; }

# 进入构建目录
echo "步骤 3/7: 进入 build 目录..."
cd build || { echo "进入 build 目录失败"; exit 1; }

# 运行 CMake
echo "步骤 4/7: 运行 CMake..."
cmake .. || { echo "CMake 配置失败"; exit 1; }

# 编译项目
echo "步骤 5/7: 编译项目 (使用 8 个线程)..."
make -j8 || { echo "编译失败"; exit 1; }

# 返回上级目录
echo "步骤 6/7: 返回项目根目录..."
cd .. || { echo "返回项目根目录失败"; exit 1; }

# 运行功能测试
echo "步骤 7/7: 运行功能测试..."
./batch_functional.sh || { echo "功能测试失败"; exit 1; }

# 运行 s.sh
echo "运行最终测试..."
./s.sh || { echo "最终测试失败"; exit 1; }

echo "========================================"
echo "所有步骤已完成！"
echo "========================================"