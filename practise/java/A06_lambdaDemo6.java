package cn.edu.cwnu.cs.lqr01;

import java.util.ArrayList;
import java.util.function.Consumer;

/**
 * @author: Li Qinru
 * @Date: 2022/11/29 1:32 AM
 */
public class A06_lambdaDemo6 {
    public static void main(String[] args) {

        ArrayList<String> arrList = new ArrayList<>();
        arrList.add("Zhangsan");
        arrList.add("Lisi");
        arrList.add("Wangwu");

//        arrList.forEach(new Consumer<String>() {
//            @Override
//            public void accept(String s) {
//                System.out.println(s);
//            }
//        });

//        //lambda表达式
//        arrList.forEach((String s) -> {
//            System.out.println(s);
//        });
//
        //p162，简化版本
        arrList.forEach(s -> System.out.println(s));
    }
}
