class Student{ // 结构体类似
private: // 私有，包装，影响下面所有的属性
    char* name;
    int age;

public:
    void setAge(int age);

    void setName(char* name);
    // private： // 影响到下面的所有方法

    int getAge();

    char* getName();
};