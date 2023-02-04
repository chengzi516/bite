package operation;

import book.Booklist;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 13378343877
 * Date: 2023-02-04
 * Time: 20:25
 */
public class exitsystem implements  operation{
    @Override
    public void work(Booklist booklist) {
        System.out.println("ÍË³öÏµÍ³");
        System.exit(0);
    }
}
