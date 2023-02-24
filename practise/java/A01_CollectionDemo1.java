package cn.edu.cwnu.cs.lqr01;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;

public class A01_CollectionDemo1 {

    public static void main(String[] args) {

        //注意点，collection是一个接口,所以我们不能直接创建对象
        //所以。我们学习他的方法时，只能创建他的实现类对象
        //实现类：ArrayList
        Collection<String> coll = new ArrayList<>();

        coll.add("aaa");
        coll.add("bbb");
        coll.add("ccc");

        System.out.println(coll);

//        coll.clear();
//        System.out.println(coll);

        //删除：因为Collection里面定义的是共性的方法，所以此时不能通过索引进行删除，只能通过元素的对象进行删除。
        coll.remove("aaa");
        System.out.println(coll);

        boolean result = coll.contains("bbb");
        System.out.println(result);
        //contains方法底层是依赖equals方法进行判断是否存在的，
        // 所以集合中存储的是自定义对象，也想通过contains方法来判断是否包含，那么在javabean类中，
        // 一定要重写equals方法。

        boolean result2 = coll.isEmpty();
        System.out.println(result2);

        System.out.println(coll.size());

    }
}
