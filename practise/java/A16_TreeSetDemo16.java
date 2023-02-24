package cn.edu.cwnu.cs.lqr01;

import java.util.Comparator;
import java.util.TreeSet;

/**
 * @author: Li Qinru
 * @Date: 2022/11/30 11:40 PM
 */
public class A16_TreeSetDemo16{
    public static void main(String[] args) {

        //o1表示要添加的元素
        //o2表示已经在红黑树存在的元素
        //返回值规则跟之前是一样的。
        TreeSet<String> ts = new TreeSet<>(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                int i = o1.length() - o2.length();
                //长度一样使用默认排序规则，否则就以真正的长度为准
                i= i == 0? o1.compareTo(o2):i;
                return i;
            }
        });

        TreeSet<String> ts1 = new TreeSet<>((o1,o2) -> {
                int i = o1.length() - o2.length();
                i= i == 0? o1.compareTo(o2):i;
                return i;
        });

        ts.add("ab");
        ts.add("c");
        ts.add("df");
        ts.add("qwer");

        System.out.println(ts);

    }

}
