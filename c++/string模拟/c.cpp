#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include "string.h"
int main() {
    newstring::string s1("hello world");
    const char* str = "hello world";
    newstring::string s2(str);
    std::string s3("hello");
    s2.insert(0, 1,'s');
    s2.insert(0, "1212121");
    //std::cout << s3<<std::endl;
    std::cout << s2.c_str() << std::endl;
    //std::cout << s2[1];
    return 0;
}