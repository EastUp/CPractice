# 怎么写？
# 一个规则
# a.out:a.c
#	gcc a.c -o a.out

# 两个函数
# src = $(wildcard *.cpp)
# obj = $(patsubst %cpp,%o,$(src))

# 三个自动变量

# 生成 hello.out 

src = $(wildcard *.cpp)
obj = $(patsubst %cpp,%o,$(src))

# 默认情况下只会执行第一个
hello.out:$(obj)
	gcc $(obj) -o hello.out

div.o:div.cpp
	gcc -c div.cpp -o div.o

add.o:add.cpp
	gcc -c add.cpp -o add.o

sub.o:sub.cpp
	gcc -c sub.cpp -o sub.o

hello.o:hello.cpp
	gcc -c hello.cpp -o hello.o


# $(xxx) 取变量的值
clean:
	rm -rf $(obj) hello.out	

# 生成伪目标
.PHONY: clean





