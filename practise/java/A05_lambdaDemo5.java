package cn.edu.cwnu.cs.lqr01;

import java.util.Arrays;
import java.util.Comparator;

/**
 * @author: Li Qinru
 * @Date: 2022/11/29 10:52 AM
 */
public class A05_lambdaDemo5 {
    public static void main(String[] args) {

        //只能给引用数据类型的数组进行排序
        //如果数组是基本数据类型，需要编程其对应的包装类
        Integer[] arr = {2, 3, 1, 6, 7, 4, 5, 9};
//        Arrays.sort(arr);
//        System.out.println(Arrays.toString(arr));
//
//        //第二个参数是一个接口，所以我们在调用方法的时候，要传递这个接口的实现类对象，作为排序的规则。
//        Arrays.sort(arr, new Comparator<Integer>() {
//            @Override
//            public int compare(Integer o1, Integer o2) {
//                return o2-o1;
//            }
//        });
//        System.out.println(Arrays.toString(arr));

        Arrays.sort(arr, (Integer o1, Integer o2) -> {
            return o2 - o1;
        });
        System.out.println(Arrays.toString(arr));

//        //如果语句体中只有一条语句，returm和大括号都可以省略不写。参数类型可以不写。
//        Arrays.sort(arr, (o1,o2) -> o2-o1);
//        System.out.println("simple"+Arrays.toString(arr));
    }
}
