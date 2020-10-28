#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm> // 预定义函数，已经实现好的一些算法头文件

using namespace std;

// map 不能存 key 重复的数据，要么不生效，要么覆盖
/*int main(){
    // map 会对 key 排序，二叉数算法
    map<int,string> map1;

    // 添加数据
    map1.insert(pair<int,string>(01,"01"));
    map1.insert(make_pair(02,"02"));
    map1.insert(map<int,string>::value_type(03,"03"));

    // 区别，如果用前面三种 key 重复添加，不生效
    // map1.insert(map<int,string>::value_type(03,"30"));

    // 第四种方式 = map[key] = value
    map1[04] = "04";

    // 这种方式会覆盖
    map1[04] = "40";

    // 如果要判断添加是否成功
    pair<map<int,string>::iterator,bool> p = map1.insert(make_pair(06,"06"));
    if(p.second){
        cout << "添加成功" << endl;
    }else{
        cout << "添加失败" << endl;
    }

    // 循环迭代器
    for(map<int,string>::iterator it = map1.begin(); it != map1.end(); it++){
        cout << it->first << " - " << it->second.c_str() << endl;
    }

    cout << " 遍历结束"  << endl;

    // 删除 ， 查找
    map<int,string>::iterator find_it = map1.find(0);

    // cout << find_it->first << " - " << find_it->second.c_str() << endl;
    if(find_it!=map1.end()){
        cout << find_it->first << " - " << find_it->second.c_str() << endl;
    }else{
        cout << " 找不到 " << endl;
    }
}*/

/*int main()
{
    std::map<int, std::string> c = {{1, "one"}, {2, "two"}, {3, "three"},
                                    {4, "four"}, {5, "five"}, {6, "six"}};

    // erase all odd numbers from c
    for(auto it = c.begin(); it != c.end(); ) {
        if(it->first % 2 == 1)
            it = c.erase(it);
        else
            ++it;
    }

    for(auto& p : c) {
        std::cout << p.second << ' ';
    }
}*/

// multimap 可存 key 重复的数据
/*
int main(){
    multimap<int,string> map1;
    // 案例， 1 （11， 12， 13）， 2 （21， 22， 23）， 3 （31， 32， 33）

    map1.insert(pair<int,string>(1,"11"));
    map1.insert(pair<int,string>(1,"12"));
    map1.insert(pair<int,string>(1,"13"));

    map1.insert(pair<int,string>(2,"21"));
    map1.insert(pair<int,string>(2,"22"));
    map1.insert(pair<int,string>(2,"23"));

    map1.insert(pair<int,string>(3,"31"));
    map1.insert(pair<int,string>(3,"32"));
    map1.insert(pair<int,string>(3,"33"));

    // 遍历
    for(auto it = map1.begin(); it != map1.end(); it++){
        cout << it->first << " - " << it->second.c_str() << endl;
    }
    cout << " 遍历结束 " << endl;

    // 分组查询 多个数据
    auto find_it = map1.find(3);
    while(find_it!=map1.end()){
        cout << find_it->first << " - " << find_it->second.c_str() << endl;
        find_it ++;
        // 不是我们要找的内容
        if(find_it == map1.end() || find_it -> first != 3){
            cout << "到底了" <<endl;
            break;
        }
    }
}
*/

/*class Person{
public:
    string name;
    char* test;
public:
    Person(){}

    Person(string name):name(name){
        this->test = (char*)malloc(12);
    }

    ~Person(){
        cout << "析构函数" << &test <<  endl;
        free(test);
    }

    void setName(string name){
        this->name = name;
    }
};

// 3. 容器对象拷贝构造函数，就想存同一对象，在任何地方改变，集合的数据也相应发生改变（指针）
int main(){
    // java 中把对象添加到了集合
    // c++ 中会调用对象的拷贝构造函数，存进去的是另一个对象
    // 第一个错误：没有默认的构造函数
    // 第二个错误：析构函数也可能回调多次，如果说在析构函数中释放内存，需要在拷贝构造函数中进行深拷贝
    vector<Person> vector1;

    Person person("eastrise");

    // 会调用对象的拷贝构造函数，存进去的是另一个对象
    vector1.push_back(person);

    person.setName("Jack");

    Person p1 = vector1.back();

    cout << p1.name.c_str() << endl;
}*/

/*class Compare{
    // 重载了括号操作符
public:
    void operator()(){
        cout << "仿函数" << endl;
    }
};

void compare1(){
    cout << "普通函数" << endl;
}

// 4. 函数对象（仿函数） 一元谓词，二元谓词
int main(){
    Compare compare;

    // 跟函数非常类似
    compare();
    // 普通函数调用
    compare1();
}*/

// 一元谓词
/*void print(int number){
    cout << number << endl;
}

// 仿函数 - 一元谓词（能够记录状态）
class PrintObj{
public:
    int count = 0;
    void operator()(int number){
        cout << number << endl;
        count ++;
    }
};

// 回调函数和仿函数的区别
int main(){
    set<int> set1;

    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(4);

    // for_each 迭代器，非常重要的一点就是：仿函数如果要保存记录状态，要确保对象一致，可以用返回值
    // for_each(set1.begin(),set1.end(),print);
    PrintObj printObj;
    printObj = for_each(set1.begin(),set1.end(),printObj);
    cout << "个数：" << printObj.count << endl;
}*/

// 二元谓词
class CompareObj{
public:
    int count = 0;
    bool operator()(const string str1,const string str2){
        return str1 < str2;
    }
};

int main(){
    // 二元谓词的仿函数
    set<string,CompareObj> set1;
    set1.insert("aaa");
    set1.insert("aAa");
    set1.insert("ccc");
    set1.insert("ddd");
    // 是否包含 aaa ， 遍历比较 ， 找方法
    for(auto it = set1.begin();it != set1.end(); it ++){
        cout << (*it).c_str() <<  endl;
    }
}
