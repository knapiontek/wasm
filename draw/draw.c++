
#define API __attribute__((visibility("default")))

extern "C" {

extern void js_func(int);
extern void js_draw_begin();
extern void js_draw_end();
extern void js_draw_line(int, int, int, int);

API void cxx_func(void) {
  js_func(667);

  js_draw_begin();
  js_draw_line(50, 50, 50, 100);
  js_draw_line(50, 100, 150, 100);
  js_draw_end();
}

}
