  @n = common global i32 0, align 4
  @sum = common global i32 0, align 4
define i32 @main #0() {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 10, i32* @n, align 4
  store i32 0, i32* @sum, align 4
  br label %2

  ; <label>:2:
  %3 = load i32, i32* @n, align 4
  br label i1 %0, label %1, label %1

  ; <label>:4:
  %5 = load i32, i32* @sum, align 4
  %6 = load i32, i32* @n, align 4
  %7 = add nsw i32 %5, %6, align 4
  store i32 %7, i32* @sum, align 4
  %8 = load i32, i32* @n, align 4
  %9 = sub nsw i32 %8, 1, align 4
  store i32 %9, i32* @n, align 4
}
