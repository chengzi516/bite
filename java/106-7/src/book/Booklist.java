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
        System.out.println("��һ��Բ");
    }

}
class rect extends shape{
    public rect()
    {

    }
    public void draw(){
        System.out.println("��һ������");
    }
}
public class Booklist {
    Book []books =new Book[10]; //�ͽ������趨Ϊ10��
    int usedsize; //Ŀǰ�洢�鼮�ı�����

   public Booklist(){
       books[0]=new Book("������","����","��ѧ",22);
       books[1]=new Book("�˼�ʧ��","̫����","��ѧ",27);
       books[2]=new Book("�������ǻ�","�屾��","��ѧ",56);
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
