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
        System.out.println("��ӭ�㣡"+name);
        System.out.println("0.�˳�ϵͳ");
        System.out.println("1.����ͼ��");
        System.out.println("2.�黹ͼ��");
        System.out.println("3.����ͼ��");
        Scanner scanner=new Scanner(System.in);
        int choice =scanner.nextInt();
        return choice;

    }

}
