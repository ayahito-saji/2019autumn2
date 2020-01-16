  @n = common global i32 0, align 4
  @x = common global i32 0, align 4
  @i = common global i32 0, align 4
define void @prime #0() {
  %1 = alloca i32, align 4
  %2 = load i32, i32* @x, align 4
  %3 = sdiv nsw i32 %2, 2, align 4
  store i32 %3, i32* %1, align 4
  br label %4

  ; <label>:4:
  %5 = load i32, i32* @x, align 4
  %6 = load i32, i32* @x, align 4
  %7 = sdiv nsw i32 %6, %1, align 4
  %8 = mul nsw i32 %7, %1, align 4
  %9 = icmp ne i32 %5, %8, align 4
  br label i1 %9, label %10, label %12

  ; <label>:10:
  %11 = sub nsw i32 %1, 1, align 4
  store i32 %11, i32* %1, align 4
  br label %4

  ; <label>:12:
  %13 = icmp eq i32 %1, 1, align 4
  br label i1 %13, label %14, label %1

  ; <label>:14:
  br label %15

  ; <label>:15:
}

define i32 @main #0() {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 @i, i32* 2, align 4
  br label %2

  ; <label>:2:
  %3 = load i32, i32* @i, align 4
  %4 = load i32, i32* @n, align 4
  %5 = icmp sle i32 %3, %4, align 4
  br label i1 %5, label %6, label %10

  ; <label>:6:
  %7 = load i32, i32* @i, align 4
  store i32 %7, i32* @x, align 4
  %8 = load i32, i32* @i, align 4
  %9 = add nsw i32 %8, 1, align 4
  store i32 @i, i32* %9, align 4
  br label %2

  ; <label>:10:
  ret %1
}
