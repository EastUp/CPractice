#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*void change1(int number){ // 不能修改
    number = 300;
    printf("%p\n",&number);
}

void change2(int* number){ //  可以
    *number = 300;
}

int main(){
    int a = 100;

    // 修改 a 的值

    a = 200;
    printf("%p\n",&a);

    change1(a); // a变量的值复制给了 number 变量，number 是在另一个函数中，number 是一个新的变量
    printf("change1：a = %d\n",a); // a = 200

    change2(&a); //  a 的地址复制给了 number 变量，number 是在另一个函数中，number 是一个新的变量

    printf("change2：a = %d\n",a); // a = 300;

    // getchar();
};*/

/*void changeNumber(int* number){
    *number = 300;
}

// 2. 指针间接赋值的意义
int main(){
    // 通过指针去修改值

    int number = 100;

    // 在同一个方法里面，直接复制
    number = 200;

    // 通过指针取赋值，其实就是为了在其它方法中去间接赋值
    // int* p = &number;
    // *p = 300;
    changeNumber(&number);

    // 在做开发的时候，离不开指针，指针出现的意义有很多，其中一种就是通过方法去修改值
    // 1.获取Bitmap信息
    // AndroidBitmapInfo android_bitmap_info; // 结构体
    // AndroidBitmap_getInfo(env,bitmap,&android_bitmap_info);// 通过 getInfo 方法去获取 Bitmap 的属性
    // 获取Bitmap的 宽，高，format
    // int bitmap_width = android_bitmap_info.width;
    // int bitmap_height = android_bitmap_info.height;

    // c 和 java 的方法不同所在，c 可以传对象的地址在方法里面去赋值，java 一般都是通过返回值

    // 模拟一下指针方法赋值的写法（很常用）
    // java 写法
    // AndroidBitmapInfo android_bitmap_info = AndroidBitmap_getInfo(env,bitmap);
    // c 的写法 就在上面
    printf("%d",number);

    // 试用期的分数 100 60分业务逻辑 15分框架维护 10分小游戏框架的维护 15分架构的性能优化 50fps 60fps 优化包的体积

    // getchar();
}*/

/*struct AndroidBitmapInfo{
    int width;
    int height;
    int format;
} info;// 定义了一个结构体变量 info info 会有初始值*/

/*typedef struct AndroidBitmapInfo{
    int width;
    int height;
    int format;
};// 定义了一个结构体取了一个别名 AndroidBitmapInfo,结构体的名字就是 匿名

void AndroidBitmap_getInfo(AndroidBitmapInfo* bitmapInfo){
    // 通过指针的方法在里面赋值
    bitmapInfo->width = 200;
    bitmapInfo->height = 200;
}

// 模拟 AndroidBimap_getInfo

int main(){
    // 通过指针间接赋值很常见（堆内存上开闭）
    AndroidBitmapInfo* androidBitmapInfo = (AndroidBitmapInfo*)malloc(sizeof(AndroidBitmapInfo));
    AndroidBitmap_getInfo(androidBitmapInfo);

    printf("width = %d,height = %d",androidBitmapInfo->width,androidBitmapInfo->height);

    // 释放
    if(androidBitmapInfo){
        free(androidBitmapInfo);
        // 避免出现野指针的情况，减少程序代码的出错
        androidBitmapInfo = NULL;
    }

    // 这个地方写了 n 行代码，省略 n 行
    // 再次释放，会有问题
    if(androidBitmapInfo){
        free(androidBitmapInfo);
    }

    getchar();
}*/

/*int main(){
    // 写入位置 0x00000000 时发生访问冲突
    char* p1 = NULL; // p1 = NULL,NUll 也是地方，指针指向 NULL 相当于指向 0x00000000

    // 但是我们不能对 0x00000000 去操作，这块地方是 c 和 c++ 编译器所持有的

    // Student student = null; 不用纠结 null 是啥，跟 c 和 c++ 有点类似

    strcpy(p1,"1122");

    getchar();
}*/

// 做字符串的强化
/*int main(){
    // char buff[100] = {'e','a','s','t','r','i','s','e'};// 后面 8 - 99 都是默认值 0
    // char buff[5] = {'e','a','s','t','r'};
    // char buff[] = {'e','a','s','t','r'}; // 长度是 12（'\0'）, size 是 5（默认统计里面的个数）
    // char buff[2] = {'e','a','s','t','r'}; // 编译不通过，长度超出
    // char buff[100] = { 0 }; // 把数组初始化为 0
    // char buff[100] 数据都是默认值 -52

    //  char buff[] = "123456"; // len 是 6（'\0'）,size 是 7 ？
    // 相当于 char buff[] = {1,2,3,4,5,6,\0}
    char* buff= "123456"; // len==6, size==8

    // 纠结一下 char buff[] = "123456" 和 char* buff= "123456"; malloc 的方式 啥区别 ？
    // 字符串可以在任何地方开辟内存，栈区，堆区，常量区

    // 大小 size 100
    int len = strlen(buff);// len 5 碰到 '\0' 就结束了
    int size = sizeof(buff);

    printf("len = %d , size = %d\n",len,size);

    // 内容
    printf("%d,%d,%d,%d",buff[0],buff[66],buff[99],buff[77]);

    getchar();

}*/

// 设计一个获取 Bitmao 属性的函数，请问怎么设计？（重点）
// 1. 确定你的参数，传递指针
// 2. 一定要考虑健壮性
// 3. 要异常错误进行抛出说明 萤视频 ffmpeg
// 4. 不要直接轻易的去改变调用传递给你的指针，打个比方

/*struct AndroidBitmapInfo{
    int width;
    int height;
    int format;
}; // 定义一个结构体：AndroidBitmapInfo

int AndroidBitmap_getInfo(AndroidBitmapInfo* bitmapInfo){

    // 对 bitmapInfo 进行再次赋值

    // 2.一定要考虑健壮性，自己的方法会报错
    if(!bitmapInfo){
        // 3. 要异常错误进行抛出说明， 音视频  ffmpeg
        printf("bitmapInfo 是 NULL 无法进行操作，错误码 %d",-1);
        return -1;
    }
    // 可能还会有 -xx

    // 通过指针在方法里面赋值
    bitmapInfo->width = 200;
    bitmapInfo->height = 200;
    return 0;// 一般 0 代表正常情况
}

// 模拟 AndroidBitmap_getInfo
int main(){
    // 通过指针间接赋值很常见（堆内存上开闭）
    struct AndroidBitmapInfo* androidBitmapInfo = (AndroidBitmapInfo*)malloc(sizeof(AndroidBitmapInfo));

    // 释放后再调用
    int res = AndroidBitmap_getInfo(androidBitmapInfo);

    if(res == 0){
        // ...
        // 会出错，调用者也会报错，但我并不知道错误所在
        printf("width = %d , height = %d",androidBitmapInfo->width,androidBitmapInfo->height);
    }

    // 释放
    if(androidBitmapInfo){
        free(androidBitmapInfo);
        // 避免出现野指针的情况，减少程序代码的出错
        androidBitmapInfo = NULL;
    }

    getchar();
}*/

// 4. 不要直接轻易的去改变调用传递个ini的指针  打个比方
int strlen(char* const str){
    // 临时变量，套路
    char* countStr = str;

    int count = 0;
    while(*countStr){ // != '\0'
        countStr ++;
        count ++;
    }

    // 自己想想看结果对不对
    printf("str = %s,len = %d \n",str,count);

    return count;
}

int main(){
    char* str = "123456";

    int len = strlen(str);

    printf("len = %d",len);

    getchar();
}













