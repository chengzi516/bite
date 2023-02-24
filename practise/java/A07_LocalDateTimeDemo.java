package cn.edu.cwnu.cs.lqr02;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;

/**
 * @author: Li Qinru
 * @Date: 2022/11/23 12:43 AM
 */
public class A07_LocalDateTimeDemo {
    public static void main(String[] args) {
        LocalDateTime nowDateTime = LocalDateTime.now();

        System.out.println("今天是："+nowDateTime);
        System.out.println(nowDateTime.getYear());
        System.out.println(nowDateTime.getMonthValue());
        System.out.println(nowDateTime.getDayOfMonth());
        System.out.println(nowDateTime.getHour());
        System.out.println(nowDateTime.getMinute());
        System.out.println(nowDateTime.getSecond());
        System.out.println(nowDateTime.getNano());

        //当年的第几天
        System.out.println("dayOfYear: "+ nowDateTime.getDayOfYear());

        //星期
        System.out.println(nowDateTime.getDayOfWeek());
        System.out.println(nowDateTime.getDayOfWeek().getValue());

        //月份
        System.out.println(nowDateTime.getMonth());
        System.out.println(nowDateTime.getMonth().getValue());

        LocalDate ld = nowDateTime.toLocalDate();
        System.out.println(ld);

        LocalTime lt = nowDateTime.toLocalTime();
        System.out.println(lt);
    }
}
