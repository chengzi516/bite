package operation;

import book.Book;
import book.Booklist;

import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 13378343877
 * Date: 2023-02-04
 * Time: 20:12
 */
public class deletebook implements operation{
    @Override
    public void work(Booklist booklist) {
        System.out.println("请输入要删除的图书");
        Scanner scanner=new Scanner(System.in);
        String bookname=scanner.nextLine();
        int currentsize= booklist.getUsedsize();
        int index=-1;
        for (int i = 0; i <currentsize ; i++) {
            Book book=booklist.getPos(i);
            if(bookname.equals(book.getBookname())){
                index=i;
                break;
            }
        }
        if(index==-1)
            System.out.println(" 未找到图书");
    }
}
