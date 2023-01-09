#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct stu {
	char name[20];
	int age;
	char gender[10];
	char id[15];
};
int main() {
	//打印结构体信息
	struct stu s = { "taylor swift",30,"female","1989" };
	printf("%s %d %s %s\n", s.name,s.age,s.gender,s.id);
	struct stu* p=&s;
	printf("%s %d %s %s\n", p->name, p->age, p->gender, p->id);
		return 0;
}