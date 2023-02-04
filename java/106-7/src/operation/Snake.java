package operation;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 13378343877
 * Date: 2023-02-04
 * Time: 20:49
 */
public class Snake extends Animal implements hunt{
    public Snake(String name) {
        super(name);
    }
    public static void huntanimal(hunt hunt){
        hunt.dowork();
    }

    @Override
    public void dowork() {
        System.out.println(name+"³ÔÍÃ×Ó");
    }

    public static void main(String[] args) {
        Snake snake=new Snake("Éß");
        huntanimal(snake);
    }
}
