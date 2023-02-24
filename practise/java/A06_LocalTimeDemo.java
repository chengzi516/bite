package cn.edu.cwnu.cs.lqr02;

import java.time.LocalDate;
import java.time.LocalTime;

/**
 * @author: Li Qinru
 * @Date: 2022/11/23 12:32 AM
 */
public class A06_LocalTimeDemo {
    public static void main(String[] args) {
        LocalTime nowTime = LocalTime.now();
        System.out.println("现在的时间是 "+nowTime);

        //拿到现在的时分秒
        int hour = nowTime.getHour();
        int minute = nowTime.getMinute();
        int second = nowTime.getSecond();
        System.out.println("时: "+hour+", 分: "+minute+", 秒："+second);

        LocalTime mtime = LocalTime.of(8,20,30,150);

        //is系列的方法
        System.out.println(nowTime.isBefore(mtime));
        System.out.println(nowTime.isAfter(mtime));

        //with系列方法：只能修改时分秒
        System.out.println(nowTime.withHour(10));

        //minus系列的方法，只能减少时分秒
        System.out.println(nowTime.minusHours(10));

        //plus系统的方法，只能增加时分秒
        System.out.println(nowTime.plusHours(10));

    }
}
