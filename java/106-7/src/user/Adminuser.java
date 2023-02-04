package user;

import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 13378343877
 * Date: 2023-02-03
 * Time: 21:27
 */
public class Adminuser extends User {
    public Adminuser(String name) {
        super(name);
    }
    public int menu(){
        System.out.println("欢迎你！"+name);
        System.out.println("0.退出系统");
        System.out.println("1.借阅图书");
        System.out.println("2.归还图书");
        System.out.println("3.查找图书");
        System.out.println("4.添加图书");
        System.out.println("5.删除图书");
        Scanner scanner=new Scanner(System.in);
        int choice =scanner.nextInt();
        return choice;

    }
}
