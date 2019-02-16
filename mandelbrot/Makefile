export EMCC_DEBUG=1

mandelbrot.js: mandelbrot.cxx
	em++ --bind --std=c++11 mandelbrot.cxx -s WASM=1 -s ALLOW_MEMORY_GROWTH=1 -o mandelbrot.js

clean:
	rm *.js *.wasm
