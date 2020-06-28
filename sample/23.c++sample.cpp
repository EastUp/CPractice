#include <iostream>

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <functional>

using namespace std;

/*int main(){ // vector 数组
    // vector
    // 1. vector<int> v;

    // 2. vector<int> v(10);

    // 3. vector<int> v(10,0);

    vector<int> v;

    // 插入数据
    // v.begin(); // 迭代器的开始位置
    v.insert(v.begin(),12);
    v.insert(v.begin(),22);
    v.insert(v.begin(),32);

    v.insert(v.end(),42);

    // 引用当左值当右值（修改）
    v.front() = 33;
    v.back() = 44;

    v.push_back(55);

    // 移除最后的元素，并没有返回值
    // v.pop_back();
    // 通过迭代器位置进行移除
    // v.erase(v.begin());

    // 获取数据 for 循环
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << "\t"; // 越界程序宕机,clion 和 AS中不一定出错
    }
    cout << endl;
    //
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << "\t"; // 越界抛异常 out_of_range
    }
    cout << endl;

    // 通过迭代器
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << "\t"; // 越界抛异常 out_of_range
    }
    cout << endl;
}*/

// stack 栈， 先进后出（链表，数组）
/*int main(){
    stack<int> s;

    // 压栈 ， 压入指定位置
    s.push(12);
    s.push(22);
    s.push(32);

    // 并不能够通过角标去插入获取值，如果在开发的过程中的确需要通过角标去获取值，需要自定义

    *//*for(int i = 0; i < s.size(); i ++){
        cout << s. << endl;
    }*//*

    // 迭代器也没有，并不支持循环的，非得循环

    *//*for(stack<int> :: iterator it; i < s.size(); i ++){
        cout << s. << endl;
    }*//*

    int top = s.top();
    cout << top << endl;

    // 弹出栈顶
    s.pop();

    top = s.top();

    cout << top << endl;

    while(!s.empty()){
        top = s.top();
        cout << top << endl;
        s.pop();
    }
}*/

// queue 队列（链表，数组）
/*int main(){
    queue<int> q;

    q.push(12);
    q.push(44);
    q.push(32);

    q.front() = 42;

    cout << q.front() <<endl;

    q.pop();

    cout << q.front() <<endl;

    // 最后，最后加入的
    int back = q.back();
    cout << back << endl;

    while (!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}*/

// 优先级队列（数据结构 数组，排序的方式堆排序）
/*int main(){

    // int 存放的数据 vector<int> 数据类型（数组） greater 从大到小 less 从小到大
    priority_queue<int,vector<int>,less<int>> pq;
    pq.push(12);
    pq.push(44);
    pq.push(32);
    pq.push(10);

    // 获取的是最后一个，最大值
    cout << pq.top() << endl;
}*/

// list 链表，双向链表（有没有回环）
/*int main(){
    list<int> l;

    // 插入
    l.push_front(11);
    l.push_back(22);
    l.insert(l.begin(),10);

    // 修改
    l.back() = 33;
    l.front() = 44;

    // 不能通过角标去访问，也不能去修改

    // 移除
    l.erase(l.begin());
    l.pop_front();
    l.pop_back();

    // 循环
    for(list<int>::iterator it = l.begin(); it != l.end(); it ++){
        cout << *it << endl;
    }
}*/

/*class Student{
public:
    string name;
    int grade;
public:
    Student(string name,int grade):name(name),grade(grade){}
};

// 谓词（函数谓词）：按照特定的规则所表写的函数谓词
bool compare(const Student& _Left,const Student& _Right){
    return _Left.grade > _Right.grade;
}

// 函数对象 仿函数
struct comparefuction{
    // 函数重载了（）运算符，函数对象，仿函数
    bool operator()(const Student& _Left,const Student& _Right){
        return _Left.grade > _Right.grade; // 从大到小
    }
};

// 基本数据类型，对象数据类型
int main(){
    set<Student,comparefuction> s;

    Student s1("eastrise",2);
    Student s2("eastrise",9);
    Student s3("eastrise",5);

    s.insert(s1);
    s.insert(s2);
    s.insert(s3);

    for(set<Student>::iterator it = s.begin(); it!=s.end(); it ++){
        cout << it->name << "," << it->grade << endl;
    }
}*/

// set 容器（红黑树结构），会对你存入的数据进行排序，但是不允许元素相同
/*int main(){
    // set<int, less<int>> s; // 从小到大排序，默认就是 less
    set<int, greater<int>> s; // 从大到小

    // 添加参数， 不需要用迭代器，也不需要指定位置
    s.insert(3);
    s.insert(5);
    s.insert(4);

    // 重复的插入，并不会报错，返回两个值 插入迭代器的位置，是否插入功
    pair<set<int,greater<int>>::iterator ,bool> res = s.insert(5);
    // res.first;// 获取第一个参数
    bool insert_succeed = res.second;
    if(insert_succeed){
        cout << "插入成功" << endl;
    }else{
        cout << "插入失败" << endl;
    }

     int count = s.count(5);
    // s.find();

    for(set<int> :: iterator it = s.begin(); it != s.end(); it ++){
        cout << *it << endl;
    }

}*/

// multiset容器， 允许重复，用法和 set 一样
/*int main(){
    // set<int,less<int>>;// 从小到大排序，默认就是 less
    multiset<int,greater<int>> ms;

    // 添加参数， 不需要用迭代器，也不需要指定位置
    ms.insert(3);
    ms.insert(5);
    ms.insert(4);
    ms.insert(4);
    ms.insert(3);

    for(set<int>::iterator it = ms.begin(); it != ms.end(); it++){
        cout << *it << endl;
    }

}*/


