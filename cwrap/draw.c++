#include <emscripten/emscripten.h>
#include <stdlib.h>

extern "C" {

int EMSCRIPTEN_KEEPALIVE cxx_func(int i) {
    return (int)malloc(i);
}

}
