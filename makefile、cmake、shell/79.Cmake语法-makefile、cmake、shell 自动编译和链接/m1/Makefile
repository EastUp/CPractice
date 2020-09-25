# 怎么写？
# 一个规则
# a.out:a.c
#	gcc a.c -o a.out
# 两个函数

# 三个自动变量

# 生成 hello.out 


# 默认情况下只会执行第一个
hello.out:hello.o sub.o add.o div.o
	gcc hello.o sub.o add.o div.o -o hello.out

div.o:div.cpp
	gcc -c div.cpp -o div.o

add.o:add.cpp
	gcc -c add.cpp -o add.o

sub.o:sub.cpp
	gcc -c sub.cpp -o sub.o

hello.o:hello.cpp
	gcc -c hello.cpp -o hello.o
