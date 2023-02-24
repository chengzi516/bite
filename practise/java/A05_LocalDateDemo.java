package cn.edu.cwnu.cs.lqr02;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.Month;
import java.time.MonthDay;

/**
 * @author: Li Qinru
 * @Date: 2022/11/23 12:03 AM
 */
public class A05_LocalDateDemo {
    public static void main(String[] args) {

//        //当前时间的日历对象（包含 年月日）
//        LocalDate nowDate = LocalDate.now();
//        System.out.println(nowDate);

        LocalDate isDate = LocalDate.of(2023,1,1);
//        System.out.println("指定日期："+isDate);
//
//        int year = isDate.getYear();
//        System.out.println("Year: "+year);
//
//        Month m = isDate.getMonth();
//        System.out.println(m);
//        System.out.println(m.getValue());
//
//        int month = isDate.getMonthValue();
//        System.out.println("month: "+month);
//
//        int dayOfYear = isDate.getDayOfYear();
//        System.out.println("dayOfYear: "+dayOfYear);
//
//        DayOfWeek dayOfWeek = isDate.getDayOfWeek();
//        System.out.println(dayOfWeek);
//        System.out.println(dayOfWeek.getValue());

        //is开头的方法表示判断
        System.out.println(isDate.isBefore(isDate));
        System.out.println(isDate.isAfter(isDate));

//        //with开头的方法表示修改，只能修改年月日
//        LocalDate withLocalDate = isDate.withYear(2000);
//        System.out.println(withLocalDate);
//
//        //minus开头的方法表示减少，只能减少年月日
//        LocalDate minusLocalDate = isDate.minusYears(1);
//        System.out.println(minusLocalDate);
//
//        //plus开头的方法表示增加，只能增加年月日
//        LocalDate plusLocalDate = isDate.plusDays(1);
//        System.out.println(plusLocalDate);
//
//        //判断今天是否是你的生日
//        LocalDate birDate = LocalDate.of(1998,11,24);
//        LocalDate nowDate1 = LocalDate.now();
//
//        MonthDay birMd = MonthDay.of(birDate.getMonthValue(),birDate.getDayOfMonth());
//        MonthDay nowMd = MonthDay.from(nowDate1);
//
//        System.out.println("今天是你的生日吗？"+birMd.equals(nowMd));
    }
}
