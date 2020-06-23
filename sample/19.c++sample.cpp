#include <iostream>

using namespace std;

// 1. 属性初始化
/*class Person{
protected:
    char* name;
    int age;
public:
    Person(char* name,int age){
        this->name = name;
        this->age = age;
    }
};

class Course{
private:
    char* name; // java String
public:
    Course(char *name) {
        this->name = name;
    }

    string _name(){
        return this->name;
    }
};

class Student: public Person{
private:
    // char* courseName;
    Course course;
public:
    Student(char* name,int age,char* courseName):Person(name,age),course(courseName){ // 初始化父类的属性
        // this->courseName = courseName;
    }

    void print(){
        cout  << name << "," << age << "," << course._name() << endl;
    }
};*/

// 2. 多继承，在 java 里面是不允许多继承的， c++ 是可以的, 但是你也不能有二义性（歧义）
/*class Person {
protected:
    char *name;
public:
    Person(char *name) {
        this->name = name;
    }

    char *_name() {
        return this->name;
    }
};

class Child {
    int age;
public:
    Child(int age) {
        this->age = age;
    }

    int _age() {
        return age;
    }
};

class Student : public Person, public Child { // 多继承，并没有实现
public:
    Student(char *name, int age) : Person(name), Child(age) {

    }
};*/

// 2.2 虚继承（二义性）
class A {
public:
    char *name;
};

class B : virtual public A { // 确保继承过来的相同属性或者函数，只存在一份拷贝

};

class C : virtual public A {

};

class D : public B, public C {

};

// 3. c++ 中的多态
class Activity {
public:
    virtual void onCreate() { // 支持多态，虚函数
        cout << "Activity 中的 onCreate" << endl;
    }
};

class MainActivity : public Activity {
public:
    void onCreate() override {
        cout << "MainActivity 中的 onCreate" << endl;
    }
};

class WelcomeActivity : public Activity {
public:
    void onCreate() override {
        cout << "WelcomeActivity 中的 onCreate" << endl;
    }
};

void startActivity(Activity *activity) {
    activity->onCreate();
}

int main() {
    Activity *activity1 = new MainActivity();
    Activity *activity2 = new WelcomeActivity();

    // activity->onCreate();
    // c++ 中的多态是怎样的，默认情况下不存在
    // 父类指向子类的引用，重写，里氏替换原则
    // 程序在编译期间并不知晓运行的状态（我需要运行哪个函数），只要在真正运行的过程中才会去找需要运行的方法
    // 解释一下 java 中的多态 20k
    startActivity(activity1);
    startActivity(activity2);

    // c++ 多态：动态多态（子父类），静态多态（函数的重载）（编译过程确定性的区别）
    //（一嗨租车） 5轮，2轮（万科），4轮
}

// 纯虚函数类似于：java 中的 抽象类，接口，
/*class BaseActivity{
public:
    void onCreate(){ // 普通函数
        initView();
        initData();
    }

    // 子类必须要实现
    virtual void initData() = 0; // 虚函数，没有实现的，类似于 java 中的抽象方法，如果子类不实现会报错

    virtual void initView() = 0;
};

// 如果不实现父类的纯虚函数，那么 MainActivity 也会变成抽象类，抽象类不允许实例化
class MainActivity:public BaseActivity{
    void initData() override{
        cout << "initData" << endl;
    }

    void initView() override {
        cout << "initView" << endl;
    }
};

int main(){
    BaseActivity *m_a = new MainActivity();

    m_a->onCreate();
}*/

/*class ClickListener{ // 所有的函数都是虚函数，那么就可以认为是接口
public:
    virtual void click() = 0; // 必须要加 = 0
};

class ImageClickListener : public ClickListener{
public:
    void click() override{
        cout << "图片点击" << endl;
    }
};

void click(ClickListener* listener){
    listener -> click();
}

// 函数指针 07 次
void click(void(*c)()){ // 函数指针作为参数传递 返回值（函数名）（参数）
    // 压缩开始
    c(); // 输出压缩进度
    // 压缩结束
}

void click(){
    cout << "click 点击" << endl;
}

int main(){
    // 函数指针的时候，回调可以用 指针函数作为回调，纯虚函数类进行回调（接口）
    ClickListener* listener = new ImageClickListener();

    // listener -> click();
    // click(listener);

    click(click);
}*/

// 构造函数和析构函数
/*class Person{
protected:
    char* name;
    int age;
public:
    Person(char* name,int age):name(name),age(age){
        cout << "构造函数" << endl;
    }
    ~Person(){
        cout << "析构函数" << endl;
    }
};

class Student: public Person{
public:
    Student(char* name,int age):Person(name,age){
        cout << "Student 的构造函数" << endl;
    }
    ~Student(){
        cout << "Student 的析构函数" << endl;
    }
};

int main(){
    // 构造函数：先父类 -> 再子类
    // 析构函数: 先子类 -> 再父类
    Student* stu = new Student("East",25);
    delete (stu);
}*/

// 模板函数（java 中的泛型）
/*int add(int number1,int number2){
    return number1+number2;
}

double add(double number1,double number2){
    return number1+number2;
}

float add(float number1,float number2){
    return number1+number2;
}*/

// 模板函数 算法4 看一遍敲一遍
/*template <typename T>  // 模板函数的定义（不能有分号）
T add(T number1,T number2){
    return number1+number2;
}

int main(){
    int sum1 = add(1,2);
    cout << sum1 << endl;

    int sum2 = add(1.0,2.0);
    cout << sum2 << endl;

    int sum3 = add(1.0f,2.0f);
    cout << sum3 << endl;
}*/






