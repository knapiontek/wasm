(module
  (type $t0 (func (param i32)))
  (type $t1 (func))
  (import "env" "_js_func" (func $env._js_func (type $t0)))
  (import "env" "__memory_base" (global $env.__memory_base i32))
  (func $_cxx_func (export "_cxx_func") (type $t1)
    (call $env._js_func
      (i32.const 667)))
  (func $__post_instantiate (export "__post_instantiate") (type $t1)
    (set_global $g1
      (get_global $env.__memory_base))
    (set_global $g2
      (i32.add
        (get_global $g1)
        (i32.const 5242880))))
  (global $g1 (mut i32) (i32.const 0))
  (global $g2 (mut i32) (i32.const 0)))

