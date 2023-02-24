package cn.edu.cwnu.cs.lqr02;

import java.time.LocalDate;
import java.time.Period;

/**
 * @author: Li Qinru
 * @Date: 2022/11/23 12:53 AM
 */
public class A08_PeriodDemo {
    public static void main(String[] args) {
        LocalDate today = LocalDate.now();
        System.out.println(today);

        LocalDate birthDate = LocalDate.of(2000,11,25);
        System.out.println(birthDate);

        Period period = Period.between(birthDate,today);

        System.out.println("相差的时间间隔对象" + period);
        System.out.println(period.getYears());
        System.out.println(period.getMonths());
        System.out.println(period.getDays());

        System.out.println(period.toTotalMonths());
    }
}
