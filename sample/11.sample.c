#include <stdio.h>
#include <stdio.h>
#include <string.h>

// 写一个打印数组的方法
void print(int* arr,int length){
    // 获取数组的大小
    int i = 0;
    for(; i < length; i++){
        printf("%d",arr[i]);
    }
}

/*void main(){
    int a; // 告诉c和c++编译器开辟一块连续大小的 4 字节的内存空间
    int arr[] = {1,2,3,4,5,6};

    // 求数组的大小？
    int size = sizeof(arr) / sizeof(int);

    printf("size = %d\n",size);

    print(arr,size);

    getchar();
}

void main(){
    int a; // 告诉c和c++编译器开辟一块连续大小的 4 字节的内存空间
    int arr[] = {1,2,3,4,5,6}; // arr 数据类型的内存大小空间 24
    a = 10;
    // -362002528 , -362002524  , -362002528  , -362002504   -362002504? = -362002528 + 24(数组的内存大小)
    printf("%d,%d,%d,%d",arr,arr+1,&arr,&arr+1);

    getchar();
}*/

/*struct MyStruct{
    char* name;
};

typedef struct MyStruct Student; //  给 MyStruct 取一个别名叫做 Student

// int32_t，可以对基本数据类型取别名
typedef int int32;

void main(){
    Student stu = {"Eastrise"};

    int32 number1 = 100;

    printf("number1 = %d",number1);

    // 获取 Bitmap, 锁定画布 void**
    // void number;// 错误

    // memcpy(); 拷贝内存，什么用 void*

    getchar();
}*/

/*char* getStr1(){
    char* str = "12345";
    return str;
}

char* getStr2(){
    char* str = "12345";
    return str;
}

char* getStr3(){
    // 静态分配的内存 是在栈区，会被自动回收
    char buff[128];

    strcpy(buff,"12345");
    return buff;
}

char* getStr4(){
    // 动态分配的内存是 在堆区
    char* buff = malloc(128); // char* buff char* 是四字节的数据类型，存的是堆区开辟的 128 个字节的首地址
    strcpy(buff,"12345");
    return buff;
}

void main(){

    char* str1 = NULL;
    char* str2 = NULL;

    str1 = getStr1();
    str2 = getStr2();

    char* str3 = getStr3();

    char* str4 = getStr4();

    // str1的地址和str2的地址是一样的都指向了 字符常量 "12345"

    printf("%d,%d,%s,%s",str1,str2,str3,str4); // str3 = "�" str4 = "12345"

    getchar();

}*/

void main(){
    int a = 10;
    int b = 10;
    // 0508 , 0496  a 的地址要大于 b 的地址 （debug）
    // 016  , 020   a 的地址要小于 b 的地址 （release）
    // buffer 数据类型跟栈的开口方向无关 （内部存储都是向上）

    char buff[10];
    // buff+1 -> buff
    printf("%p , %p , %p , %p",&a,&b,buff,buff+1);

    int a1 = 100;
    int* ff=  &a1; // 虽说是 a1 的地址，但是我也可以把 ff 看做一个数组

    // char** 二位数组 char** 二级指针

    ff += 1;

    getchar();
}
// 理解指针的关键还是在于内存 , 指针的大小是 4 字节 int* double* 指针存放的是一块内存的地址 4 字节，但是也会有数据类型













