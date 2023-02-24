package cn.edu.cwnu.cs.lqr01;

import java.util.ArrayList;
import java.util.Collection;

/**
 * @author: Li Qinru
 * @Date: 2022/11/28 4:37 PM
 */
public class A02_CollectionDemo2 {
    public static void main(String[] args) {
        Collection<Student> coll = new ArrayList<>();

        Student s1 = new Student("Zhangsan",22);
        Student s2 = new Student("Lisi",23);
        Student s3 = new Student("Wangwu",20);

        coll.add(s1);
        coll.add(s2);
        coll.add(s3);

        Student s4 = new Student("Zhangsan",22);
        //那么我会想如果同姓名和年龄，就认为是同一个学生。
        System.out.println(coll.contains(s4));
    }
}
