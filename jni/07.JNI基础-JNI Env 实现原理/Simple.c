
// 实现我们的 native 方法
#include "com_darren_ndk12_NdkSimple.h"
#include "com_darren_ndk12_NdkSimple1.h"

// JNIEXPORT: JNI 一个关键字，不能少（编译能通过），标记为该方法可以被外部调用
// jstring : 代表 java 中的 String 
// JNICALL: 也是一个关键字，可以少的 jni call
// JNIEnv: 这个是 c 和 java 相互调用的桥梁，所有 function 搞清
// jobject: java传递下来的对象，就是本项目中 NdkSimple java 对象
// jclass: java传递下来的 class 对象，就是本项目中的 JniSimple.class（如果是静态方法才是jclass）
JNIEXPORT jstring JNICALL Java_com_darren_ndk12_NdkSimple_getSingnaturePassword
(JNIEnv * env, jobject jobj){
    // C 中 typedef const struct JNINativeInterface* JNIEnv; 已经是一个结构体指针了
    // C++ 中 typedef _JNIEnv JNIEnv; // 就是一个结构体

	// JNIEnv * 其实已经是一个二级指针了，所以 -> 调用的情况下必须是一级指针 *取值
	return (*env)->NewStringUTF(env,"940223");
}

JNIEXPORT void JNICALL Java_com_darren_ndk12_NdkSimple1_changeName
(JNIEnv *env, jobject jobj){
	// 获取 name 属性然后修改为 Jack

	// 3.获取 jclass 
	jclass j_clz = (*env)->GetObjectClass(env, jobj);
	// 获取 jfieldId (JNIEnv *env, jclass clazz, const char *name, const char *sig)
	// name 获取哪个属性的属性名 
	// 2.sig 属性的签名
	jfieldID j_fid = (*env)->GetFieldID(env, j_clz, "name", "Ljava/lang/String;");
	// 1.获取 name 属性的值
	jstring j_str = (*env)->GetObjectField(env, jobj, j_fid);

	// 打印字符串 jstring -> c_str
	char* c_str = (*env)->GetStringUTFChars(env,j_str,NULL);

	printf("name is %s",c_str);

	// 修改成 jack
	jstring jackName = (*env)->NewStringUTF(env,"Jack");
	(*env)->SetObjectField(env, jobj, j_fid, jackName);

}

JNIEXPORT void JNICALL Java_com_darren_ndk12_NdkSimple1_changeAge
(JNIEnv * env, jclass jcls){
	// 首先获取原来的

	jfieldID j_fid = (*env)->GetStaticFieldID(env,jcls,"age","I");
	// Static 获取静态的
	jint age = (*env)->GetStaticIntField(env, jcls, j_fid);

	// jint -> int
	age += 12;

	// 设置新的 age 参数
	(*env)->SetStaticIntField(env,jcls,j_fid,age);
}


JNIEXPORT void JNICALL Java_com_darren_ndk12_NdkSimple1_callAddMathod
(JNIEnv *env, jobject jobj){
	
	jclass j_clz = (*env)->GetObjectClass(env,jobj);
	// 获取 methodid 
	jmethodID j_mid = (*env)->GetMethodID(env, j_clz, "add", "(II)I");
	// 去调用 java 的方法
	jint sum = (*env)->CallIntMethod(env, jobj, j_mid,2,3);

	printf("sum = %d",sum);
}