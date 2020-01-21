  @n = common global i32 0, align 4
  @x = common global i32 0, align 4
define void @prime #0() {
  %1 = alloca i32, align 4
  %3 = load i32, i32* @x, align 4
  %4 = sdiv nsw i32 %3, 2, align 4
  store i32 %4, i32* %1, align 4
  br label %5

  ; <label>:5:
  %6 = load i32, i32* @x, align 4
  %7 = load i32, i32* @x, align 4
  %8 = sdiv nsw i32 %7, %1, align 4
  %9 = mul nsw i32 %8, %1, align 4
  %10 = icmp ne i32 %6, %9, align 4
  br label i1 %10, label %11, label %13

  ; <label>:11:
  %12 = sub nsw i32 %1, 1, align 4
  store i32 %12, i32* %1, align 4
  br label %5

  ; <label>:13:
  %14 = icmp eq i32 %1, 1, align 4
  br label i1 %14, label %15, label %16

  ; <label>:15:
  br label %16

  ; <label>:16:
}

define i32 @main #0() {
  %1 = alloca i32, align 4
  store i32 0, i32* %2, align 4
  %3 = alloca i32, align 4
  br label %4

  ; <label>:4:
  %5 = load i32, i32* @n, align 4
  %6 = icmp sle i32 1, %5, align 4
  br label i1 %6, label %7, label %11

  ; <label>:7:
  %8 = load i32, i32* @n, align 4
  store i32 %8, i32* @x, align 4
  %9 = load i32, i32* @n, align 4
  %10 = sub nsw i32 %9, 1, align 4
  store i32 %10, i32* @n, align 4
  br label %4

  ; <label>:11:
  ret %1
}
