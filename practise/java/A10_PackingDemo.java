package cn.edu.cwnu.cs.lqr02;

/**
 * @author: Li Qinru
 * @Date: 2022/11/23 1:20 AM
 */
public class A10_PackingDemo {
    public static void main(String[] args) {

        //两种手动装箱的方法JDK5之前
        Integer i1 = Integer.valueOf(127);
        Integer i2 = Integer.valueOf(127);
        System.out.println(i1 == i2);

        Integer i3 = 128;
        Integer i4 = Integer.valueOf(128);
        System.out.println(i3==i4);

        Integer i5 = new Integer(127);
        Integer i6 = new Integer(127);
        System.out.println(i5 == i6);

        //手动拆箱：
        int a = i6.intValue();
        System.out.println(a);

        //自动装箱拆箱
        int i = 10;
        Integer n = i;
        System.out.println(n.getClass());
        int l = n;
        System.out.println(l);

        Integer i7 = 10;
        Integer i8 = 10;
        Integer i9 = i7+i8;
        System.out.println(i9);

//        ValueOf, parseInt
        Integer c = Integer.valueOf("123");
        System.out.println(c.getClass());

        int d = Integer.parseInt("123");
        System.out.println(d);
    }
}
