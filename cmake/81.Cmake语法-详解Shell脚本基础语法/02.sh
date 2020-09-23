# 变量设置规则
# 1. 命名跟Java规范一样
# 2. shell 中默认都是字符串类，如果需要用到其他类型，需要额外处理
# 3. 变量用等号连接，千万注意不能有空格
# 4. 变量的值如果有空格，需要用单引号或者双引号包括

str1="str1"  
str2=str2
str3=3
str4="Hello Shell"

# 重新赋值
str4=str4

# $取变量的值
echo "str1 = $str1"
echo "str2 = $str2"
echo "str3 = $str3"
echo "str4 = $str4"

#输出环境变量
echo "CMAKE_PATH = ${CMAKE_PATH}"

#指定一个命令的执行结果返回给变量
#soPath=$(pwd)
soPath=`pwd`
echo "soPath = ${soPath}"

