  @n = common global i32 0, align 4
  @x = common global i32 0, align 4
define i32 @prime #0() {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = load i32, i32* @x, align 4
  %3 = sdiv nsw i32 %2, 2, align 4
  store i32 %3, i32* %32766, align 4
  br label %4

  ; <label>:4:
  %5 = load i32, i32* @x, align 4
  %6 = load i32, i32* @x, align 4
  %7 = load i32, i32* %32766, align 4
  %8 = sdiv nsw i32 %6, %7, align 4
  %9 = load i32, i32* %32766, align 4
  %10 = mul nsw i32 %8, %9, align 4
  %11 = icmp ne i32 %5, %10, align 4
  br label i1 %11, label %12, label %15

  ; <label>:12:
  %13 = load i32, i32* %32766, align 4
  %14 = sub nsw i32 %13, 1, align 4
  store i32 %14, i32* %32766, align 4
  br label %4

  ; <label>:15:
  %16 = load i32, i32* %32766, align 4
  %17 = icmp eq i32 %16, 1, align 4
  br label i1 %17, label %18, label %19

  ; <label>:18:
  ; <label>:19:
  ; <label>:20:
}

define i32 @main #0() {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  br label %2

  ; <label>:2:
  %3 = load i32, i32* @n, align 4
  %4 = icmp sle i32 1, %3, align 4
  br label i1 %4, label %5, label %9

  ; <label>:5:
  %6 = load i32, i32* @n, align 4
  store i32 %6, i32* @x, align 4
  %7 = load i32, i32* @n, align 4
  %8 = sub nsw i32 %7, 1, align 4
  store i32 %8, i32* @n, align 4
  br label %2

  ; <label>:9:
}
