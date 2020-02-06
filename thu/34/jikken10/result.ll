@.str.write = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
declare dso_local i32 @printf(i8*, ...)

define i32 @main() {
%1 = alloca i32, align 4
store i32 0, i32* %1, align 4
%2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.write, i64 0, i64 0), i32 8)
ret i32 0
}
