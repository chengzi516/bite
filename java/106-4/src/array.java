import java.util.Arrays;
/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 13378343877
 * Date: 2023-01-28
 * Time: 19:52
 */
public class array {

//    public static void change(int []tmp) {
//        tmp=new int[10];
//        System.out.println(Arrays.toString(tmp));
//    }
//    public static void main(String[] args) {
////        int []arr= new int[]{1,2,3};
////        String a=Arrays.toString(arr);
////        System.out.println(a);
//        int []arr2=new int[]{1,2,3};
//        change(arr2);
//        System.out.println(Arrays.toString(arr2));
//
//    }

    String name;
    int age;
    String gender;
    public array(String a,int b,String c)
    {
        this.name=a;
        this.gender=c;
        this.age=b;
    }
    public void SetPerson(String a,int b,String c)
    {
        this.name=a;
        this.age=b;
        this.gender=c;
    }
    public void PrintPerson()
    {
        System.out.println("student's name is "+this.name+" and age is "+this.age+" and the gender is "+this.gender);
    }

    public static void main(String[] args) {
        array stu1 =new array("taylor",12,"male");
      //  stu1.SetPerson("taylor",12,"male");
        stu1.PrintPerson();
    }

}
