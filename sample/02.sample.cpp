#include <stdio.h>

//二级指针和多级指针
/*int main(){
    int num = 12;
    // int* 指针  & 取地址
    int* p = &num;

    int** s_p = &p; // 对一级指针取地址

//    int*** s_s_p = &s_p; // 多级指针

    printf("p 的值是：%p, s_p 的值是：%p\n",p,s_p);
    // p的地址是000000000060FE14 里面存的值为 12
    // s_p的地址是000000000060FE08 ，里面存的值是 000000000060FE14

    // 通过二级指针获取值
    printf("获取最终的值是：%d",**s_p);

    getchar();// 暂停
}*/

// 数组和数组指针 （重点）
/*int main(){
    // 定义数组
    int arr[] = {1,2,3,4};

    //遍历数组，linux 就有问题
    for(int i = 0; i<4 ; i++){
        printf("%d\n",arr[i]);
    }

    // for 循环在 c 和 c++ 中的正确写法
    int i = 0;
    for(; i < 4; i++){
        printf("%d\n",arr[i]);
    }

    // 看一种现象：arr 的值 = arr 取地址的值 , arr 地址的值 = arr[0]的地址的值（首地址）
    printf("arr = %p\n",arr); // arr = 000000000060FE00
    printf("&arr = %p\n",&arr); // &arr = 000000000060FE00
    printf("&arr[0] = %p\n",&arr[0]); // &arr[0] = 000000000060FE00

    // 如何获取数组的指针
    int* arr_p = arr;// 数组指针指向的是数组的首地址

    // 做一系列的操作
    printf("%d\n",*arr_p); // 1

    // 对指针进行 ++
    arr_p++;

    printf("%d\n",*arr_p); // 2

    // 指针再往后挪动两位
    arr_p += 2;

    printf("%d\n",*arr_p); // 4

    getchar();
}*/

// 采用指针遍历数组循环赋值
/*int main(){
    int arr[] = {1,2,3,4};

    int* arr_p = arr;

    int i = 0;
    for (; i < 4; i++) {
        printf("位置%d的值是：%d\n",i,*(arr_p+i));
    }

    getchar();
}*/

/*int main(){
    int arr[4]; // 指定数组[4]

    int* arr_p = arr;

    int i = 0;
    for(; i< 4; i++){
        *(arr_p + i) = i;
    }

    i = 0;
    for(; i< 4; i++){
        printf("位置%d的值是：%d\n",i,arr[i]);
    }
    getchar();
}*/

// 数组指针的几种操作方式
/*int main(){

    int arr[] = {1,2,3,4};

    int* arr_p = arr;

    int i = 0;
    for(; i < 4; i++){
        printf("使用arr_p[i]算出位置%d的值是：%d\n",i,arr_p[i]); // == *(arr_p+i)
        printf("使用*(arr + i)算出位置%d的值是：%d\n", i, *(arr + i));
    }

    getchar();
}*/

// 指针为什么要有类型？指针其实就是一块地址而且他的值都差不多
/*
int main(){

    int num = 12;

    int* num_p = &num;

    printf("%p",num_p);

    // double* num_p_d = num_p;

    // 取值的时候我要知道怎么取，指针偏移。

    getchar();
}
*/

// 函数指针（回调）
/*void add(int num1,int num2){
    printf("num1 + num2 = %d\n",num1 + num2);
}

void mins(int num1,int num2){
    printf("num1 - num2 = %d\n",num1 - num2);
}

// 方法指针， 传两个数
void operator1(void(method)(int,int),int num1,int num2){
    method(num1,num2);
}

int main(){
    //add(1,2);

    // 方法指针怎么定义？ 方法的返回（*方法的名称）（方法的参数）
    operator1(add,1,2);  // 3
    operator1(mins,1,2); // -1

    getchar();
}*/

// 监听数据压缩回调
/*void call_back(int current,int total){
    printf("压缩的进度是：%d/%d\n",current,total);
}

// 这个方法 3 ，他是一个额外的文件了
void compress(char* file_name,void(*call_back)(int,int)){
    call_back(12,24);
}

int main(){

    void(*call)(int,int); // 声明了一个函数
    call = call_back; // 给函数指针赋值

    // call(1,2) 通过函数指针间接的调用call_back
    compress("1.png",call);

    getchar();

}*/

//函数指针
void print(){
    printf("打印");
}

void method(void(print)()){
    print();
}

int main(){
    void(*ssd)() = &print;
//    void(*ssds)() = print;
    method(ssd);
}



