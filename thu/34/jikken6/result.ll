@i = common global i32 0, align 4
@r = common global i32 0, align 4
@.str.write = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
declare dso_local i32 @printf(i8*, ...)

define void @twice(i32) {
%2 = alloca i32, align 4
store i32 %0, i32* %2, align 4
%3 = load i32, i32* %2, align 4
%4 = load i32, i32* %2, align 4
%5 = add nsw i32 %3, %4
store i32 %5, i32* @r, align 4
ret void
}

define i32 @main() {
%1 = alloca i32, align 4
store i32 0, i32* %1, align 4
store i32 2, i32* @i, align 4
%2 = load i32, i32* @i, align 4
call void @twice(i32 %2)
%3 = load i32, i32* @r, align 4
%4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.write, i64 0, i64 0), i32 %3)
ret i32 0
}
