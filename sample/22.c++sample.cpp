#include <iostream>
#include <algorithm>// STL 算法包
#include <cctype> // 用到一个函数指针，回调函数

using namespace std;

/*int main(){
    string str("1234567");

    // 1. 字符串的遍历
    for(int i = 0; i < str.length(); i++){
        cout << str[i] << endl;
    }

    // 迭代器遍历
    for(string::iterator it = str.begin(); it < str.end(); it++){
        cout << *it <<endl;
    }

    try{
        for(int i = 0; i < str.length() + 2; i++){
            cout << str.at(i) <<endl; // 如果越界会抛异常
        }

        for(int i = 0; i < str.length() + 2; i++){
            cout << str[i] <<endl; // 不会报错！！！，会导致程序宕机，AS里面是可以的
        }
    } catch (...) {
        cout << "异常了" << endl;
    }
}*/

// 添加
/*int main(){
    string str1 = "123";
    string str2 = "456";

//     str1 = str1 + str2;
     str1 = str1.append(str2);

    cout << str1 << endl;
}*/

// 删除
/*int main(){
    string str1 = "123 abc 123 abc 123";

    // str1.erase(0,3);// 第一个参数：从哪里开始，第二个参数：删除几个（默认值，字符串结尾）

    // 迭代器删除 2 bc 123 abc 123 解释
    for(string::iterator it = str1.begin(); it<str1.begin()+3; it++){ // 删除一个节后都会从头开始计算
        str1.erase(it);
    }

    cout << str1 << endl;
}*/

// 替换
/*int main(){
    string str1 = "123 abc 123 abc 123";

    // 第一个参数：从哪里开始
    // 第二个参数：替换几个
    // 第三个参数：替换成谁
    str1.replace(0,6,"1234");

    cout <<str1 << endl;
}*/

// 查找
/*int main() {
    string str1 = "123 abc 123 abc 123";
    // 查找谁，从哪里开始
     int position1 = str1.find("123",0);
    // 从后面往前找
    int position2 = str1.rfind("123");

    cout << position1 << "," << position2 <<endl;
}*/

// 大小写转换
/*int main(){
    string str1 = "AAA abc BBB abc 123";
    // 转换成大写
    transform(str1.begin(),str1.end(),str1.begin(),::toupper);

    // 转小写
    transform(str1.begin(),str1.end(),str1.begin(),::tolower);

    cout << str1.c_str() << endl;
}*/

// 作业
// string str1 = "AAA abc BBB abc 123"; abc 全部替换成 def
/*int main(){
    // 寄存器上面的变量不能取地址，register 快速
    register int a = 10;
    // c++ 很多默认情况下就会有 register 增强
    printf("%d",&a);

    for(register int i =0; i < 10; i++){

    }
}*/

// 参数处理增强
/*int a = 10;
int main(){
    printf("%d",a);
}*/

/*class Student{
public:
    char* name;
public:
    void print() const {
        // name = "1234"
    }
};*/

// 2.1 const 使用场景
/*int main(){
    // 1. 修饰变量不可改变
    // const int number = 1;
    // 修饰指针 常量指针，指针常量
    int number = 1;
    // const int *n_p = &number;
    // *n_p = 3; // 常量指针不能改变值
    // 指针常量
    int *const n_p = &number;
    int a = 200;
    // n_p = &a; // 指针常量不能修改值

    // 拷贝构造函数，操作符重载，方法后面（都是由于它的成员不可改变）

    cout << "Hello" << endl;
}*/

// 2.2 c / c++ 之间的区别
// c 里面 const 是一个伪命题，可以通过指针去操作，编译时期的检测
// c++ 里面不光在编译时期做处理，还在运行时做了处理
/*int main(){
    const int number = 12;
    // number = 23;
    int *number_p = const_cast<int*>(&number);// 计算通过 const_cast 转换已经不能修改值
    *number_p = 20;
    cout << number << endl;
    cout << *number_p << endl;
}*/

// 2.3 c / c++ 各自实现原理
// 使用学习的时候不要过多去纠结原理
// 遇到一些奇怪的现象，想办法去分析

// 3. 引用加强
// 3.1 引用的使用场景（回顾，好处）
// 3.2 引用的本质剖析
/*void change(int& number1, int& number2){
    int temp = number1;
    number1 = number2;
    number2 = temp;
}


// 其实引用的本质就是 指针
void change(int& number){// 相当于 change(int* number1);
    number = 12;// 相当于 *number1 = 12;
}

int main(){
    int number1 = 10;
    int number2 = 12;

    change(number1);

    cout << number1 << endl;
}*/

/*int get(){
    int number = 10;
    return number;
}

int& get1(){
    int number = 10;
    return number;
}

// 引用做左值和右值的问题
int main(){
    int number1 = get(); // 10
    cout << number1 << endl;

    int number2 = get1(); // 10;
    cout << number2 << endl;

    int& number3 = get1(); // ? 野指针 12478
    cout << number3 << endl;

}*/

class Student {
private:
    string name;
public:
    Student(string name) : name(name) {}

    string &getName() {// java 想都别想
        return this->name;
    }
};

int main(){
    Student stu = Student("eastrise");

    // 改不动
    // stu.getName() = "Jack";

    stu.getName() = "Jack";

    cout << stu.getName() << endl;

    // vector front back

}

/*class Exception : public out_of_range {
public:
    Exception(string mag) : out_of_range(mag) {
        cout << "构造函数" << endl;
    }

    ~Exception() {
        cout << "析构函数" << endl;
    }
};

void c_method() { // 如果是自己的写，1000 多行
    cout << "抛异常" << endl;
    throw new Exception("异常了");
}

int main() {
    try {
        c_method();
    } catch (Exception *e) {
        // Exception：多次构造函数和析构函数
        // Exception&：避免了多次创建对象（最多的）
        // Exception*：创建的对象会被析构，如果使用局部函数或者成员就会是一个野指针
        cout << "try异常" << e->what() << endl;
        delete e;
    } catch (...) {
        cout << "其它异常" << endl;
    }
}*/




