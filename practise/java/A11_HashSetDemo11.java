package cn.edu.cwnu.cs.lqr01;

import java.util.HashSet;

/**
 * @author: Li Qinru
 * @Date: 2022/11/30 8:00 PM
 */
public class A11_HashSetDemo11 {
    public static void main(String[] args) {
        Student s1 = new Student("Zhangsan",22);
        Student s2 = new Student("Zhangsan",22);

        System.out.println(s1.hashCode());
        System.out.println(s2.hashCode());

//        HashSet<String> hm = new HashSet<>();

    }
}
