
#include <stdlib.h>

#define EXPORT_API __attribute__((visibility("default")))

extern "C" {

extern void js_func(int);
extern void js_draw_begin();
extern void js_draw_end();
extern void js_draw_line(int, int, int, int);

EXPORT_API void cxx_func(float f) {
  js_func(667);

  int* mem = (int*)malloc(1000000*f);
  *(mem+1000) = int(f);
  js_func(*(mem+1000));
  js_func(*(mem+1001));

  *(mem+1999) = 999;
  for(int i = 2000; i < 2010; i++) {
    mem[i] = mem[i-1] + 1;
    js_func(mem[i]);
  }
  free(mem);

  js_draw_begin();
  js_draw_line(50, 50, 50, 100);
  js_draw_line(50, 100, 150, 100);
  js_draw_end();
}

}
