
#!/bin/bash

for i in $(seq -w 0 31); do
    asm_file="$i.s"
    elf_file="$i.elf"
    if [ ! -f "$asm_file" ]; then
        echo "[${i}] 未找到 $asm_file，跳过"
        continue
    fi
    echo ">>> 编译 $asm_file"
    riscv64-linux-gnu-gcc -static -o "$elf_file" "$asm_file"
    if [ ! -f "$elf_file" ]; then
        echo "[${i}] 编译失败，未生成 $elf_file"
        continue
    fi
    echo ">>> 运行 $elf_file"
    qemu-riscv64 "$elf_file"
    echo "[${i}] 返回值: $?"
done
