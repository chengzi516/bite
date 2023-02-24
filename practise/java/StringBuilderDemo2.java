package cn.edu.cwnu.cs.lqr01;

import java.util.Scanner;

/**
 * @author: Li Qinru
 * @Date: 2022/11/16 10:55 PM
 */
public class StringBuilderDemo2 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("请输入字符串...");
        String str = s.next();

        String sb = new StringBuilder(str).reverse().toString();
//        String result = sb.toString();

        if(str.equals(sb)){
            System.out.println("这是对称字符串！");
        }
        else {
            System.out.println("这不是对称字符串！");
        }
    }
}
