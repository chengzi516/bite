package cn.edu.cwnu.cs.lqr02;

import java.time.Duration;
import java.time.LocalDateTime;

/**
 * @author: Li Qinru
 * @Date: 2022/11/23 1:03 AM
 */
public class A09_DurationDemo {
    public static void main(String[] args) {
        LocalDateTime today = LocalDateTime.now();
        System.out.println(today);

        LocalDateTime birthDate = LocalDateTime.of(1998,11,25,0,0,0);
        System.out.println(birthDate);

        Duration duration = Duration.between(birthDate,today);
        System.out.println("相差的时间间隔对象："+duration);

        System.out.println(duration.toDays());
        System.out.println(duration.toHours());
        System.out.println(duration.toMinutes());
        System.out.println(duration.toMillis());
        System.out.println(duration.toNanos());
    }
}
