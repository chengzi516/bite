/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 13378343877
 * Date: 2023-02-01
 * Time: 14:51
 */
class father{
    int a;
    int b;
}
class son extends father{
    int c;
    public void method1(){
        a=3;
    }
}
public class inherit extends father{
    public static void main(String[] args) {
         son son=new son();
         son.method1();
         inherit son2 =new inherit();
        System.out.println(son2.a);
    }
}

