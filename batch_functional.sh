#!/bin/bash

SRC_DIR="test/functional"
OUT_DIR="out/functional"
COMPILER="build/compiler"  

mkdir -p "$OUT_DIR"
for i in $(seq -w 0 32); do
    SRC_FILE="$SRC_DIR/$i.cact"
    OUT_FILE="$OUT_DIR/$i.s"

    if [ -f "$SRC_FILE" ]; then
        echo "Compiling $SRC_FILE -> $OUT_FILE"
        $COMPILER "$SRC_FILE" "$OUT_FILE"  # 使用修正后的路径

        if [ $? -ne 0 ]; then
            echo " Compilation failed: $SRC_FILE"
        else
            echo "Output written to $OUT_FILE"
        fi
    else
        echo " Source file not found: $SRC_FILE"
    fi
done
