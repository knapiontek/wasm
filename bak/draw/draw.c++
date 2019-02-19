
#include <stdlib.h>

#define EXPORT_API __attribute__((visibility("default")))

extern "C" {

extern void js_func(float);
extern void js_draw_begin();
extern void js_draw_end();
extern void js_draw_line(int, int, int, int);

EXPORT_API void cxx_func(float f, int size) {
  js_func(667);

  float* mem = (float*)malloc(20);
  mem[0] = f;
  mem[1] = 2 * f;
  js_func(mem[0]);
  js_func(mem[1]);
  free(mem);

  js_draw_begin();
  js_draw_line(50, 50, 50, 100);
  js_draw_line(50, 100, 150, 100);
  js_draw_end();
}

}
