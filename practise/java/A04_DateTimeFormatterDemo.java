package cn.edu.cwnu.cs.lqr02;

import java.time.Instant;
import java.time.ZoneId;
import java.time.ZonedDateTime;
import java.time.format.DateTimeFormatter;

/**
 * @author: Li Qinru
 * @Date: 2022/11/22 11:42 PM
 */
public class A04_DateTimeFormatterDemo {
    public static void main(String[] args) {

        //获取时间对象
        ZonedDateTime time = Instant.now().atZone(ZoneId.of("Asia/Shanghai"));

        //解析/格式化器
        DateTimeFormatter dtf1 = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss EE a");

        //格式化
        System.out.println(dtf1.format(time));
    }
}
