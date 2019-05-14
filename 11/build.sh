#!/bin/bash
rm -rf out
rm -rf dist
mkdir dist out
clang -lm -std=c11 -Wall -Wextra -Wpedantic -save-temps=obj -o out/main.out src/main.c
clang-format -i src/*.c
clang-tidy src/*.c
mv out/main.out dist
