package com.darren.ndk12;

import java.util.UUID;

public class NdkSimple1 {
	public String name = "Darren"; // name = Jack
	
	public static int age = 24;// 24 + 12
	
	public int add(int number1,int number2){
		return number1+number2;
	}
	
	// С��˼������̬��ȡ uuid �ķ�����Ȼ���� c �������������ȡuuid
	public static String getUUID(){
		return UUID.randomUUID().toString();
	}
	
	public static void main(String[] args) {
		NdkSimple1 ndSimple1 = new NdkSimple1();
		
		/*System.out.println("�޸�ǰ��"+ndSimple1.name);
		ndSimple1.changeName();
		System.out.println("�޸ĺ�"+ndSimple1.name);*/
		
		
		/*System.out.println("�޸�ǰ��"+NdkSimple1.age);
		changeAge();
		System.out.println("�޸ĺ�"+NdkSimple1.age);*/
		
		ndSimple1.callAddMathod();
	}
	// �ı���������
	public native void changeName();
	public static native void changeAge();
	
	// c ���� java ����
	public native void callAddMathod();
	
	static{
		// ����������ǵĶ�̬�� 
		// System.loadLibrary ��android ����apk�е�libsĿ¼�� .so ��
		// System.load : ����һ������·���ϵ� .so �⣬ȥ�������������ٽ��м���(data/data)
		System.load("C:/Users/hcDarren/Desktop/android/NDK/NDK_Day12/x64/Debug/NDK_Day12.dll");
	}
}
