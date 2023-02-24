package cn.edu.cwnu.cs.lqr02;

import java.util.Random;

/**
 * @author: Li Qinru
 * @Date: 2022/11/21 11:53 PM
 */
public class A02_RandomDemo {
    public static void main(String[] args) {

//        Random s = new Random();
//        for (int i = 0; i < 10; i++) {
//            System.out.println(s.nextInt(10)+1);
//        }

        Random r = new Random(2);
        for (int i = 0; i < 10; i++) {
            System.out.println(r.nextInt(10)+1);
        }
    }
}
