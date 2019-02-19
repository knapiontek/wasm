(module
  (type (;0;) (func (param f32 i32)))
  (type (;1;) (func (param f32)))
  (type (;2;) (func))
  (type (;3;) (func (param i32 i32 i32 i32)))
  (import "env" "__linear_memory" (memory (;0;) 0))
  (import "env" "__indirect_function_table" (table (;0;) 0 anyfunc))
  (import "env" "js_func" (func (;0;) (type 1)))
  (import "env" "js_draw_begin" (func (;1;) (type 2)))
  (import "env" "js_draw_line" (func (;2;) (type 3)))
  (import "env" "js_draw_end" (func (;3;) (type 2)))
  (func (;4;) (export "cxx_func") (type 0) (param f32 i32)
    f32.const 0x1.4d8p+9 (;=667;)
    call 0
    local.get 0
    call 0
    local.get 0
    local.get 0
    f32.add
    call 0
    call 1
    i32.const 50
    i32.const 50
    i32.const 50
    i32.const 100
    call 2
    i32.const 50
    i32.const 100
    i32.const 150
    i32.const 100
    call 2
    call 3))
