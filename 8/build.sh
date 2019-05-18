#!/bin/bash
rm -rf out
rm -rf dist
mkdir dist out
clang++ -lm -std=c++11 -Wall -Wextra -Wpedantic -save-temps=obj -o out/main.out src/main.cpp
clang-format -i src/*.cpp
clang-tidy src/*.cpp
mv out/main.out dist
