package cn.edu.cwnu.cs.lqr01;

import java.util.ArrayList;

/**
 * @author: Li Qinru
 * @Date: 2022/11/29 12:45 AM
 */
public class A04_foreachDemo4 {
    public static void main(String[] args) {
//        int[] array = {1, 2, 3, 4, 5, 6};
//
//        for (int i : array) {
//            System.out.println(i);
//        }

        ArrayList<String> arrList = new ArrayList<>();
        //链式编程：如果一个方法是返回值是一个对象，那么可以直接继续调用所返回对象的方法
        arrList.add("Zhangsan");
        arrList.add("Lisi");
        arrList.add("Wangwu");

//        //s是一个第三方变量，在循环过程当中依次表示集合中的每一个数据
//        for (String s : arrList) {
//            System.out.println(s);
//        }

        for (String s : arrList) {
            s = "Kunkun";
            System.out.println(s);
        }
        System.out.println(arrList);
    }
}
