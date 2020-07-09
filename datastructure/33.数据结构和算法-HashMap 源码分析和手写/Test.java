package com.east.datastructure33hashmap;

import java.util.Objects;

public class Test {
    public static void main(String[] args) {

        HashMap<Student,Integer> map = new HashMap<Student, Integer>();

        for (int i =0; i < 25; i++){
            map.put(new Student("east"+i),i);
        }

        System.out.println(map.get(new Student("east2")));

        System.out.println("size = "+map.size() + "数组长度：table.length = "+map.table.length);

    }

    static class Student{
        String name;

        public Student(String name) {
            this.name = name;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Student student = (Student) o;
            return Objects.equals(name, student.name);
        }

        @Override
        public int hashCode() {
            return Objects.hash(name);
        }
    }
}
