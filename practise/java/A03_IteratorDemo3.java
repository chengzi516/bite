package cn.edu.cwnu.cs.lqr01;

import java.util.ArrayList;
import java.util.Iterator;

/**
 * @author: Li Qinru
 * @Date: 2022/11/29 12:03 AM
 */
public class A03_IteratorDemo3 {
    public static void main(String[] args) {
        ArrayList<String> coll = new ArrayList<>();

        coll.add("aaa");
        coll.add("bbb");
        coll.add("ccc");
        coll.add("ddd");


        Iterator<String> it = coll.iterator();
        while (it.hasNext()){
            String str = it.next();
        }

        //当我们上面循环结束之后，迭代器的指针已经指向了最后没有元素的位置
        System.out.println(it.next());
//
//        循环中只能使用一次next方法
//        Iterator<String> iter = coll.iterator();
//        while(iter.hasNext()){
//            System.out.println(iter.next());
//            System.out.println(iter.next());
//        }

////       迭代器遍历时，不能用集合的方法进行增加或者删除
//        Iterator<String> iter1 = coll.iterator();
//        while(iter1.hasNext()){
//            String str = iter1.next();
//            if("bbb".equals(str)){
////               coll.remove("bbb");
//                iter1.remove();
//            }
//        }
//        System.out.println(coll);
    }
}
