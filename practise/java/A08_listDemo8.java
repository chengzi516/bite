package cn.edu.cwnu.cs.lqr01;

import java.util.ArrayList;
import java.util.List;

/**
 * @author: Li Qinru
 * @Date: 2022/11/29 10:23 PM
 */
public class A08_listDemo8 {
    public static void main(String[] args) {

        List<String> list = new ArrayList<>();

        list.add("aaa");
        list.add("bbb");
        list.add("ccc");

        System.out.println(list);

        //插入数据
        System.out.println("--------插入数据--------");
        list.add(1,"qqq");
        System.out.println(list);

        //删除指定索引
        System.out.println("--------删除指定索引--------");
        String removeNum = list.remove(0);
        System.out.println(removeNum);
        System.out.println(list);

        //修改指定索引
        System.out.println("--------修改指定索引--------");
        String result = list.set(0,"hhh");
        System.out.println(result);
        System.out.println(list);

        //返回索引处的元素
        System.out.println("--------返回索引处的元素--------");
        String s =list.get(0);
        System.out.println(s);
    }
}
