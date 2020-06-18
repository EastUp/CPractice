package com.east.jni07;

import java.util.UUID;

public class NdkSample1 {
    public String name = "East"; // name = Jack

    public static int age = 25; // 25 + 12

    public int add(int number1,int number2){
        return number1 + number2;
    }

    // 小小的思考：静态获取 uuid 的方法，然后再 c 调用这个方法获取uuid
    public static String getUUID(){
        return UUID.randomUUID().toString();
    }

    public static void main(String[] args) {
        NdkSample1 ndkSample1 = new NdkSample1();

        /*System.out.println("修改前："+ndkSample1.name);
        ndkSample1.changeName();
        System.out.println("修改后："+ndkSample1.name);*/

        /*System.out.println("修改前："+NdkSample1.age);
        ndkSample1.changeAge();
        System.out.println("修改后："+NdkSample1.age);*/

        ndkSample1.callAddMethod();
    }

    // 改变普通属性
    public native void changeName();
    // 改变静态属性
    public static native void changeAge();

    // c 调用 java 方法
    public native void callAddMethod();

    static{
        // 引入加载我们的动态库
        // System.loadLibrary : android 加载 apk中libs目录下的 .so 文件
        // System.load：加载一个具体路径上的 .so 库，去服务器上下载再进行加载（data/data）
        System.load("E:\\VSProjects\\07Jni\\x64\\Debug\\07Jni.dll");
    }
}
