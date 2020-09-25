#!/bin/bash

# 输出错误日志，输出日志，输出配置文件

# 永久重定向  echo 标准输入：0 标准输出：1 标准错误：2
exec 1>log.txt
exec 2>>log.txt
# >> 代表追加，> 代表重新生成
# 临时重定向
# echo "Hello Shell!" > log.txt   
# echo "Hello Shell!" >> log.txt   

echo "Hello Shell"
echo "Hello Shell"
echo "Hello Shell"

ll xx

