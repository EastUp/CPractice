#include <stdlib.h>
#include <stdio.h>
// 定义一个结构体指针的别名
typedef const struct JNINativeInterface* JNIEnv;
// 模拟一个结构体
struct JNINativeInterface{
	// 结构体的方法指针
	char*(*NewStringUTF)(JNIEnv*,char*);
};

char* NewStringUTF(JNIEnv* env, char* c_str){
	// c_str -> jstring
	return c_str;
}

char* Java_com_darren_getSingnaturePassword(JNIEnv * env){
	// JNIEnv * 其实已经是一个二级指针了，所以 -> 调用的情况下必须是一级指针 *取值 
	return (*env)->NewStringUTF(env, "940223");
}

void main(){

	// 构建 JNIEnv* 对象
	struct JNINativeInterface nativeInterface;
	// 给结构方法指针进行复制(实现)
	nativeInterface.NewStringUTF = NewStringUTF;

	// 传给 Java_com_darren_ndk12_NdkSimple_getSingnaturePassword 的参数是 JNIEnv*
	JNIEnv env = &nativeInterface;// 一级指针
	JNIEnv* jniEnv = &env;// 二级指针

	// 把 jniEnv 对象传给 Java_com_darren_ndk12_NdkSimple_getSingnaturePassword
	char* jstring = Java_com_darren_getSingnaturePassword(jniEnv);

	// jstring 通过 JNIEnv 传给 java 层
	printf("jstring = %s",jstring);

	getchar();
}
