package com.darren.ndk12;

public class NdkSimple {

	public static void main(String[] args) {
		NdkSimple ndkSimple = new NdkSimple();
		
		String signaturePassword = ndkSimple.getSingnaturePassword();
		
		System.out.println("秘钥 = "+signaturePassword);
	}
	
	// 定义好本地的 native 方法
	public static native String getSingnaturePassword();
	
	static{
		// 引入加载我们的动态库 
		// System.loadLibrary ：android 加载apk中的libs目录下 .so 库
		// System.load : 加载一个具体路径上的 .so 库，去服务器上下载再进行加载(data/data)
		System.load("C:/Users/hcDarren/Desktop/android/NDK/NDK_Day12/x64/Debug/NDK_Day12.dll");
	}
}
