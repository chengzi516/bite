package cn.edu.cwnu.cs.lqr01;

import java.util.*;
import java.util.function.Consumer;

/**
 * @author: Li Qinru
 * @Date: 2022/11/29 11:40 PM
 */
public class A09_listDemo9 {
    public static void main(String[] args) {

        List<String> myList = new ArrayList<>();
        myList.add("aaa");
        myList.add("bbb");
        myList.add("ccc");

        //迭代器
        System.out.println("------------迭代器------------");
        Iterator<String> it = myList.iterator();
        while(it.hasNext()){
            String str = it.next();
            System.out.println(str);
        }

        //foreach
        System.out.println("------------foreach------------");
        for (String s : myList) {
            System.out.println(s);
        }


        //Lambda
        System.out.println("------------Lambda------------");
        myList.forEach(s -> System.out.println(s));

        //普通for循环
        System.out.println("------------普通for循环------------");
        for (int i = 0; i < myList.size(); i++) {
            String s = myList.get(i);
            System.out.println(s);
        }

        //列表迭代器
        System.out.println("------------列表迭代器------------");
        ListIterator<String> listIt = myList.listIterator();
//        while (listIt.hasNext()){
//            String n = listIt.next();
//            System.out.println(n);
//        }

        //在遍历的过程中，可以添加元素
        while (listIt.hasNext()){
            if("bbb".equals(listIt.next())){
                listIt.add("qqq");
            }
        }
        System.out.println("add"+myList);

    }
}
