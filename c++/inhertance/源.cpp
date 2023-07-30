#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
// ����
class Base {
public:
    void display() {
        std::cout << "Base class" << std::endl;
    }
};

// ������
class Derived : public Base {
public:
    void display() {
        std::cout << "Derived class" << std::endl;
    }
};

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
int main()
{
    D d;
    d.B::_a = 1;
    d.C::_a = 2;
    d._b = 3;
    d._c = 4;
    d._d = 5;
    std::cout << d._a;
    return 0;
}