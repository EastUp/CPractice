#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream> // c++ 的包
#include "15.Student.h"
//#include "15.Student.cpp"

using namespace std; // 命名的空间， java中的内部类

// 1. c 和 c++ 的区别

// 1. c++ 代码中可以混编 c 代码，c++ 里面写 c 代码也可以调用
// 2. c++ 面向对象（java）, c 面向过程
// 3. 很多的开源框架都是用 c++ 写的（大部分基于 c++）

/*int main() {
    // printf("Hello World");

    // c++ 打印 opencv << 操作符重载
    // std::cout << "Hello World" << std::endl;
    cout << "Hello World" << endl;
}*/

// 2. 常量
/*int main() {
    const int number = 10;

    // number = 20;

    // int* numberP = &number; //  不能通过地址去修改值，但是某些编译器上面能通过，但是也不能修改值。
    // c 是能干修改的，在 c 中可以说是一个伪命题

    // *numberP = 20

    // printf("%d",number);
}*/

// 3. 引用
/*int swap(int* number1,int* number2){
    int temp = 0;
    temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

int swap(int &number1,int &number2){ // 引用
    cout << "swap number1的地址" << &number1 << endl;

    int temp = 0;
    temp = number1;
    number1 = number2;
    number2 = temp;
}

int main(){
    int a  = 10;

    // int b = a; // 这个地址不一样
    int &b = a; // 给 a 指向的内存取另外一个别，名 b

    b = 20;

    cout << "a的地址" << &a << endl;
    cout << "b的地址" << &b << endl;
    cout << "a的值" << a <<endl;
    cout << "b的值" << b <<endl;

    // 交换值
    int number1 = 10;
    int number2 = 20;

    // 引用，四驱模型值的拷贝，引用其实就是地址赋值，可以看成同一块内存的另外一个变量
    cout << "main number1的地址" << &number1 <<endl;

    swap(number1,number2);

    cout << "number1 = " << number1 << ", number2 = " << number2 << endl;
}*/

// 3. 常量引用
/*typedef struct{
    char name[20];
    int age;
} Student;

void insertStu(const Student &stu) {// &stu  不想改，常量引用
    // 可以修改 stu 的值
    // strcpy(stu.name,"Jack");

    // 就变成了只读
    cout << stu.name << "," << stu.age << endl;

}

int main(){
    Student stu = {"Eastrise",20};

    insertStu(stu);
}*/

// 4. 函数重载和默认参数
/*int add(int number1, int number2 = 200, bool cache = 0) { // number2 = 200 默认的参数 kotlin 很像
    return number1 + number2;
}

// 错误 1 error C2084：函数 "int add(int,int)" 已有主题， c 不允许函数的重载
int add(int number1, int number2, int number3) {
    return number1 + number2 + number3;
}

int main() {
    int number1 = 100;
    int number2 = 200;
    int sum = add(number1, 200);

    // bool 类型
    bool cache = -100; // 0（false） 和 !0（true）

    if (cache) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // printf("sum = %d", sum);
}*/

// 0 1 2 ,0 打印， 1 上传到后台， 2 友盟和服务器
void printLog(char* content,int){ //  自己平台打印，产品说了下个版本可能要上传到服务器，友盟也要备一份
    cout << content << endl;
    // 补功能 有可能
}

int main(){
    // new , new 出来的是一个指针
    Student* stu = new Student();

    printLog("xxx",0);// 100

    printLog("xxx",1);// 100

    printLog("xxx",2);// 100

    stu->setName("Eastrise");

    stu -> setAge(24);

    cout << stu->getName() << " , " << stu->getAge() << endl;
}

// 补充：开发过程中（重要）直接写的问题所在 Student.cpp 是一个单独类 Student.cpp
// 会编译成一个 so 库，必须要有一个头文件







