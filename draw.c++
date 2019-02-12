#include "emscripten.h"

extern "C" {

extern void js_func(int i);

void EMSCRIPTEN_KEEPALIVE cxx_func(void) {
  js_func(667);
}

}

