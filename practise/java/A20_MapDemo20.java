package cn.edu.cwnu.cs.lqr01;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.function.BiConsumer;

/**
 * @author: Li Qinru
 * @Date: 2022/12/08 12:25 AM
 */
public class A20_MapDemo20 {
    public static void main(String[] args) {

        Map<String,String> map = new HashMap<>();

        map.put("Zhangsan","Lisi");
        map.put("Kunkun","Hanhan");

        //1. 通过键找值，获取所有键，把这些键放到一个单列集合中
        System.out.println("-------------键找值-----------");
        Set<String> keys = map.keySet();
        for (String key : keys) {
//            System.out.println(key);
            String value = map.get(key);
            System.out.println(key + "=" + value);
        }

        //2. 依次获取键值对,自动生成
        System.out.println("-------------键值对-----------");
        Set<Map.Entry<String, String>> entries = map.entrySet();
        for (Map.Entry<String, String> entry : entries) {
            String key = entry.getKey();
            String value = entry.getValue();
            System.out.println(key + "=" + value);
        }

        //3. Lambda表示式,底层就是键值对对象foreach遍历
        System.out.println("-------------Lambda表示式-----------");
        map.forEach((String s, String s2)-> {
                System.out.println(s+s2);
            }
        );
        map.forEach(new BiConsumer<String, String>() {
            @Override
            public void accept(String key, String value) {
                System.out.println(key + "=" + value);
            }
        });

//        map.forEach((key, value) ->
//                System.out.println(key + "=" + value)
//        );
    }
}
