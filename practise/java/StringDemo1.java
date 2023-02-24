package cn.edu.cwnu.cs.lqr01;

public class StringDemo1 {

    public static void main(String[] args) {
        String a = "abd";
        System.out.println(a);

        String b = new String();
        System.out.println(b);

        String c = new String("Hello");
        System.out.println(c);

        //字符串内容不会发生改变，如果要修改字符串的内容
        char[] chs = {'a','b','d','e'};
        String e = new String(chs);
        System.out.println(e);

        //以后在网络传输中的数据都是字节信息，要把信息转换成字符串就需要这个构造。
        byte[] byt = {97,98,99,100};
        String f = new String(byt);
        System.out.println(f);
    }
}
