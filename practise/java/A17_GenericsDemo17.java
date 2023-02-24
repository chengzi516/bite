package cn.edu.cwnu.cs.lqr01;

import java.util.ArrayList;
import java.util.Iterator;


/**
 * @author: Li Qinru
 * @Date: 2022/12/07 10:42 AM
 */
public class A17_GenericsDemo17 {

    public static void main(String[] args) {
        //如果没有泛型，集合如何存储数据

        //1.创建集合的对象
        ArrayList<String> list = new ArrayList<>();

        //2.添加数据
//        list.add(123);
        list.add("aaa");
//        list.add(new Student("Zhangsan",23));

        //3.遍历集合，获取里面的每一个元素。
        Iterator it = list.iterator();
        while (it.hasNext()){
            Object obj = it.next();
            //多态的弊端是不能访问子类的特有功能
            //强转是不行的。
//            obj.length();
            System.out.println(obj);
        }
    }
}
