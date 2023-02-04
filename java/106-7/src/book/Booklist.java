package book;

import java.util.Arrays;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 13378343877
 * Date: 2023-02-04
 * Time: 12:52
 */
abstract class shape{
    abstract void draw();

    public shape() {
    }
}
class cycle extends shape{
    public cycle() {
    }
    public void draw(){
        System.out.println("画一个圆");
    }

}
class rect extends shape{
    public rect()
    {

    }
    public void draw(){
        System.out.println("画一个矩形");
    }
}
public class Booklist {
    Book []books =new Book[10]; //就将数量设定为10本
    int usedsize; //目前存储书籍的本数。

   public Booklist(){
       books[0]=new Book("局外人","加缪","文学",22);
       books[1]=new Book("人间失格","太宰治","文学",27);
       books[2]=new Book("人生的智慧","叔本华","文学",56);
       this.usedsize=3;
   }

    public Book[] getBooks() {
        return books;
    }

    public void setBooks(Book[] books) {
        this.books = books;
    }

    public int getUsedsize() {
        return usedsize;
    }

    public void setUsedsize(int usedsize) {
        this.usedsize = usedsize;
    }

    public static void main(String[] args) {
        Booklist booklist=new Booklist();
        System.out.println(Arrays.toString(booklist.getBooks()));
    }


}
