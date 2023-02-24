package cn.edu.cwnu.cs.lqr01;


import java.io.IOException;

/**
 * @author: Li Qinru
 * @Date: 2022/11/17 1:11 AM
 */
public class RuntimeClass {
    public static void main(String[] args) throws IOException {
     Runtime r1 = Runtime.getRuntime();

//     Runtime.getRuntime().exit(0);

//     System.out.println(Runtime.getRuntime().availableProcessors());
//
//     System.out.println(Runtime.getRuntime().maxMemory()/1024/1024);
//
//     System.out.println(Runtime.getRuntime().totalMemory()/1024/1024);
//
//     System.out.println(Runtime.getRuntime().freeMemory()/1024/1024);

//        Runtime.getRuntime().exec("notepad");

//        Runtime.getRuntime().exec("shutdown -s -t 3600");

        Runtime.getRuntime().exec("shutdown -a");
    }
}
