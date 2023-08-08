#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
// ����
//class Base {
//public:
//    void display() {
//        std::cout << "Base class" << std::endl;
//    }
//};
//
//// ������
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
    int _stuNum; // ѧ��
};
class Graduate : public Student
{
protected:
    std::string _seminarCourse; // �о���Ŀ
};
void test() {
   
   
        Student s1;
        Student s2;
        Student s3;
        Graduate s4;
        std::cout << " ���� :" << Person::_count << std::endl;
        Student::_count = 0;
        std::cout << " ���� :" << Person::_count << std::endl;
    

}
//int main() {
//    //Derived derivedObj;
//    //Base* basePtr = &derivedObj; // ����ת��
//
//    //basePtr->display(); // ��� "Base class"����ʹ����������󣬵��õ�Ҳ�ǻ���ĺ���
//    Base baseObj;
//    Derived derivedObj;
//    Base* basePtr = &derivedObj;
//
//    basePtr->display(); // ��� "Derived class"��ͨ������ָ�����������ĺ���
//    //Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
//    //if (derivedPtr != nullptr) {
//    //    derivedPtr->display(); // ��� "Derived class"
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