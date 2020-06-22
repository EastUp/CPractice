#include "17.Student.h"
#include <iostream>

// 一个一个来实现
int Student::tag = 0;

// 构造函数
Student::Student(char* name):Student(name,0) { // :age(0) 赋默认值
    this->name = name;
}

Student::Student(char *name,int age) {
    this->name = name;
    this->age = age;
}

// 析构函数
Student::~Student() {

}

// 拷贝函数
Student::Student(const Student &stu) {

}

// 普通方法
void Student::setName(char *name) {
    this->name = name;
}

void Student::setAge(int age) {
    this->age = age;
}

char * Student::getName() {
    return this->name;
}

int Student::getAge() {
    return this->age;
}

void Student::print() const {
    std::cout << this->name << " , " << this->age << std::endl;
}

// 静态
void Student::changeTag(int tag_replace) {
    tag = tag_replace;
}

// 实现友元方法
void changeAge(Student* stu,int age){
    stu->age = age;
}






