/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: 13378343877
 * Date: 2023-01-28
 * Time: 14:54
 */
public class digui {
    public static void digui(int x) {
       if(x>10)
       {
           digui(x/10);
       }
        System.out.println(x%10);
    }

    public static int digui2(int x) {
       if(x<10)
           return x;
       return x%10+digui2(x/10);

    }

    public static int sum(int x) {
               if(x==1)
                   return 1;
               return x+sum(x-1);
    }
    public static void main1(String[] args) {
        digui(123);
        int x=digui2(123);
        System.out.println(x);
        int y=sum(3);
        System.out.println(y);
    }

    public static void hanoi(int n,String a,String b,String c) {
        if(n==1)
            System.out.println(a+"--->"+c);
        else
        {
            hanoi(n-1,a,c,b);
            System.out.println(a+"--->"+c);
            hanoi(n-1,b,a,c);
        }
    }
    public static void main(String[] args) {
        hanoi(3,"AÖù","BÖù","CÖù");
    }

}
