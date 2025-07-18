#!/bin/bash
RT_C="../../runtime.c"

cd out/functional
mkdir -p bin log

compile_fail_count=0

for i in $(seq -w 0 31); do
    input="${i}.s"
    elf="./bin/${i}.elf"
    infile="../../compiler/test/functional/${i}.in"   # ← 根据实际路径调整

    echo ">>> 编译 $input"
    riscv64-linux-gnu-gcc -static -o "$elf" "$input" "$RT_C" 2>> log/compile_errors.txt
    if [ $? -ne 0 ]; then
        echo "[ERROR] 编译失败: $input" | tee -a log/result.txt
        ((compile_fail_count++))
        continue
    fi

    echo ">>> 运行 $elf"
    if [ -f "$infile" ]; then
        # 有 .in 文件就喂进去
        qemu-riscv64 "$elf" < "$infile" > "log/${i}.log" 2>&1
    else
        # 没有就给它空输入
        echo "" | qemu-riscv64 "$elf" > "log/${i}.log" 2>&1
    fi
    echo $? > "log/${i}.ret"
done

echo "===== 编译失败总数: $compile_fail_count ====="