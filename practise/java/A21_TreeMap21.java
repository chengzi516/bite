package cn.edu.cwnu.cs.lqr01;

import java.util.Comparator;
import java.util.TreeMap;
import java.util.TreeSet;

/**
 * @author: Li Qinru
 * @Date: 2022/12/08 1:29 AM
 */
public class A21_TreeMap21 {
    public static void main(String[] args) {

        TreeMap<Integer,String> tm = new TreeMap<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1 - o2;
            }
        });

//        TreeMap<Integer,String> tm = new TreeMap<>((o1, o2) -> {
//                return o2 - o1;
//        });

        tm.put(3, "zhangsan");
        tm.put(5, "Wangwu");
        tm.put(4,"Lisi");

        System.out.println(tm);
    }
}
