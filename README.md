# wasm

### check import - export test at:

* https://knapiontek.github.io/wasm/draw.html

### source emsdk env

```
. ~/emsdk/emsdk_env.sh --build=Release
```

### compile wasm command

```
em++ -O3 -s WASM=1 -s ONLY_MY_CODE=1 -s SIDE_MODULE=1 -o draw.wasm draw.c++
```

#### check out wasm2wat here

* https://webassembly.github.io/wabt/demo/wasm2wat/

### other compilation commands

```
clang++ -emit-llvm --target=wasm32 -Oz draw.c++ -c -o draw.bc
emcc -s WASM=1 -s ONLY_MY_CODE=1 -s EXPORTED_FUNCTIONS="['_cxx_func']" -o output.js *.c
em++ -O3 -s WASM=1 -s ONLY_MY_CODE=1 -s SIDE_MODULE=1 -s EXPORTED_FUNCTIONS="['_cxx_func']" -o draw.wasm *.c++
```

### start http server in the source folder

```
python -m SimpleHTTPServer
```

### useful links about wasm

* https://github.com/emscripten-core/emsdk
* https://github.com/mdn/webassembly-examples/tree/master/js-api-examples
* https://blog.kowalczyk.info/article/k/how-to-install-latest-clang-6.0-on-ubuntu-16.04-xenial-wsl.html
* https://developer.mozilla.org/en-US/docs/WebAssembly
* https://webassembly.github.io/wabt/demo/wasm2wat/
* https://codelabs.developers.google.com/codelabs/web-assembly-intro/#0
* https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/WebAssembly

