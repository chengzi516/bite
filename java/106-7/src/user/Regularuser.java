package user;

import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 13378343877
 * Date: 2023-02-03
 * Time: 21:26
 */
public class Regularuser extends User{


    public Regularuser(String name) {
        super(name);
      //  this.Specialproperties = specialproperties;
    }
    public int menu(){
        System.out.println("欢迎你！"+name);
        System.out.println("0.退出系统");
        System.out.println("1.借阅图书");
        System.out.println("2.归还图书");
        System.out.println("3.查找图书");
        Scanner scanner=new Scanner(System.in);
        int choice =scanner.nextInt();
        return choice;

    }

}
