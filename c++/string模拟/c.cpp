#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include "string.h"
int main() {
 
    const char* str = "hello world";
    newstring::string s2(str);
    std::string s3("hello");
    s2.insert(0, 1,'s');
 //   s2.insert(0, "1212121");
    //std::cout << s3<<std::endl;
    std::cout << s2.c_str() << std::endl;
    //std::cout << s2[1];
  //  std::string s = "111";
    //s += '\0';
    //s += "123"; //string������\0��������ֹ
    //std::cout << s;
    //std::string str1 = "123\\01212121";
    //size_t len = str1.size(); // ��ȡ�ַ����ĳ��ȣ������� null ��β��
    //for (auto c : str1) { // �����ַ��������� null �ַ��ͻ��з�
      //  std::cout << c;
    //}
  //  std::cout << s1.find("ll");
    newstring::string s1("hello world");
    newstring::string ss = s1.substr(2, 3);
    std::cout << ss.c_str();
    return 0;
}