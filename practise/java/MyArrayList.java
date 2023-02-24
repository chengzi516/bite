package cn.edu.cwnu.cs.generics02;

import java.util.Arrays;

/**
 * @author: Li Qinru
 * @Date: 2022/12/07 3:15 PM
 */
public class MyArrayList<E>{

    Object[] obj = new Object[10];
    int size;

    //E表示不确定的类型
    //e表示形参的名字，变量名
    public boolean add(E e){
        obj[size] = e;
        size++;
        return true;
    }

    //这里需要进行强转
    public E get(int index){
        return (E)obj[index];
    }

    @Override
    public String toString() {
        return Arrays.toString(obj);
    }
}
