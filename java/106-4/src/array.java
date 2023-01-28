import java.util.Arrays;
/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 13378343877
 * Date: 2023-01-28
 * Time: 19:52
 */
public class array {

    public static void change(int []tmp) {
        tmp=new int[10];
        System.out.println(Arrays.toString(tmp));
    }
    public static void main(String[] args) {
//        int []arr= new int[]{1,2,3};
//        String a=Arrays.toString(arr);
//        System.out.println(a);
        int []arr2=new int[]{1,2,3};
        change(arr2);
        System.out.println(Arrays.toString(arr2));

    }

}
