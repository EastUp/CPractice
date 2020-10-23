#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 字符串定义
/*int main(){
    // 第一种 字符串数组
    char str[] = {'E','a','s','t','r','i','s','e','\0'};

    str[2] = 'y';

    printf("%s\n",str); // 字符串结尾必须是 '\0'，开辟内存也需要多开辟一个

    // 第二种 不加 const 会警告：deprecated conversion from string constant to 'char*'
    // 原因：
    //      "Eastrise"是字符串常量, 内存分配在全局的const内存区
    //       char * 声明了一个指针，而这个指针指向的是全局的const内存区，const内存区当然不会让你想改就改的。所以，如果你一定要写这块内存的话，那就是一个非常严重的内存错误。
    const char *str1 = "Eastrise";

//    str1[2] = 'y';

    printf("%s\n",str1);

    // 两种定义的区别：一个能修改，一个不能修改

}*/

/*int strlen_(const char *str){
    // 怎么获取字符串的长度？ 不断读取字符，判断末尾 '\0'

    int len = 0;
    while (*str != '\0'){
        len ++;
        str ++;
    }
    return len;
}

// 字符串长度获取
int main(){
    const char *name = "Eastrise is";

    const char str[] = {'E','a','s','t','r','i','s','e','\0','i','s'};

    printf("name length is %d\n",strlen(name));

    // 怎么获取长度？有一种方式计算（不好使）
    // printf("length is %d",sizeof(str)/sizeof(char));

    // 自己来写一个方法读取字符串的长度
    // strlen_(name);
    printf("name length is %d",strlen_(name));
}*/

// 字符串的转换
/*int main(){

     const char* num1 = "1"; // -> int float double
     const char* num_str1 = "12.0xxx";
     int number1 = atoi(num_str1); // 如果不能转换就是 0 ，后面如果有其他不适数字的就会被剔除 12xxx -> 12
    printf("number1 is %d\n",number1);

     const char* num_str2 = "12.5f";
     float number2 = atof(num_str2); // 如果不能转换返回的是默认值 0.0000
    printf("number2 is %f\n",number2);

    const char *num_str3 = "12.5xx";
    double number3 = strtod(num_str3,NULL);// 如果不能转换就是 0.000 ，后面如果有其他不适数字的就会被剔除 12.5xxx -> 12.5000

    printf("number3 is %lf\n",number3);
    getchar();
}*/

//字符串的比较
/*int main(){
    const char* str1 = "Eastrise";
    const char* str2 = "eastrise";

    // 大于小于等于
    // int rc = strcmp(str1,str2); // 区分大小写比较
    // int rc = _strcmpi(str1,str2); // 不区分大小写比较 c strcmpi c++ _strcmpi , android ndk strcasecmp;

    // 比较前几个
//     int rc = strncmp(str1,str2,7); // count 达标的是比较字符串前几个是否相等
    int rc = _strnicmp(str1,str2,6); // 不区分大小写的比较
    if(rc == 0) {
        printf("相等");
    }else{
        printf("不相等");
    }

    getchar();
}*/

// 字符串查找，包含
/*int main() {

    const char *str = "name not Eastrise";
    const char *substr = "E";
    char *pos = strstr(str, substr); //  返回的是字符串第一次出现的位置（位置指针），如果没有找到返回的是空
    printf("%s\n", pos); // Eastrise;
    // 求一下位置 int 怎么办？ strstr
    int position = pos - str;

    printf("第一次出现的位置是：%d\n", position);

    // 包含？ pos 是不是空就可以了
    if (pos)
        printf("%s", "包含");
    else
        printf("%s", "不包含");

    getchar();
}*/

