package cn.edu.cwnu.cs.lqr01;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.function.Consumer;

/**
 * @author: Li Qinru
 * @Date: 2022/11/30 1:20 AM
 */
public class A10_SetDemo10 {
    public static void main(String[] args) {

        //创建一个Set集合的对象
        Set<String> setDemo = new HashSet<>();

        boolean s1 = setDemo.add("aaa");
        boolean s2 = setDemo.add("aaa");

        System.out.println(s1);
        System.out.println(s2);
        System.out.println(setDemo);

        setDemo.add("bbb");
        setDemo.add("ccc");
        setDemo.add("ddd");

        System.out.println(setDemo);

        System.out.println("-----------------");

        //迭代器遍历
        Iterator<String> setIt = setDemo.iterator();
        while (setIt.hasNext()){
            String str = setIt.next();
            System.out.println("iterator: "+str);
        }

        for (String s : setDemo) {
            System.out.println("foreach: " + s);
        }

        setDemo.forEach(s-> System.out.println("Lambda: "+s));
    }
}
