#include <iostream>
using namespace std;

// 类型转换
class Person{
public:
    string name;
    int age;
public:
    Person(string name,int age):name(name),age(age){}
};

class Student : public Person{
public:
    Student(string name,int age):Person(name,age){
    }
};

class Worker: public Person{
};

// static_cast(静态转换 类似于 直接转换)
/*int main(){
    double number1 = 20.02;
    // 直接转换
    // int number2 = number1;
    // 用于基本数据类型之间的转换，例如把 int 转 char
    // int number2 = static_cast<int>(number1);
    // cout << number2 << endl;

    // 把类型转换成另一种类型，用于类层次结构中基类和派生类之间指针或引用的转换
    // Student *stu = new Student("eastrise",26);
    // Person *person = stu;
    // Person *person = static_cast<Person*>(stu); // ok的

    // 待会再试
    Person person = Person("eastrise",26);
    // 转成 Student
    // Student stu = person; // 错误

    cout << person.name.c_str() << " , " << person.age << endl;
}*/

// const_cast（常量转换，用于修改常量的值）
/*int main(){
    const Person* person = new Person("eastrise",26);

    cout << person->name.c_str() << " , " << person->age << endl;

    // person->age = 24;
    // const_cast
    Person* person1 = const_cast<Person*>(person);
    person1->age = 25;
    person1->name = "Jack";

    cout << person1->name.c_str() << " , " << person1->age << endl;
}*/

// reinterpret_cast
/*int main(){
    // 待会再试
    Person *person = new Person("eastrise",26);
    // 转成 Student
    // Student stu = person; // 错误
    // Student *stu = static_cast<Student*>(person); // 正确

    long mPtr = (long)person; // NDK中可以
    // 除了字符类，各种类型的转换  long -> 对象的指针* ，用到reinterpret_cast
    // 与 static_Cast 区别在于 static_cast 一般用于转换有继承关系的类型 reinterpret_cast 也能转换有继承关系的类型
    Student *stu = reinterpret_cast<Student*>(person);

    cout << stu->name.c_str() << " , " << stu->age << endl;
}*/

// dynamic_Cast (动态转换 ，更安全，转换成功返回类型，失败返回空 ，
//      必须要包含多态类型和 static_cast 很类似，但是更安全)
/*
int main(){
    Student *stu = new Student("",26);

    Person *worker = dynamic_cast<Person* >(stu);
}
*/

/*class Exception{
public:
    string msg;
public:
    Exception(string msg):msg(msg){}

    const char* what(){
        return msg.c_str();
    }
};

// 异常的处理
int main(){
    // c++ 中有自己一套异常的体系，不要去强记
    // 但是 c++ 可以抛任何数据类型 try{}catch(数据类型 变量名){}
    // throw 抛异常
    try{
        int i = 0;

        if(i == 0)
            throw Exception("出异常了");

        if(i < 0)
            throw 12.5f;
    } catch (int number) {
        cout << "捕捉到异常" << number << endl;
    } catch (Exception e) {
        cout << "捕捉到异常：" << e.what() << endl;
    } catch (...) {
        cout << "捕捉到其它异常"<< endl;
    }
}*/

int main(){
    // C++ STL(Standard Template Library) 标准模板库：容器 + 迭代 + 算法
    // 1. 对象的构建
    string str1 = "123";
    string str2("123");
    string str3(5,'A'); // 5 个 A = AAAAA
    string *str4 = new string ("123");

    // cout << str1.c_str() << endl;
    // cout << str2.c_str() << endl;
    // cout << str3.c_str() << endl;
    // cout << str4->c_str() << endl;

    // string 转 char* c_str();
    const char* c_str1 = str1.c_str();
    cout << c_str1 << endl;

    // char* 转 string
    char* c_str = "east";
    string str(c_str); // 对象
    cout << str.c_str() << endl;
}