// 拼接，截取，大小写转换
/*int main(){

    //strcopy; copy进来
    const char* str = "eastrise";

    const char* str1 = " is";

    // char* str1 = "is";
    // int len = strlen(str); // cpy[len] android studio 是可以的
    char cpy[strlen(str)+strlen(str1)];

    // str 会 copy 到 cpy 里面
    strcpy(cpy,str);

    printf("%s\n",cpy);

    //拼接
    strcat(cpy,str1);

    printf("%s",cpy);

    getchar();
}*/


// 截取
/*char* substr(const char* str,int start ,int end){
    // 开辟一个字符串去存储我们的数据，开辟多大计算
    // char sub[end -start];
    int len = end - start;
    char* sub = (char*)malloc(sizeof(char)*(len+1));// 记得+1，因为还有一个\0，在 NDK 一般会采用静态的数组存储 char sub[len]
    // malloc 一定要 free

    // 遍历赋值
    for(int i = 0; i< len; i++){
        sub[i] = str[start+i];
    }
    // 标记字符串结尾，否则 print 无法判断结尾
    sub[len] = '\0';

    printf("%p\n",sub);

    // free(sub);

    return sub;
}

// 字符串的截取
int main(){
    const char* str = "Eastrise is";

    // 截取第三个位置到第五个位置 3,5
    char* sub = substr(str,0,5);

    printf("%p\n",sub);

    printf("%s",sub);

    // 一定要free ，因为你的 substr 有动态开辟内存，但是真正开发中并不会这么做，自己的方法尽量要自己处理好内存
    free(sub);

    getchar();
}
*/

// dest 用来存放结果， 大小自己指定
// source 需要转换的字符串
/*void lower(char* dest,const char* source){
    while (*source != '\0'){
        // 拿当前字符
        char ch = *source;
        // 转换完成后赋值给 dest
        *dest = tolower(ch); // a->a A->a
        source++;
        dest++;
    }
    // 标记字符串结尾
    *dest = '\0';
}

//大小写转换
int main(){
    const char* name = "EASTRISE";
    char dest[20];

    lower(dest,name);

    printf("%s",dest);

    getchar();
}*/

// 大写转换
/*void upper(char* dest,const char* source){
    while (*source != '\0'){
        char ch = *source;
        *dest = toupper(ch);
        source ++;
        dest ++;
    }

    *dest = '\0';
}

//大小写转换
int main(){
    const char* name = "eastrise";
    char dest[20];

    upper(dest,name);

    printf("%s",dest);


    getchar();
}*/



char *substr(const char *str, int start, int end) {
    // 开辟一个字符串去存储我们的数据，开辟多大计算
    // char sub[end -start];
    int len = end - start;
    if (len == 0) {
        return nullptr;
    }
    char *sub = (char *) malloc(sizeof(char) * (len + 1));// 记得+1，因为还有一个\0，在 NDK 一般会采用静态的数组存储 char sub[len]
    // malloc 一定要 free

    // 遍历赋值
    for (int i = 0; i < len; i++) {
        sub[i] = str[start + i];
    }
    // 标记字符串结尾，否则 print 无法判断结尾
    sub[len] = '\0';

    printf("%p\n", sub);

    // free(sub);

    return sub;
}


char *str_replace(const char *str, const char *src, const char *dst) {
    char *pos = strstr(str, src);
    if (!pos)
        return const_cast<char *>(str);

    // 1. 计算新的数组大小
    char result[strlen(str) - strlen(src) + strlen(dst)];

    // 截取替换
    int start_position = pos - str;
    char *start = substr(str, 0, start_position);
    char *end = substr(str, start_position + strlen(src), strlen(str));

    // 拼接
    if (start){
        strcpy(result, start);
        strcat(result, dst);
        free(start);
        if (end){
            strcat(result, end);
            free(end);
        }
    }else{
        strcpy(result, dst);
        if (end){
            strcat(result, end);
            free(end);
        }
    }

    return str_replace(result, src, dst);
}

// 字符串替换
int main() {
    char *str = str_replace("aabbaabbfffaa", "aa", "ccc");

    printf("%s", str);

    getchar();
}










