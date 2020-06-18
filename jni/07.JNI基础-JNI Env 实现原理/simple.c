
// 实现我们的 native 方法
#include "com_east_NdkSample.h"
#include "com_east_NdkSample1.h"

// JNIEXPORT： JNI 一个关键字，不能少（编译能通过），标记为该方法可以被外部调用
// jstring：代表 java 中的 String
// JNICALL：也是一个关键字，可以少的 jni call
// jobject： java 传递下来的类对象，就是本项目中 NdkSample java 对象
// jclass：java 传递下来的 class 对象，就是本项目中的 NdkSample.class
JNIEXPORT jstring JNICALL Java_com_east_NdkSample_getSingnaturePassword
        (JNIEnv * env, jclass clz){
    // C 中 typedef const struct JNINativeInterface* JNIEnv; 已经是一个结构体指针了
    // C++ 中 typedef _JNIEnv JNIEnv; // 就是一个结构体
    // JNIEnv * 其实已经是一个二级指针了，所以 -> 调用的情况下必须是一级指针 *取值
    return (*env)->NewStringUTF(env, "eastrise");
}

JNIEXPORT void JNICALL Java_com_east_NdkSample1_changeName
(JNIEnv * env, jobject jobj){

// 1. 获取 jclass
jclass j_clz = (*env)->GetObjectClass(env,jobj);
// 2. 获取 jfieldID
// 获取 jfieldId (JNIEnv *env, jclass clazz, const char *name, const char *sig)
// name 获取哪个属性的属性名 ,sig 属性的签名
jfieldID j_fid = (*env)->GetFieldID(env, j_clz, "name", "Ljava/lang/String;");
// 1. 获取 name 的属性值
jstring j_str = (*env)->GetObjectField(env,jobj,j_fid);

// 打印字符串 jstring -> c_str
char* c_str = (*env)->GetStringUTFChars(env, j_str, NULL);

printf("name is %s", c_str);

// 修改成 Jack
jstring jack_name = (*env)->NewStringUTF(env,"Jack");
(*env)->SetObjectField(env,jobj,j_fid,jack_name);
}

// 静态方法参数会变为 jclass 代表 NdkSample1.class
JNIEXPORT void JNICALL Java_com_east_NdkSample1_changeAge
(JNIEnv * env, jclass jcls){

// 2. 获取 jfieldID
jfieldID j_fid = (*env)->GetStaticFieldID(env,jcls,"age","I");
// 1. 获取 age 的值 Static 获取静态的
jint age = (*env)->GetStaticIntField(env,jcls,j_fid);

// jnit == int
age += 12;

(*env)->SetStaticIntField(env,jcls,j_fid,age);
}

// c 调用 java 层普通方法
JNIEXPORT void JNICALL Java_com_east_NdkSample1_callAddMethod
(JNIEnv * env, jobject jobj){

// 3. 获取 jclass
jclass jcls = (*env)->GetObjectClass(env,jobj);

// 2. 获取 jmethodID
jmethodID j_mid = (*env)->GetMethodID(env,jcls,"add","(II)I");

// 1. 调用 java 方法
jint sum = (*env)->CallObjectMethod(env,jobj,j_mid,2,3);

printf("sum = %d",sum);
}
