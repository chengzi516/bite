package cn.edu.cwnu.cs.lqr02;

import java.time.Instant;
import java.time.ZoneId;
import java.time.ZonedDateTime;
import java.util.Set;

/**
 * @author: Li Qinru
 * @Date: 2022/11/22 11:21 PM
 */
public class A03_InstantDemo {
    public static void main(String[] args) {

//        ZoneId zoneId = ZoneId.systemDefault();
//        System.out.println(zoneId);

        //获取所有的时区名称
//        Set<String> zoneIds = ZoneId.getAvailableZoneIds();
//        System.out.println(zoneIds);

        //当前时间的Instant对象（标准时间）
//        Instant nowTime = Instant.now();
//        System.out.println(nowTime);

//        //根据（秒/毫秒/纳秒）获取Instant对象
//        Instant instant1 = Instant.ofEpochSecond(1L);
//        System.out.println(instant1);
//
//        //指定时区
//        ZonedDateTime chinaTime = Instant.now().atZone(ZoneId.of("Asia/Shanghai"));
//        ZonedDateTime currentTime = ZonedDateTime.now();
//        System.out.println(chinaTime);
//        System.out.println(currentTime);

        //4. isXxx判断
        Instant instant4 = Instant.ofEpochMilli(0L);
        Instant instant5 = Instant.ofEpochMilli(1000L);

        boolean result1 = instant4.isBefore(instant5);
        System.out.println(result1);

        boolean result2 = instant4.isAfter(instant5);
        System.out.println(result2);

//        //5.Instant minusXxx
//        Instant result3 = Instant.ofEpochMilli(3000L);
//        System.out.println(result3);
//
//        Instant result4 = result3.minusSeconds(1);
//        System.out.println(result4);
    }
}
