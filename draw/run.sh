#!/bin/bash

set -x

clang++ -I /usr/include/x86_64-linux-gnu draw.c++ --compile --target=wasm32-unknown-unknown-wasm --optimize=3 --output draw.wasm -fvisibility=hidden -std=c++11
wasm2wat draw.wasm > draw.wat 
sed -i 's/(type 0) (param f32 i32)/(export "cxx_func") (type 0) (param f32 i32)/g' draw.wat 
wat2wasm draw.wat
python -m SimpleHTTPServer
