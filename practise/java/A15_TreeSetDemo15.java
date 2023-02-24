package cn.edu.cwnu.cs.lqr01;

import java.util.TreeSet;

/**
 * @author: Li Qinru
 * @Date: 2022/11/30 9:50 PM
 */
public class A15_TreeSetDemo15 {
    public static void main(String[] args) {

        Student s1 = new Student("Zhangsan",23);
        Student s2 = new Student("Lisi",25);
        Student s3 = new Student("Wangwu",22);

        TreeSet<Student> ts = new TreeSet<>();

        ts.add(s1);
        ts.add(s2);
        ts.add(s3);

        System.out.println(ts);

    }
}
