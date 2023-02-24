package cn.edu.cwnu.cs.lqr01;

/**
 * @author: Li Qinru
 * @Date: 2022/11/16 7:09 PM
 */
public class StringDemo2 {
    public static void main(String[] args) {
        String s1 = "abc";
        String s2 = "abc";
        System.out.println(s1==s2);

        String s3 = new String("abc");
        String s4 = new String("abc");
        System.out.println(s3==s4);

        String s5 = "abc";
        String s6 = new String("abc");
        System.out.println(s5==s6);
    }
}
