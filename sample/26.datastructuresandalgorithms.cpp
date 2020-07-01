#include <iostream>
using namespace std;

// 比如我们现在 求 1+2+3+4+***+n
// 任何算法在特定执行的 n 步骤下，我们都可以推演出算法的复杂度（时间，空间）
// 简单的理解为执行的步骤
int sum1(int n){// n + 2 步 O(n)
    int sum = 0; // 1步
    for (int i = 0; i <= n ; ++i) { // n 步
        sum += i;
    }
    return sum;// 1步
}

int sum2(int n){ // O(1)
    return (1+n)*n / 2; // 1步
}

// 空间复杂度 反转一个字符串 aaa222bbb -> bbb222aaa
char* reverse1(char str1[],int n){ // O(n)
    // 第一种写法
    // 创建一个新的数组
    char* res = (char*)malloc(sizeof(char)*n);

    // 倒序循环
    for(int i = n - 1; i >=0; i--){
        // 赋值
        res[n - 1 - i] = str1[i];
    }

    return res; // 1
}

void reverse2(char str[],int n){// 空间复杂度是 O(1) 时间复杂度是 O(n)
    int mid = n / 2;
    for(int i = 0; i < mid; i++){
        // i 的位置和 i+mid 的位置进行交换
        // 交换 1 次交换是两次赋值
    }
}

/*int main(){
    // int sum = sum2(100);

    // cout << "sum = " << sum << endl;
    int n = (int)'b'; // a = 97
    // 'z' 122
    cout << n << endl;
}*/

// 读一篇英文文档统计字符出现的个数
int main(){
    // 一个字符一个字符的读过来
    char* str = "zxcvbnmsdfghjklertyuiop tyuiocvbnm";

    // 开辟一块内存大小的数组
    int aisc[123] = {0};

    // 当我读到一个字符, a , b
    int index = (int)'d';
    aisc[index]++;

    // 最后一个for循环输出，变种 2000 个数字（1,2000）
}

// 数组与链表源码分析
// C++基础 - 实现 Native 层的 ArrayList


