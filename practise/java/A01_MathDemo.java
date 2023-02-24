package cn.edu.cwnu.cs.lqr02;

/**
 * @author: Li Qinru
 * @Date: 2022/11/21 11:08 AM
 */
public class A01_MathDemo {
    public static void main(String[] args) {
        //绝对值
        System.out.println("计算绝对值"+Math.abs(-78));
        //bug int的类型的数组范围-2147483648 ~ 2147483647
        System.out.println(Math.abs(-2147483648));
        System.out.println("------------------------------");

//        //计算方根
        System.out.println(Math.sqrt(16));
        System.out.println(Math.cbrt(8));
        System.out.println("------------计算方根-------------");
//
//        //向上取整
        System.out.println(Math.ceil(12.34));
        System.out.println(Math.ceil(-12.34));
        System.out.println("-------------向上取整------------");
//
//        //向下取整
        System.out.println(Math.floor(12.34));
        System.out.println(Math.floor(-12.34));
        System.out.println("-------------向下取整-----------");
//
        //四舍五入
        System.out.println(Math.round(12.34));
        System.out.println(Math.round(12.64));
        System.out.println("-------------四舍五入-----------");
//
        //比较最大值最小值
        System.out.println(Math.max(20,30));
        System.out.println(Math.min(20,30));
        System.out.println("-------------最大值最小值-------------");
//
        //获取a的b次幂
        System.out.println(Math.pow(2,3));
        System.out.println("------------a的b次幂------------");

        //随机数生成
        for (int i = 0; i <= 10; i++) {
            System.out.println(Math.floor(Math.random()*100)+1);
        }
        //Math.random() [0.0 1.0)
        //* 100         [0.0 100.0)
        //floor         去掉了后面的小数
        //+1            [1 100.0]
    }
}
