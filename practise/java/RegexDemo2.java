package cn.edu.cwnu.cs.lqr02;

/**
 * @author: Li Qinru
 * @Date: 2022/11/23 5:06 PM
 */
public class RegexDemo2 {
    public static void main(String[] args) {
        // \转义字符，改变后面那个字符原本的含义
        //练习：以字符串的形式打印一个双引号
        //在Java中表示字符串的开头或者结尾
//        System.out.println("\"");

        //.表示任意一个字符
        System.out.println("-----------1----------");
        System.out.println("你".matches(".."));
        System.out.println("你a".matches(".."));

        //\\d只能是任意的一位数字
        //简单来记：两个\表示一个\
        System.out.println("-----------2----------");
        System.out.println("a".matches("\\d"));
        System.out.println("3".matches("\\d"));
        System.out.println("333".matches("\\d"));

        //\\w只能是一位单词字符[a-zA-Z_0-9]
        System.out.println("-----------3----------");
        System.out.println("z".matches("\\w"));
        System.out.println("2".matches("\\w"));
        System.out.println("21".matches("\\w"));
        System.out.println("你".matches("\\w"));

        //非单词字符
        System.out.println("-----------4----------");
        System.out.println("你".matches("\\W"));

        //如果要校验多个,至少6位
        System.out.println("-----------5----------");
        System.out.println("2442fsfsfs".matches("\\w{6,}"));
        System.out.println("244f".matches("\\w{6,}"));

        //必须是数字和字符，必须是4位
        System.out.println("-----------6----------");
        System.out.println("23dF".matches("[a-zA-Z0-9]{4}"));
        System.out.println("23_F".matches("[a-zA-Z0-9]{4}"));
        System.out.println("23dF".matches("[\\w&&[^_]]{4}"));
        System.out.println("23_F".matches("[\\w&&[^_]]{4}"));
    }
}
