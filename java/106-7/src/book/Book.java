package book;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 13378343877
 * Date: 2023-02-03
 * Time: 23:53
 */
public class Book {
    private String bookname;
    private String author;
    private String type;
    private int price;
    private boolean isborrowed;

    public Book(String bookname, String author, String type, int price) {
        this.bookname = bookname;
        this.author = author;
        this.type = type;
        this.price = price;
    }

    public String getBookname() {
        return bookname;
    }

    public void setBookname(String bookname) {
        this.bookname = bookname;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public boolean isIsborrowed() {
        return isborrowed;
    }

    public void setIsborrowed(boolean isborrowed) {
        this.isborrowed = isborrowed;
    }

    @Override
    public String toString() {
        return "Book{" +
                "bookname='" + bookname + '\'' +
                ", author='" + author + '\'' +
                ", type='" + type + '\'' +
                ", price=" + price +
                ", isborrowed=" + isborrowed +
                '}';
    }

    public static void main(String[] args) {
        Book book =new Book("aaa","bbb","ccc",12);
//        System.out.println(book.getAuthor());
//        System.out.println(book.isIsborrowed());
//        book.setAuthor("taylor swift");
//        System.out.println(book.author);
        System.out.println(book);

    }
}
