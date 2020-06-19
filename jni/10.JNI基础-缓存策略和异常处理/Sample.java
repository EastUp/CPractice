package com.east.jni10;

public class Sample {
    private static String name; // 一大堆变量
    private static String name1; // 一大堆变量
    private static String name2 ; // 一大堆变量

    static {
        System.load("E:\\VSProjects\\10jni\\x64\\Debug\\10jni.dll");
    }

    public static void main(String[] args) {
        // 1. 数组的一些细节

//        int[] arr = {11,22,-3,2,4,6,-15};
//
//        sort(arr);
//
//        for(int i = 0; i < arr.length; i++){
//            System.out.println(arr[i]+"\t");
//        }

        // 2. 局部引用和全局引用

        // localRef();

//        saveGlobalRef("Eastrise");
//
//        System.out.println(getGlobalRef());
//        // 合适的时机去释放
//        deleteGlobalRef();
//        // 再次获取
//        System.out.println(getGlobalRef()); //因为已经删除 所以获取不到了

        // 3.缓存策略 static, native层有一大堆方法需要去获取 name 属性 // 初始化全局静态缓存
//        initStaticCache();
//
//        staticLocalCache("Eastrise");
//
//        System.out.println("name = "+name);
//
//        staticLocalCache("Jack"); // not null
//
//        System.out.println("name = "+name);
//
//        staticLocalCache("Rose"); // not null
//
//        System.out.println("name = "+name);

        // 异常处理（简单讲，C++异常）
        try {
            exception();
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        }

        System.out.println("name3 = "+name);

    }

    private native static void sort(int[] arr);

    private native static void localRef();

    private native static void saveGlobalRef(String value);

    private native static String getGlobalRef();

    private native static void deleteGlobalRef();

    private native static void staticLocalCache(String value);

    private native static void initStaticCache();

    private native static void exception() throws NoSuchFieldException;

}
