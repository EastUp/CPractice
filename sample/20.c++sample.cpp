#include <iostream>

using namespace std;

template <typename T>
T add(int number1, int number2){
    cout << "模板函数被调用" << endl;
    return number1+number2;
}

// 打算生成 3 个方法， 发现有一个 int 函数就不会额外生成（因为自己写了普通的函数），发现 double float 没有，就会生成两个

// 汇编代码 xposed 调试
// 1. 编译的时候 c 和 c++ 编译器会对 cpp/c 文件做一些优化（模板函数）
// 2. java 有 samll -> class，也会生成 c/c++ 编译器能够忍受的一套代码 public:void _thiscall Activity::initView(void)
// 3. 生成二进制文件 .obj .o 等等一些文件，链接其他模板 cmake 中一些链接
// 4. 最后就会可执行文件 .dll、.so、.exe

/*class Activity{
public:
    void initView();

    void initData();
};

class MainActivity : public Activity{
public:
    void initView(){

    }
};

// 当普通函数和模板函数同时存在时，优先会调用普通函数
// 普通函数
int add(int number1,int number2){
    cout << "int add 被调用" << endl;
    return number1+number2;
}

// so 是很难被反编译，比 java 安全为啥
// samll 语法

int main(){
    int sum1 = add(1,2);

    double sum2 = add(1.0,2.0);

    float sum3 = add(1.0f,2.0f);

    cout << sum1 << " , " << sum2 << endl;
}*/

// 2. 模板类 语法啊，跟模板函数非常相似
template <class T>
class Callback{
public:
    void onError(){

    }

    void onSucceed(T result){
        cout << result << endl;
    }
};

// 模板类继承
// 如果子类不是模板类
/*class HttpCallback : public Callback<int>{

};*/

// 子类还是模板类
template <typename T>
class HttpCallback : public Callback<T>{

};

int main(){
    Callback<int>* callback = new HttpCallback<int>();

    callback -> onSucceed(15);
}





