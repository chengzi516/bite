package cn.edu.cwnu.cs.lqr01;

import java.util.HashSet;

/**
 * @author: Li Qinru
 * @Date: 2022/11/30 8:55 PM
 */
public class A12_HashSetDemo12 {
    public static void main(String[] args) {
        Student s1 = new Student("Zhangsan",23);
        Student s2 = new Student("Lisi",25);
        Student s3 = new Student("Zhangsan",23);

        HashSet<Student> hs = new HashSet<>();
        hs.add(s1);
        hs.add(s2);
        hs.add(s3);

        for (Student h : hs) {
            System.out.println(h);
        }
    }
}
