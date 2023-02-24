package cn.edu.cwnu.cs.lqr01;

import java.util.Scanner;

/**
 * @author: Li Qinru
 * @Date: 2022/11/16 9:12 PM
 */
public class StringDemo3 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String str = s.next();
        int upperStr = 0;
        int lowerStr = 0;
        int number = 0;
         for (int i = 0; i < str.length(); i++) {
             if(str.charAt(i) >= 'A' && str.charAt(i) <= 'Z'){
                 upperStr ++;
             }
             if(str.charAt(i) > 96 && str.charAt(i) < 123){
                 lowerStr ++;
             }
             if(str.charAt(i) > 47 && str.charAt(i) < 58){
                 number++;
             }
        }
        System.out.println("大写有"+upperStr);
        System.out.println("小写有"+lowerStr);
        System.out.println("数字有"+number);
    }
}
