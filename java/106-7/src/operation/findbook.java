package operation;

import book.Book;
import book.Booklist;

import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 13378343877
 * Date: 2023-02-04
 * Time: 19:48
 */
public class findbook implements operation {
    public  void work(Booklist booklist) {
        System.out.println("请输入需要查找的图书");
        Scanner scanner=new Scanner(System.in);
        String bookname=scanner.nextLine();
        int currentsize=booklist.getUsedsize();
        for (int i = 0; i <currentsize ; i++) {
            Book book=booklist.getPos(i);
            if(bookname.equals(book.getBookname())){
                System.out.println("找到了");
                System.out.println("book");
                return;
            }
        }
        System.out.println("没找到");

    }
}
