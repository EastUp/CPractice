#include <stdio.h> // 导入头文件 都是方法的声明 .h .hpp 里面都是方法的声明；.cpp （c++） .c  都是方法的实现

/*int main() { //函数的主入口
    printf("hello world"); // printf C的打印输出
    getchar();
}*/

// 基本数据类型
/*int main(){
    int i = 100;    // 占位符d
    double d = 200; // 占位符lf
    float f = 200;  // 占位符f
    long l = 100;  // 占位符ld
    short s = 100; // 占位符d
    char c = 'D';  // 占位符c
    // 字符串 char*

    // 输出打印 ， 要用占位符
    printf("i 的值是：%d\n",i);
    printf("d 的值是：%lf\n",d);
    printf("f 的值是：%f\n",f);
    printf("l 的值是：%ld\n",l);
    printf("s 的值是：%d\n",s);
    printf("c 的值是：%c\n",c);

    getchar();
}*/

// 变量的地址：任何的数据（变量）都会有地址（住址门牌号）
/*int main(){
    int i = 100;
    // &i & 代表变量的地址
    // 通过 debug 的调试，我们可以根据地址去查下该地址的数据 int 4 字节 sizeof() 获取数据类型所占的字节数
    printf("i 的地址是：%p",&i);

    getchar();
}*/

/*int main(){
    printf("int 数据类型所占的字节数：%d\n",sizeof(int));// int 数据类型所占的字节数：4
    printf("double 数据类型所占的字节数：%d\n",sizeof(double));// double 数据类型所占的字节数：8
    printf("char 数据类型所占的字节数：%d\n",sizeof(char));// char 数据类型所占的字节数：1

    getchar();
}*/


// 指针变量和获取地址的值
/*int main(){
    int i = 100;
    double d = 200;

    printf("i的值是：%d\n",i); // i的值是：100
    // 通过 * 获取地址的值
    printf("i的值是：%d\n",*(&i)); // i的值是：100

    //指针（地址）变量 指针存放（指向）的就是变量的地址
    // int* 代表的是 int 类型的指针 （地址）
    int* p = &i;
    // double* p1 = &d;
    printf("i的值是：%d\n",*p); // i的值是：100

    getchar();
}*/

 // 通过指针修改值
/*int main(){

	int i = 100;

	int* p = &i;

	i = 200;

	printf("i的值是：%d\n",i); // i的值是：200

	// 还有一种方式：获取指针的值进行间接的修改
	*p = 300;
	printf("i的值是：%d", i); // i的值是：300

	getchar();
}*/

/*void change(int i){// 这个 i 是另外一个
	printf("change 中i的地址是：%p\n",&i);
	i = 200;
}
// 通过地址来修改
void change(int* p){
	printf("change中i的地址是：%p\n",p);
	*p = 200;
}

// 通过方法修改值
int main(){
	int i = 100;
	printf("i的地址是：%p\n", &i);
	printf("i的值是：%d\n", i);

	change(&i);

	printf("i修改后的值是：%d\n", i);
	getchar();
}*/

// 题目：写个方法对两个值进行交换
/*void change(int* a,int* b){ // 2 面试题：对 a,b 两个值进行交换，但是不开辟额外的内存（不能用中间变量）
    // 大家在这里面写
    int temp = *a;

    *a = *b;// a的值 = b 的值

    *b = temp;
}
int main(){
    int a = 100;
    int b = 200;
    // 交换
    // change(&a,&b);

    a = a + b;// a = 300
    //a = a - b;
    b = a - b;// b = 200
    a = a - b;// a = 100


    printf("交换后ab的值分别是：%d,%d",a,b); // 交换后ab的值分别是：200,100

    getchar();
}*/

int main(){
    int a = 100;
    int b = 200;

    // a = b 把b变量的值复制给a
    printf("a,b的地址分别是：%p,%p\n",&a,&b); // a,b的地址分别是：000000000060FE0C,000000000060FE08

    int* p1 = &a;// p1 是一个变量而已
    int* p2 = &b;

    // p1 = p2 是什么意思，有点类似于 a = b ；p1 和 p2 只是一个变量而已；
    p1 = p2;// 只是p1 的变量指向改成了指向b的地址，并没有改动 a 的地址

    printf("a,b的地址分别是：%p,%p\n", &a, &b); // a,b的地址分别是：000000000060FE0C,000000000060FE08
    getchar();
}



