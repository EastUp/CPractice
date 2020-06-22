#include <iostream>
#include <stdarg.h>
using namespace std;
#include "17.Student.h"
// 1. 可变参数
//void sum(int count,...){// int ..., c++ ...
//    va_list vp;
//    // 可变参数开始方法， count 代表从哪里开始
//    va_start(vp,count);
//
//    int number = va_arg(vp,int);
//    cout << number <<endl;
//
//    // 读取下一个
//    number = va_arg(vp,int);
//    cout << number <<endl;
//
//    // 读取下一个，超出了默认是 0
//    number = va_arg(vp,int);
//    cout << number <<endl;
//}

/*int sum(int count,...){// int ..., c++ ...
    va_list vp;
    // 可变参数开始方法， count 代表从哪里开始
    va_start(vp,count);

    int sum = 0;
    for(int i = 0; i<count;i++){
        sum += va_arg(vp,int);
    }

    // 结尾，释放内存
    va_end(vp);

    return sum;
}

int main(){
    // sum(5,1,2,4);
    int number = sum(5,1,2,4); // 67
    cout << number << endl;
}*/


// 2. static 关键字
/*class Student{
public:
    char* name;
    int age;
    //静态
    static int tag; // 定义

    Student(){
        tag = 12;
    }

public:
    static void change(){
        tag += 12;
    }

    void change1(){
        this -> change();
    }
};

// 静态属性在 c++ 中必须要初始化，初始化必须这么写
int Student::tag = 12;

// 静态 可以直接用类名去操作 ：：
//      静态的属性必须初始化（实现）
//      静态的方法只能去操作静态的属性或方法

int main(){
    Student stu;

    // stu.tag = 12;
    // c++ 操作静态语法 ::
    // Student::tag += 12;
    // Student::change();
    stu.change1();

    cout <<Student::tag << endl;
}*/

// 3. 对象的大小
/*class A{
public:
    double b;
    int a;
    char c;
};

class B{
public:
    double b;
    int a;
    char c;
    static double d;
};

class C{
public:
    double b;
    int a;
    char c;
    C(int a){
        this->a = a;
    }

public:
    int getA(){
        return this->a;
    }
};

// 1. 对象的大小与结构体的计算方式类似
// 2. static 静态变量和方法并没有算到类的大小中
// 3. 栈、堆、全局（静态、常量、字符串），代码区，类的大小只与普通属性有关系
int main(){
    cout << "A 的大小： " << sizeof(A) <<endl; // 16
    cout << "B 的大小： " << sizeof(B) <<endl; // 16
    cout << "C 的大小： " << sizeof(C) <<endl; // 16

    C c1(12);
    C c2(24);
    cout << c1.getA() << endl;
    cout << c2.getA() << endl;

}*/

// 5. const 修饰函数
// this 指针：代表当前的对象，因为类的方法放在代码区，大家一起共享的，所以要有 this 做区分
/*class Student{
public:
    char* name;
    int age;

public:
    // this = const Student* const this
    // 第一个 const : 常量指针， 代表值不能修改
    // 第二个 const : 指针常量，代表指针的地址不能修改
    void change() const { // const 在 () 之后主要用来限制 this 关键字
        // this->age + = 12;
        // this = (Student)0x0012;
    }

    // this = Student& const this
    void change1(){
        // this = (Student)0x0012;
    }
};

int main(){
    Student stu;
    stu.change();

    cout << stu.age << endl;
}*/

// 6. 友元函数
/*class Person{
private:
    int age = 0;
public:
    // 如果有自己写构造函数，那么默认覆盖无参的构造函数
    Person(int age){
        this->age = age;
    }

    int getAge(){
        return this->age;
    }

    // 友元函数的声明
    friend void friend_change(Person* person,int age);
};

// 友源函数的实现
void friend_change(Person* person,int age){
    // 修改一下 age 的值
    // 在类的内部才能访问私有属性
    // 如果该方法声明成友元函数那么是可以在外部访问其私有属性的
    person->age = age;
}

int main(){
    Person person = Person(24);

    friend_change(&person,36);

    cout << person.getAge() << endl;
}*/

// 友元函数和普通函数的区别
int main(){
    Student* stu = new Student("Eastrise",25);

    // Student::changeTag(36);

    changeAge(stu,36);
    stu -> print();
}




