import book.Booklist;
import user.Adminuser;
import user.Regularuser;
import user.User;

import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 13378343877
 * Date: 2023-02-04
 * Time: 13:52
 */
public class Main {
    public static User login(){
        System.out.println("��������");
        Scanner scanner =new Scanner(System.in);
        String name=scanner.nextLine();
        System.out.println("���ǹ���Ա(1)�����û�(0)");
        int choice =scanner.nextInt();
        if(choice==1)
            return new Adminuser(name);
        else
            return new Regularuser(name);

    }

    public static void main(String[] args) {
        Booklist booklist =new Booklist();

        User user=login();
        while(true) {
            int choice = user.menu();
        }
    }
}
