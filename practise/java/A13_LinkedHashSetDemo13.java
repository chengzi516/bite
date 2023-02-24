package cn.edu.cwnu.cs.lqr01;

import java.util.HashSet;
import java.util.LinkedHashSet;

/**
 * @author: Li Qinru
 * @Date: 2022/11/30 9:07 PM
 */
public class A13_LinkedHashSetDemo13 {
    public static void main(String[] args) {

        Student s1 = new Student("Zhangsan",23);
        Student s2 = new Student("Lisi",25);
        Student s3 = new Student("Wangwu",22);
        Student s4 = new Student("Ikun",26);

        HashSet<Student> hs = new HashSet<>();
        hs.add(s1);
        hs.add(s2);
        hs.add(s3);
        hs.add(s4);

        System.out.println(hs);

        LinkedHashSet lh = new LinkedHashSet();
        lh.add(s1);
        lh.add(s2);
        lh.add(s3);
        lh.add(s4);

        System.out.println(lh);
    }
}
