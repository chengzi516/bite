package cn.edu.cwnu.cs.lqr01;

import java.util.Objects;

/**
 * @author: Li Qinru
 * @Date: 2022/11/28 3:52 PM
 */
public class Student implements Comparable<Student>{

    private String name;
    private int age;

    public Student(){
    }

    public Student(String name, int age){
        this.name = name;
        this.age = age;
    }

    public String getName(){
        return name;
    }

    public void setName(String name){
        this.name = name;
    }

    public int getAge(){
        return age;
    }

    public void setAge(){
        this.age = age;
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Student student = (Student) o;
        return age == student.age && Objects.equals(name, student.name);
    }
//
    @Override
    public int hashCode() {
        return Objects.hash(name, age);
    }


    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }

    @Override
    public int compareTo(Student o) {
        //指定排序的规则
        //只看年龄，我想要按照年龄的升序进行排列
        //int result = this.getAge() - o.getAge();
        int result = o.getAge() -this.getAge() ;
        return result;
    }
}
