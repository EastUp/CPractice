package com.darren.ndk12;

import java.util.UUID;

public class NdkSimple1 {
	public String name = "Darren"; // name = Jack
	
	public static int age = 24;// 24 + 12
	
	public int add(int number1,int number2){
		return number1+number2;
	}
	
	// 小的思考：静态获取 uuid 的方法，然后再 c 调用这个方法获取uuid
	public static String getUUID(){
		return UUID.randomUUID().toString();
	}
	
	public static void main(String[] args) {
		NdkSimple1 ndSimple1 = new NdkSimple1();
		
		/*System.out.println("修改前："+ndSimple1.name);
		ndSimple1.changeName();
		System.out.println("修改后："+ndSimple1.name);*/
		
		
		/*System.out.println("修改前："+NdkSimple1.age);
		changeAge();
		System.out.println("修改后："+NdkSimple1.age);*/
		
		ndSimple1.callAddMathod();
	}
	// 改变我们属性
	public native void changeName();
	public static native void changeAge();
	
	// c 调用 java 方法
	public native void callAddMathod();
	
	static{
		// 引入加载我们的动态库 
		// System.loadLibrary ：android 加载apk中的libs目录下 .so 库
		// System.load : 加载一个具体路径上的 .so 库，去服务器上下载再进行加载(data/data)
		System.load("C:/Users/hcDarren/Desktop/android/NDK/NDK_Day12/x64/Debug/NDK_Day12.dll");
	}
}
