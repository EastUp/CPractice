#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 1. 结构体赋值操作
/*typedef struct {
    char name[50];
    int age;
}Student;

void main(){
    Student stu1 = {"Eastrise",25};

    Student stu2;

    // strcpy(stu2.name,stu1.name);
    // stu2.age = stu1.age;

    stu2 = stu1;// = 赋值操作，java 中 stu2 对象就会变成 stu1
    // 在 c 中相当于是（内容）赋值操作，是把 stu1 的值赋值给 stu2;

    printf("%p,%p\n",stu1,stu2);

    printf("%s,%d",stu2.name,stu2.age);
}*/

// 2. 结构体套指针
/*typedef struct {
    char* name; // 定义一个 name 指针，name 是可以给任何char*值，结构体的大小怎么算,64位计算机上8字节，32位上4个字节
    int age; // 4个字节
}Student;

void main(){
    Student stu;

    // stu.name = "Eastrise";// 将指针指向常量区的中Eastrise（OK）

    stu.name = (char*)malloc(100); // 如果需要调用 strcpy 给结构体的char* 赋值就必须要开辟内存
    // 结构体套指针，我们必须对结构体指针进行初始化（赋值）
    // 指针可以指向任何地址，但在64位计算机上它的大小永远是 8 个字节，在32位计算机上它的大小永远是 4 字节
    strcpy(stu.name,"Eastrise");// 往 stu.name 中拷贝数据 Eastrise（错误，必须先进行开辟内存才能拷贝）

    stu.age = 24;

    printf("%s,%d,%d",stu.name,stu.age,sizeof(Student)); // 16个字节？？因为要字节对齐，是8的倍数所以是 16
}*/

// 3. 深拷贝和浅拷贝
/*typedef struct {
    char* name; // 定义一个 name 指针，name 是可以给任何char*值，结构体的大小怎么算,64位计算机上8字节，32位上4个字节
    int age; // 4个字节
}Student;

void copyTo(Student* from,Student* to){
    *to = *from; // 指针的赋值运算 是一个浅拷贝，都指向的是同一块内存地址

    // 非得用，就将指针进行深拷贝（系统架构原型设计模式里面）
    to->name = malloc(100); // 开辟一块内存
    strcpy(to->name,from->name); // 值的拷贝。
};

void main(){
    Student stu1;

    stu1.name = (char*)malloc(100);
    strcpy(stu1.name,"Eastrise");
    stu1.age = 24;

    Student stu2;
    stu2.name = "Jack";
    stu2.age = 24;

    copyTo(&stu1,&stu2); // 用方法进行拷贝，有问题吗？

    printf("%s,%d",stu2.name,stu2.age);

    // 释放内存
    if(stu1.name){
        free(stu1.name);
        stu1.name = NULL;
    }

    if(stu2.name){
        free(stu2.name); // 浅拷贝会释放出错
        stu2.name = NULL;
    }
}*/

// 4. 结构体的偏移量强化
typedef struct date{ // 12
    char year;
    char month;
    char day;
}date;

typedef struct student{
    double number; // 8 内部偏移量 字节对齐 是针对后面的这个数据来看的
    int age; // 4
    int salary; // 4
    char sex; // 1 8
    char name[10]; // 10
    struct date birthday; // 12

    // 31%4  32%4 32个字节？ // 36
}student;

typedef struct Worker{
    double salary;
    int age;
    char sex;
}Worker;

void main(){
    student* stu = NULL; // 0x00000000 0

    // 1. 内部偏移量的问题
    printf("%d\n",&(stu->name) - (int)stu); // 0

    printf("%d",sizeof(student));

    getchar();
}

// 结构体大小的偏移量问题
// 1. 获取内存元素的偏移量 &(stu->name) - (int)stu
// 2. 获取结构体的大小 sizeof(student)
// 3. 大小怎么来的，根据每个的偏移量计算来的 ， 结构体的大小跟内存位置摆放有关
// 4. 把最小的字节数尽量往后靠，结构体一旦定义了不要轻易的去挪动，因为我们只要知道内部任何一个变量的地址，那么就知道了整个结构体









