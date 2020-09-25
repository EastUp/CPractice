#!/bin/bash

# 条件判断 test expression 或者 []
# 测试的范围：整数，字符串，文件

# num1=1
# num2=2
# 数字计算 expr 命令，$(())
# num3=$(($num1+$num2))
# num3=`expr $num1 + $num2`

# echo "num3=$num3"

str1=darren
str2=jack
test $str1 == $str2
echo "$?"

