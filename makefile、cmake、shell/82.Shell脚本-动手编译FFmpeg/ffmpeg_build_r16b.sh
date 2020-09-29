# 这个脚本使用于在linux上的ndkr16以上ndkr17以下
#环境：ndkr16,ffmpeg-3.3.9
# 用于编译 android 平台的脚本
#!/bin/bash
#./etc/profile

# 定义几个变量
NDK_PATH=/lib/ndk/android-ndk-r16b
ARCH=arm
CPU=armv7-a
MARCH=armv7-a
API=21
PREFIX=$(pwd)/android/$ARCH/$CPU
TOOLCHAIN=$NDK_PATH/android-toolchains/android-19/arch-arm
CROSS_PREFIX=$TOOLCHAIN/bin/arm-linux-androideabi-
SYSROOT=$TOOLCHAIN/sysroot
CFLAG="-D__ANDROID_API__=$API -Os -fPIC -DANDROID "
LDFLAG="-lc -lm -ldl -llog "
 build(){
    echo "start build ffmpeg for $ARCH"
    ./configure --target-os=linux \
    --prefix=$PREFIX --arch=$ARCH \
    --disable-doc \
    --enable-shared \
    --disable-static \
    --disable-yasm \
    --disable-asm \
    --disable-symver \
    --enable-gpl \
    --disable-ffmpeg \
    --disable-ffplay \
    --disable-ffprobe \
    --disable-ffserver \
    --cross-prefix=$CROSS_PREFIX \
    --enable-cross-compile \
    --sysroot=$SYSROOT \
    --enable-small \
    --extra-cflags="$CFLAG -mfloat-abi=softfp -mfpu=vfp -marm -march=$MARCH" \
    --extra-ldflags="$LDFLAG" \

    make clean
    make
    make install
    echo "build ffmpeg for $ARCH finished"
}



# 执行 build 函数
build

# 下面需要再编译其他的
# 需要重新设置参数
# CPU=NAME
# build





