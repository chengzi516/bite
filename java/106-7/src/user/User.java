package user;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 13378343877
 * Date: 2023-02-03
 * Time: 21:26
 */
public class User {
    private String name;
    int age;
    public User()
    {
        this.name="xiaoming";
        this.age=12;
        System.out.println("调用了无参构造方法");
    }
    public User(String name) {
        this.name = name;
        System.out.println("调用了只需name的构造方法");
    }
    public User(String name,int age){
        this.age=age;
        this.name=name;
        System.out.println("调用了需要name和age的构造方法");
    }

    public static void main(String[] args) {
        User person1=new User("taylor");
        System.out.println(person1.age);
    }
}
