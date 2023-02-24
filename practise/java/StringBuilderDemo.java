package cn.edu.cwnu.cs.lqr01;

/**
 * @author: Li Qinru
 * @Date: 2022/11/16 9:59 PM
 */
public class StringBuilderDemo {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder("天天学习很开心").append(1).append(23.78);
        sb.append(1);
        sb.append(23.56);
        sb.append(" ");
        sb.append("不骗你哟");
        System.out.println(sb);
        System.out.println(sb.reverse());
        System.out.println(sb.length());
        System.out.println(sb.getClass());
        System.out.println(sb.toString().getClass());
    }
}
