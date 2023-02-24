package cn.edu.cwnu.cs.lqr01;

/**
 * @author: Li Qinru
 * @Date: 2022/11/29 11:21 AM
 */
public class A07_lambdaDemo7 {
    public static void main(String[] args) {

        //匿名内部类
        method(new Swim() {
            @Override
            public void swimming() {
                System.out.println("I like to swim....");
            }
        });

//        //lambda表达式
//        method(() -> {
//                System.out.println("I like to swim....");
//            }
//       );
    }

    public static void method(Swim s){
        s.swimming();
    }
}
