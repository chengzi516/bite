package cn.edu.cwnu.cs.lqr01;

/**
 * @author: Li Qinru
 * @Date: 2022/11/17 12:20 AM
 */
public class SystemClass {
    public static void main(String[] args) {

//        System.exit(0);

//        long currentTime = System.currentTimeMillis();//1669289708828
//        //1669289751142
//        System.out.println(currentTime);

        int[] arr1 = {1,2,3,4,5,6,7,8,9,10};
        int[] arr2 = new int[10];

        System.arraycopy(arr1,0,arr2,0,10);

        for (int i = 0; i < arr2.length; i++) {
            System.out.print(arr2[i]+" ");
        }
    }
}
