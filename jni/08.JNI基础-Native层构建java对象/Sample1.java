package com.east.jni08;

import java.util.UUID;

public class Sample1 {
    public static void main(String[] args) {
        // callStaticMethod();

        // c 层创建对象
        Point point = createPoint();

        System.out.println("point：x = "+point.getX()+" , y = "+point.getY());
    }

    private native static Point createPoint();

    private native static void callStaticMethod();

    // 小的思考：静态获取 uuid 的方法，然后再 c 调用这个方法获取uuid
    public static String getUUID() {
        return UUID.randomUUID().toString();
    }

    public static Point test(int x, int y){
        return null;
    }

    static {
        System.load("E:\\VSProjects\\08jni\\x64\\Debug\\08jni.dll");
    }
}
