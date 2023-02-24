package cn.edu.cwnu.cs.lqr02;

/**
 * @author: Li Qinru
 * @Date: 2022/11/23 5:42 PM
 */
public class RegexDemo3 {
    public static void main(String[] args) {

        //验证手机号码: 13112345678  13712345667 15824678882 18990012490
        System.out.println("----------1----------");
        String regex1 = "1[3-9]\\d{9}";
        System.out.println("15228864630".matches(regex1));
        System.out.println("152288646301".matches(regex1));

        //座机号码: 020-2324242   0214224222  0817-2319155
        System.out.println("----------2----------");
        String regex2 = "0\\d{2,3}-?[1-9]\\d{4,9}";
        System.out.println("020-2324242".matches(regex2));
        System.out.println("0214224222".matches(regex2));
        System.out.println("0817-2319155".matches(regex2));
        //-写在括号里面表示范围，外面就是一个简单的-

        //邮箱号码: Zhangsna@qq.com  Zhangsan@cwnu.edu.cn  Lisi@163.com
        System.out.println("----------3----------");
        String regex3 = "\\w+@[\\w&&[^_]]{2,6}(\\.[a-zA-Z]{2,3}){1,2}";
        System.out.println("Zhangsna@qq.com".matches(regex3));
        System.out.println("Zhangsna@cwnu.edu.cn".matches(regex3));
    }
}
