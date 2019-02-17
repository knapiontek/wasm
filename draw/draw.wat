(module
  (type (;0;) (func (param f32)))
  (type (;1;) (func (param i32)))
  (type (;2;) (func))
  (type (;3;) (func (param i32 i32 i32 i32)))
  (import "env" "__linear_memory" (memory (;0;) 0))
  (import "env" "__indirect_function_table" (table (;0;) 0 anyfunc))
  (import "env" "js_func" (func (;0;) (type 1)))
  (import "env" "js_draw_begin" (func (;1;) (type 2)))
  (import "env" "js_draw_line" (func (;2;) (type 3)))
  (import "env" "js_draw_end" (func (;3;) (type 2)))
  (func (;4;) (export "cxx_func") (type 0) (param f32)
    (local i32)
    i32.const 667
    call 0
    block  ;; label = @1
      block  ;; label = @2
        local.get 0
        f32.abs
        f32.const 0x1p+31 (;=2.14748e+09;)
        f32.lt
        br_if 0 (;@2;)
        i32.const -2147483648
        local.set 1
        br 1 (;@1;)
      end
      local.get 0
      i32.trunc_f32_s
      local.set 1
    end
    local.get 1
    call 0
    local.get 1
    call 0
    i32.const 1000
    call 0
    i32.const 1001
    call 0
    i32.const 1002
    call 0
    i32.const 1003
    call 0
    i32.const 1004
    call 0
    i32.const 1005
    call 0
    i32.const 1006
    call 0
    i32.const 1007
    call 0
    i32.const 1008
    call 0
    i32.const 1009
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
