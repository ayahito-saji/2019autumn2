  @x = common global i32 0, align 4
define i32 @main #0() {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = load i32, i32* @x, align 4
  %3 = icmp eq i32 %2, 0, align 4
  br label i1 %3, label %4, label %1

  ; <label>:4:
  store i32 1, i32* @x, align 4
  br label %5

  ; <label>:5:
}
