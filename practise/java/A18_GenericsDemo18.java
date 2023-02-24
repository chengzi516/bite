package cn.edu.cwnu.cs.lqr01;

import java.util.ArrayList;

/**
 * @author: Li Qinru
 * @Date: 2022/12/07 5:00 PM
 */
public class A18_GenericsDemo18 {
    public static void main(String[] args) {
        ArrayList<Ye> list1 = new ArrayList<>();
        ArrayList<Fu> list2 = new ArrayList<>();
        ArrayList<Zi> list3 = new ArrayList<>();

        //调用method方法，泛型不具备继承性。
//        method(list1);
//        method(list2);
//        method(list3);


        //数据具备继承性
        list1.add(new Ye());
        list1.add(new Fu());
        list1.add(new Zi());
    }

    //此时，泛型里面写的什么类型，那么只能传递什么类型的数据。
    public static void method(ArrayList<Ye> list){

    }

    //直接泛型，所有类型都可以传
//    public static <E> void method(ArrayList<E> list){
//
//    }

    //如果只想传递Ye,Fu,Zi.此时我们就可以使用泛型的通配符。
    //?也表示不确定的关系，可以进行类型限定
    //? extends E: 表示可以传递E或者E所有的子类类型
    //? super E: 表示可以传递E或者E所有的父类类型

//    public static void method(ArrayList<? extends Ye>list){
//
//    }

//    public static void method(ArrayList<? super Fu>list){
//
//    }
}
class Ye{}
class Fu extends Ye{}
class Zi extends Fu{}
