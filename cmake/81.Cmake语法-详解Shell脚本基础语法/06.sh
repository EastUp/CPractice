#!/bin/bash

# 函数需要先定义再使用
# 可以直接采用方法名调用
function error(){
	echo "usage：./build_ogre.sh [build_type]"
        echo "build_type: Release or Debug (must have)"
	# 函数需要穿参数 arm $1 参数不是代表的脚本参数，而是方法传递过来的参数 
	echo "\$1 = $1"
        exit
}

# 判断有没有输入
if [ -z $1 ]
then
	# echo "usage：./build_ogre.sh [build_type]"
        # echo "build_type: Release or Debug (must have)"
	# exit
	error
fi

# 需要用户去指定编译 Debug 还是 Release
CMAKE_BUILD_TYPE=""
if [ "Debug" = $1 ]; then
	CMAKE_BUILD_TYPE="Debug"
elif [ "Release" = $1 ]; then
	CMAKE_BUILD_TYPE="Release"
else
	error arm
fi

echo "start build ogre $CMAKE_BUILD_TYPE"


echo "=========================================="
for((i=0;i<10;i++))
do
echo $i
done

echo "=========================================="
sum=0
i=1
while(($i<=100))
do
	sum=$(($sum+$i))
	i=$(($i+1))
done
echo "sum = $sum"

echo "=========================================="
case $2 in
start)
	echo "start service"
	;;
stop)
	echo "stop service"
	;;
*)
	echo "invalid command"
	echo "Usage:{start|stop}"
esac		






















