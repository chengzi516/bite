#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
// 基类
//class Base {
//public:
//    void display() {
//        std::cout << "Base class" << std::endl;
//    }
//};
//
//// 派生类
//class Derived : public Base {
//public:
//    void display() {
//        std::cout << "Derived class" << std::endl;
//    }
//};

class Person
{
public:
    Person() { ++_count; }
protected:
    std::string _name; 
public:
    static int _count; 
};
int Person::_count = 0;
class Student : public Person
{
protected:
    int _stuNum; // 学号
};
class Graduate : public Student
{
protected:
    std::string _seminarCourse; // 研究科目
};
void test() {
   
   
        Student s1;
        Student s2;
        Student s3;
        Graduate s4;
        std::cout << " 人数 :" << Person::_count << std::endl;
        Student::_count = 0;
        std::cout << " 人数 :" << Person::_count << std::endl;
    

}
//int main() {
//    //Derived derivedObj;
//    //Base* basePtr = &derivedObj; // 向上转换
//
//    //basePtr->display(); // 输出 "Base class"，即使是派生类对象，调用的也是基类的函数
//    Base baseObj;
//    Derived derivedObj;
//    Base* basePtr = &derivedObj;
//
//    basePtr->display(); // 输出 "Derived class"，通过基类指针调用派生类的函数
//    //Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
//    //if (derivedPtr != nullptr) {
//    //    derivedPtr->display(); // 输出 "Derived class"
//    //}
//    //else {
//    //    std::cout << "Failed to downcast" << std::endl;
//    //}
//
//    test();
//
//    return 0;
//}

class A
{
public:
    int _a;
};
// class B : public A
class B : virtual public A
{
public:
    int _b;
};
// class C : public A
class C : virtual public A
{
public:
    int _c;
};
class D : public B, public C
{
public:
    int _d;
};
class Base
{
public:
    virtual void print1()
    {
        std::cout << "Base::print1()" << std::endl;
    }
    virtual void print2()
    {
        std::cout << "Base::print2()" << std::endl;

    }
    void print3()
    {
        std::cout << "Base::print3()" << std::endl;

    }
private:
    int _b = 1;
};
class Derive : public Base
{
public:
    virtual void print1()
    {
        std::cout << "Base::print1()" << std::endl;

    }
private:
    int _d = 2;
};
int main()
{
    Base b;
    Derive d;
    return 0;
}