package cn.edu.cwnu.cs.generics02;

/**
 * @author: Li Qinru
 * @Date: 2022/12/07 3:19 PM
 */
public class TestMain {
    public static void main(String[] args) {
        MyArrayList<String> list = new MyArrayList<>();
        list.add("aaa");
        list.add("bbb");
        list.add("ccc");
        System.out.println(list.get(2));
        System.out.println(list);
    }
}
