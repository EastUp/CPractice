#include "com_east_jni08_Sample1.h"

// 调用 java 层 static 的获取 uuid 的方法
JNIEXPORT void JNICALL Java_com_east_jni08_Sample1_callStaticMethod
(JNIEnv* env,jclass jclz){
	
	// 2. 获取jmethodID
	jmethodID j_mid = (*env)->GetStaticMethodID(env, jclz, "getUUID", "()Ljava/lang/String;");

	// 1. 调用 getUUID 的方法 statics
	jstring j_uuid = (*env)->CallStaticObjectMethod(env,jclz,j_mid);

	// jstring -> c_str
	char* c_uuid = (*env)->GetStringUTFChars(env,j_uuid,NULL);

	// 回收，字符串回收
	(*env)->ReleaseStringChars(env,j_uuid,c_uuid);

	printf("c_uuid = %s",c_uuid);
}


// c 层 创建 java 对象
JNIEXPORT jobject JNICALL Java_com_east_jni08_Sample1_createPoint
(JNIEnv* env, jclass jclz){

	// 2. 需要获取 Point 的class name = "全类名"
	// 方法参数上的 jclz  指的是 Sample1.class
	jclass point_clz = (*env)->FindClass(env,"com/east/jni08/Point");

	// 3. 获取jmethodID ,构造方法写死 "<init>"
	jmethodID j_mid = (*env)->GetMethodID(env, point_clz, "<init>","(II)V");

	// 1. 创建对象
	jobject point = (*env)->NewObject(env,point_clz, j_mid, 11, 12);

	// 练习下 y 重新赋值,调用 set 方法
	j_mid = (*env)->GetMethodID(env,point_clz,"setY","(I)V");
	/* va_list 集合
	void (JNICALL *CallVoidMethodV)
	(JNIEnv *env, jobject obj, jmethodID methodID, va_list args);
	// jvalue
	void (JNICALL *CallVoidMethodA)
	(JNIEnv *env, jobject obj, jmethodID methodID, const jvalue * args);
	*/

	(*env)->CallObjectMethod(env,point,j_mid,33);

	// 直接重新赋值，相当于反射了但是比反射快
	jfieldID j_fid = (*env)->GetFieldID(env,point_clz,"y","I");
	(*env)->SetIntField(env,point,j_fid,55);


	return point;
}

void main(){
	// 常量，不能去修改
	const int number = 100;
	// number = 200;

	int number1 = 100;
	int number2 = 200;

	// 常量指针（const 在 * 之前,地址可以被重新赋值，但是值不能改变）
	// int const * n_p = &number2;
	// n_p = &number1;
	// printf("n_p = %p",n_p); // 地址是可以重新被赋值的
	// *n_p = 300; // 值不能改变

	// 指针常量（const 在 * 之后,地址不可以被重新赋值，但是值可以改变）
	int* const n_p = &number2;
	// n_p = &number1; // 地址是不能被重新赋值的
	*n_p = 300;
	printf("number2 = %d",number2);

	getchar();
}