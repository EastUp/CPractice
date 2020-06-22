#ifndef STUDENT_H
#define STUDENT_H

class Student{
private:
    char* name;
    int age;
public:
    // 静态属性的声明
    static int tag;

public:
    Student();
    Student(char* name);
    Student(char* name,int age);
    // 析构函数
    ~ Student();
    // 拷贝构造函数
    Student(const Student& stu);
public:
    void setAge(int age);
    void setName(char* name);
    int getAge();
    char* getName();

    void print() const;

    // 静态和友元
    static void changeTag(int tag);
    friend void changeAge(Student* stu,int age);
};
#endif // STUDENT_H