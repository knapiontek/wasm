#include "emscripten.h"

extern "C" {

extern void js_func(int);
extern void js_draw_line(int, int, int, int);

void EMSCRIPTEN_KEEPALIVE cxx_func(void) {
  js_func(667);
  js_draw_line(50, 50, 150, 150);
}

}

