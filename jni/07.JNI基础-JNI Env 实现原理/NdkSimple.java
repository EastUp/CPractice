package com.darren.ndk12;

public class NdkSimple {

	public static void main(String[] args) {
		NdkSimple ndkSimple = new NdkSimple();
		
		String signaturePassword = ndkSimple.getSingnaturePassword();
		
		System.out.println("��Կ = "+signaturePassword);
	}
	
	// ����ñ��ص� native ����
	public static native String getSingnaturePassword();
	
	static{
		// ����������ǵĶ�̬�� 
		// System.loadLibrary ��android ����apk�е�libsĿ¼�� .so ��
		// System.load : ����һ������·���ϵ� .so �⣬ȥ�������������ٽ��м���(data/data)
		System.load("C:/Users/hcDarren/Desktop/android/NDK/NDK_Day12/x64/Debug/NDK_Day12.dll");
	}
}
