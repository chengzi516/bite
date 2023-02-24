package cn.edu.cwnu.cs.lqr01;

import java.util.TreeSet;

/**
 * @author: Li Qinru
 * @Date: 2022/11/30 9:35 PM
 */
public class A14_TreeSetDemo14 {
    public static void main(String[] args) {

        TreeSet<Integer> ts = new TreeSet<>();

        ts.add(2);
        ts.add(10);
        ts.add(4);
        ts.add(7);
        ts.add(9);

        System.out.println(ts);

        for (Integer t : ts) {
            System.out.println(t);
        }

    }
}
