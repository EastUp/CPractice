#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 1. 指针使用注意事项
/*int main(){
    // 犯的错误，在运算的过程中不断的改变指针的位置

    const char* name = "Eastrise";

    const char* temp_name = name;

    int i = 0;
    // 运算打印
    for(;i < 8 ; i++){
        printf("%c",*temp_name);
        temp_name ++;
    }

    printf("\n");
    // 后面还要去操作 name
    printf("name = %s",name);


    getchar();
}*/

// 给一个字符串复制
/*void set(char** str){
    *str = "eastrise";
    // 指针变量不断赋值改变的是指针的指向
}

int main(){
    // 写法有没有问题
    char* name = NULL;

    // 强调一个概念：指针变量与指针指向的内存变量是两个不同的概念
    // 指针变量不断赋值改变的是指针的指向

//    set(&name);

    // name = "sss"; //sss
    strcpy(name,"123");

    printf("name = %s",name);

    getchar();
}*/

// const 关键字在 c 和 c++ 中会有区别，这里先讲 c
/*int main() {
    // 常量
    const int number = 100;

    // number = 200;

    printf("number = %d", number);

    // 常量指针(常量指针的值是不能被修改的)

    // const int* numberP = &number;

    // *numberP = 200;

    int number2 = 300;
    // numberP = &number2;

    // 指针常量（指针常量的地址是不能被修改的）
    // int* const numberP = &number2;

    // *numberP = 400;

    // numberP = &number;

    // 值不能修改，指针也不能修改
    const int *const numberP = &number2;

    // 在 c 里面是一个忽悠类型（假命题）

//    int* numberP = &number;
//    *numberP = 300;
//    printf("number = %d", number);
}*/

// 二级指针的内存模式
// 指针数组：数组指针指向的是数组元素的首地址

/*struct FILE{
    char* file_name;
    int length;
};

int main() {
    char *name = "eastrise";
    // 二级指针，二位数组
    char **nameP = &name;

    // 比如压缩文件,指定两个FILE 一个输入一个输出
    // 定义一个 FILE* 指针数组
    // FILE *file[2] = {{"in.txt",  200},{"out.txt", 100}};
    FILE** file = {{"in.txt",  200},{"out.txt", 100}}; // 另一种定义的方式（指针数组）（二级指针）其实是同一个概念
    // 数组指针指向的是数组的首地址

    int number = 100;
    int* numberP = &number;

    numberP++;
    printf("number = %d\n",*numberP);
}*/

void print(char** str,int len){
    int i = 0;
    for(; i< len; i++){
//        printf("%s\n",str[i]); // [] 也相当于挪动指针
        printf("%s\n",*(str+i));
    }
}

void print1(char str[10][30],int len){ // 不重要
    int i = 0;
    for(; i< len; i++){
//        printf("%s\n",str[i]); // [] 也相当于挪动指针
        printf("%s\n",*(str+i));
    }
}

// 单独来拿字符串数组来讲
/*int main(){
    // 第一种定义方式
    // char** name = {"east","rose","jack"}; // 这种定义方式有问题,我不知道如何去开辟内存
    // 直接去赋值那么 c 和 c++ 会把这哥们当做 二级指针。而不是指针数组

    // char* name[10] = {"east","rose","jack"};// 后面的默认指向的是 NULL 地址，都是在静态常量区
    // char* = "east";

    // 打印一下
    // print(name,10);

    // 第二种定义的方式
    // char name[10][30] = {"east","rose","jack"}; // 这个几个数据都是冲静态常量区copy 到 栈的 buffer里面的
    // 打印一下,print(char** str,int len) 打印报错
    // 这个是因为指针++的步长不一样，指定步长
    // print1(name,3);

    // 第三种定义方式（最常见的一种方式）动态开辟，不理解记住套路
    int number = 4;
    char** params = (char**)malloc(sizeof(char*)*number); // 开辟二位数组
    // 开辟一维数组
    for(int i =0; i<number; i++){
        params[i] = malloc(sizeof(char)*100); // 不会去开辟一维数组

        // 写一些数据
        sprintf(params[i],"i = %d",i);
    }

    print(params,number);

    // 释放数组
    for(int i =0; i<number; i++){
        if(params[i]){
            free(params[i]);
            params[i] = NULL;
        }
    }
    // 然后再释放 params 二维数组  (也可以看做一维数组，只不过这个一维数组里面存放的是元素是 一级数组指针)
    if(params){
        free(params);
        params = NULL;
    }
}*/

// 多级指针的用法，使用的一些场景

void initParams(char*** params,int number){ // 三级指针就出来了，最多也就二级指针（数组指针）
    // 开辟内存去赋值
    char** tempParams = (char**)malloc(sizeof(char*)*number); // 开辟二位数组
    // 开辟一维数组
    int i =0;
    for(;i<number; i++){
        tempParams[i] = malloc(sizeof(char)*50); // 不会去开辟一维数组
        sprintf(tempParams[i],"i = %d",i);
    }
    *params = tempParams;
}

int main(){
    // 我想给字符串数组开辟内存，开辟内存写到另一个方法
    char** params = NULL;
    int number = 4;
    initParams(&params,number);

    print(params,number);

    // 释放
}







