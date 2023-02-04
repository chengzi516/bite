package user;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 13378343877
 * Date: 2023-02-03
 * Time: 21:26
 */
public abstract class User {
     String name;
    public User(){
    }
    public abstract int menu();
    public User(String name) {
        this.name = name;
//        System.out.println("调用了只需name的构造方法");
    }
//    public User(String name,int age){
//        this.age=age;
//        this.name=name;
//        System.out.println("调用了需要name和age的构造方法");
//    }

//    public static void main(String[] args) {
//        User person1=new User("taylor");
//        System.out.println(person1.age);
//    }

}
