package com.east;

public class NdkSample {
    public static void main(String[] args) {
        NdkSample ndkSample = new NdkSample();

        String signaturePassword = ndkSample.getSingnaturePassword();

        System.out.println("秘钥 = "+signaturePassword);
    }

    // 定义好本地的 native 方法
    public static native String getSingnaturePassword();

    static{
        // 引入加载我们的动态库
        // System.loadLibrary ：android 加载apk中的libs目录下 .so 库
        // System.load : 加载一个具体路径上的 .so 库，去服务器上下载再进行加载(data/data)
        System.load("E:\\VSProjects\\07Jni\\x64\\Debug\\07Jni.dll");
    }
}
