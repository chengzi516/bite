package cn.edu.cwnu.cs.lqr02;

/**
 * @author: Li Qinru
 * @Date: 2022/11/23 8:54 PM
 */
public class RegexDemo1 {
    public static void main(String[] args) {
//        //判断是否与正则表达式匹配，匹配返回true
//        //public boolean matches(String regex);
//
//        //只能是abc
//        System.out.println("---------1-----------");
//        System.out.println("a".matches("[abc]"));
//        System.out.println("z".matches("[abc]"));
//
//        //不能是abc
//        System.out.println("----------2-----------");
//        System.out.println("a".matches("[^abc]"));
//        System.out.println("z".matches("[^abc]"));
//        System.out.println("zz".matches("[^abc]"));
//
//        //a到z, A到Z(包括头尾的范围)
//        System.out.println("----------3----------");
//        System.out.println("a".matches("[a-zA-Z]"));
//        System.out.println("aa".matches("[a-zA-Z]"));
//        System.out.println("0".matches("[a-zA-Z]"));
//
//        System.out.println("----------4---------");
//        //[a-d[m-p]] a到d, 或m到p
//        System.out.println("a".matches("[a-d[m-p]]"));
//        System.out.println("m".matches("[a-d[m-p]]"));
//        System.out.println("e".matches("[a-d[m-p]]"));
//
//        System.out.println("----------5----------");
//        //[a-z&&[def]] a-z和def的交集。为：d,e,f
//        //如果写成了一个&,那么此时&表示就不是交集了，而是一个简简单单的&符号
//        System.out.println("a".matches("[a-z&&[def]]"));
//        System.out.println("d".matches("[a-z&&[def]]"));
//        System.out.println("0".matches("[a-z&&[def]]"));
//
//        //[a-z&&[^bc]] a到z和非bc的交集。（等同于[ad-z]）
//        System.out.println("-----------6----------");
//        System.out.println("a".matches("[a-z&&[^bc]]"));
//        System.out.println("b".matches("[a-z&&[^bc]]"));
//        System.out.println("0".matches("[a-z&&[^bc]]"));
//
//        //[a-z&&[^m-p]] a到z和除了m到p的交集。（等同于[a-lq-z]）
//        System.out.println("----------7----------");
//        System.out.println("a".matches("[a-z&&[^m-p]]"));
//        System.out.println("m".matches("[a-z&&[^m-p]]"));
//        System.out.println("0".matches("[a-z&&[^m-p]]"));

        System.out.println("Pass_word2".matches("\\w{8,15}"));
//        System.out.println("川A123456".matches("川[a-zA-Z][\\w&&[^_]]{5}"));
    }
}
