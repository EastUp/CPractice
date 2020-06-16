#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*struct Worker{ // 定义一个结构体， 相当于 java 的 class
    char name[10];
    int age;
    double salary;
};*/

// 第二种方式，可以直接取名字
/*struct Worker{ // 定义一个结构体， 相当于 java 的 class
    char name[20];
    int age;
    double salary;
}eastrise = {"Eastrise",25,1000},jack; // 这种方式会有一个默认的初始值,jack会有默认初始值

// 1. 结构体的定义和使用
// char* 不算基本数据类型
int main(){

    struct Worker worker; // 初始化，没有初始化的情况下，那么里面所有的属性都是没有初始值的，salary

    // 赋值
    worker.age = 24;
    // worker.name = "Eastrise";
    strcpy(worker.name,"JACK");

    // jack.name = "Jack";
    strcpy(jack.name,"JACK");
    jack.age = 24;

    printf("name = %s, age = %d, salary = %lf",eastrise.name,eastrise.age,eastrise.salary);
    getchar();
}*/

/*struct Work{
    char name[10];
    char grade[10];
};

// 第三种方式,结构体嵌套
struct Worker{ // 定义一个结构体， 相当于 java 的 class
    char name[10];
    int age;
    double salary;

    //工作, name gradle
    Work work;
};*/

// 第四种方式，结构体嵌套
/*struct Worker { // 定义一个结构体， 相当于 java 的 class
    char name[10];
    int age;
    double salary;

    struct Work{
        char name[10];
        char grade[10];
    }work;

    // 工作， name grade
    // Work work;
};*/

/*int main(){
  struct Worker worker = {"Eastrise",25,1000,{"Android","中级"}}; // 嵌套的初始

  printf("name = %s, grade = %s",worker.work.name,worker.work.grade);

  getchar();
}*/

// 2. 结构体指针和动态内存开辟
/*int main(){
    struct Worker worker = {"eastrise",25};
    Worker* worker_p = &worker;

    // 通过结构体指针去操控数据
    // worker.age = 24;
    worker_p -> age = 24; // 结构体操作的另外一种方式， 一般这种比较常用
    strcpy(worker_p->name,"Jack");

    printf("name = %s, age = %d",worker_p->name,worker_p->age);

    getchar();
}*/

/*struct Worker{ // 定义一个结构体， 相当于 java 的 class
    char name[10];
    int age;
    double salary;

    //工作, name gradle
    // Work work;
};

int main(){
    // Worker* worker;// 创建了一个结构体指针， 指针没有初始化？
    Worker* worker = (Worker*)malloc(sizeof(Worker));
    worker->age = 26;
    strcpy(worker->name,"Jamin");

    printf("name = %s, age = %d",worker->name,worker->age);

    // 释放
    if(worker){
        free(worker);
        worker = NULL;
    }

    getchar();
}*/

/*struct Worker{ // 定义一个结构体， 相当于 java 的 class
    char name[20];
    int age;
    double salary;
};

// 结构体的数组
int main(){
    // 插件结构体数组，第一种
//    Worker worker[10] = {{"Eastrise",25,1000},{},{},{}}; // 创建了 10 个，静态开辟
//
//    worker[9] = {"Eastrise",26,1000};
//
//    printf("name = %s ,age = %d\n",worker[9].name,worker[9].age);

    // 动态内存开辟 Worker* 结构体的指针
    Worker* worker = (Worker*)malloc(sizeof(Worker)*10);

    strcpy(worker->name,"Eastrise");
    worker->age = 10;

    // 对第十个数据进行操作
    worker += 9;
    strcpy(worker->name,"Eastrise9");
    worker->age = 9;
    free(worker);
    printf("name = %s，age = %d",worker->name,worker->age);

    getchar();
}*/

// 3. 结构体大小计算（字节对齐）
/*struct Worker{ // 定义一个结构体， 相当于 java 的 class
    char name[10]; // 10
    int age; // 4
    double salary; // 8

    // char name[10] 24, char name[18] 32
    // 32 怎么来的？ 18 + 4 + 8 = 30,32
};

int main(){
    int size = sizeof(Worker); // 16字节
    // 计算的规则：
    // 1. 按照最大的字节去计算
    // 2. 算得时候只会按照基本数据类型去算
    // 3. 首先会把所有字节数加起来， 是否能够整除最大属性的字节数，如果不够会往上累加，一直加到能整除的位置

    printf("size = %d \n",size);
    getchar();
}*/

/*struct date{ // 12
    int year;
    int month;
    int day;
};

struct student{
    int number; // 4
    char sex; // 1
    int age; // 4
    char name[10]; // 10
    struct date birthday; // 12

    // 31%4  32%4 32个字节？
};

int main(){
    int size = sizeof(student); // 36字节
    // 计算的规则：
    // 1. 按照最大的字节去计算
    // 2. 算得时候只会按照基本数据类型去算
    // 3. 首先会把所有字节数加起来， 是否能够整除最大属性的字节数，如果不够会往上累加，一直加到能整除的位置
    // 4. 进阶，留下一个思考

    printf("size = %d \n",size);
    getchar();
}*/

// 4. 结构体和结构体指针取别名
/*struct Worker_{// 定义一个结构体，相当于 java 的 class
    char name[10];
    int age;
    double salary;
};

typedef Worker_ Worker_;
// 对结构体的指针取别名
typedef Worker_* Worker;

int main(){
    Worker worker = (Worker_*)malloc(sizeof(Worker_));

    printf("%s,--> %d,---> %lf",worker->name,worker->age,worker->salary);

    getchar();
}*/

// 定义一个 联合体
/*union Person{
    // 最多出现一个，不用累加，找最大值 10， 16字节，需要能被最大的基本数据类型double 整除才行
    char name[10]; // 10
    int age; // 4
    double salary; // 8
};

// 5. 联合体的定义和使用，联合体只能存在一个，要么是 age ，要么是name
int main(){
    Person person = {"Eastrise"};
    // Person person;

    // strcpy(person.name,"Eastrise");
    // person.age = 25;

    // printf("name = %s,age = %d\n",person.name,person.age);
    printf("%d",sizeof(Person)); // 16，是否够 double 整除

    getchar();
}*/

// 6. 联合体大小计算（不用累加，取最大值，最终是否够基本数据类型整除）

// 7. 枚举的定义和使用 枚举有点类似于 int
/*
enum CommentType{
    TEXT = 10,TEXT_IMAGE,IMAGE
};

int main(){
    CommentType commentType = TEXT; // 10
    CommentType commentType1 = TEXT_IMAGE; // 11
    CommentType commentType2 = IMAGE; // 12

    printf("%d,%d,%d",commentType,commentType1,commentType2);

    getchar();
}
*/










