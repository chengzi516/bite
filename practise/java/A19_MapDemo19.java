package cn.edu.cwnu.cs.lqr01;

import java.util.HashMap;
import java.util.Map;

/**
 * @author: Li Qinru
 * @Date: 2022/12/07 11:59 PM
 */
public class A19_MapDemo19 {
    public static void main(String[] args) {

        Map<String,String> map = new HashMap<>();

        //put
        System.out.println(map.put("Zhangsan", "Lisi"));
        System.out.println(map.put("Kunkun", "Hanhan"));

        String va = map.put("Kunkun","Wangwu");

        //remove
        String result = map.remove("Kunkun");
        System.out.println(result);

        //clear
//        map.clear();
//        System.out.println(map);
        //contains
        boolean result1 = map.containsKey("Zhangsan");
        System.out.println(result1);

        boolean result2 = map.containsValue("Lisi");
        System.out.println(result2);

        //empty
        boolean result3 = map.isEmpty();
        System.out.println(result3);

        //size
        System.out.println(map.size());

        System.out.println(map);
    }
}
