package operation;

import book.Book;
import book.Booklist;

import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 13378343877
 * Date: 2023-02-04
 * Time: 20:02
 */
public class addbook implements operation{
    @Override
    public void work(Booklist booklist) {
        System.out.println("������Ҫ��ӵ�ͼ��");
        Scanner scanner=new Scanner(System.in);
        String bookname=scanner.nextLine();
        System.out.println("������ͼ������");
        String bookauthor=scanner.nextLine();
        System.out.println("������ͼ������");
        String booktype=scanner.nextLine();
        System.out.println("������ͼ��۸�");
        int bookprice=scanner.nextInt();
        Book book =new Book(bookname,bookauthor,booktype,bookprice);
        int currentsize=booklist.getUsedsize();
        booklist.setBooks(book,currentsize);
        booklist.setUsedsize(currentsize+1);

    }
}
