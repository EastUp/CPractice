#include "15.Student.h"

// 写实现，定义了另外一个方法
void Student::setAge(int age){ // 实现 Student 的 setAge 方法
    this->age = age;
}

void Student::setName(char* name){
    this -> name = name;
}

int Student::getAge(){
    return this->age;
}

char* Student::getName(){
    return this->name;
}







