# 这个脚本使用于在linux上的ndkr16以上ndkr17以下
#环境：ndkr21,ffmpeg-4.3.1
# 用于编译 android 平台的脚本
#!/bin/bash
#./etc/profile

# 定义几个变量
NDK_PATH=/lib/ndk/android-ndk-r21b
ARCH=arm
CPU=armv7-a
MARCH=armv7-a
API=21
PREFIX=$(pwd)/android/$ARCH/$CPU
TARGET=armv7a-linux-androideabi
ANDROID_TOOLCHAINS_PATH=$NDK_PATH/toolchains/llvm/prebuilt/linux-x86_64
CROSS_PREFIX=$ANDROID_TOOLCHAINS_PATH/bin/arm-linux-androideabi-
SYSROOT=$ANDROID_TOOLCHAINS_PATH/sysroot
CFLAG="-D__ANDROID_API__=$API -Os -fPIC -DANDROID "
LDFLAG="-lc -lm -ldl -llog "

 build(){
	# 执行 .configure 文件
	./configure --prefix=${PREFIX} \
	--enable-gpl \
	--disable-static \
	--enable-shared \
	--enable-small \
	--disable-programs \
	--disable-ffmpeg \
	--disable-ffplay \
	--disable-ffprobe \
	--disable-symver \
	--disable-doc \
	--disable-asm \
	--arch=$ARCH \
	--cpu=$CPU \
	--cross-prefix=${CROSS_PREFIX} \
	--sysroot=$SYSROOT \
	--cc=$ANDROID_TOOLCHAINS_PATH/bin/$TARGET$API-clang \
	--cxx=$ANDROID_TOOLCHAINS_PATH/bin/$TARGET$API-clang++ \
	--enable-cross-compile \
	--target-os=android \
	--extra-cflags="$CFLAG -mfloat-abi=softfp -mfpu=vfp -marm -march=$MARCH" \
	--extra-ldflags="$LDFLAG" \
 
	# makefile 清除，就是执行了 makefile 文件里面的 clean 命令
	make clean
	# 运行 Makefile
	make
	# 安装到指定 prefix 目录下
	make install
	# make clean
}



# 执行 build 函数
build

# 下面需要再编译其他的
# 需要重新设置参数
# CPU=NAME
# build





