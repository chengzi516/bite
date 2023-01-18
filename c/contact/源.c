#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct peoinfo
{
	char name[20];
	int age;
	char gender[5];
	char number[12];
};

typedef struct contact
{
	struct peoinfo data[100];
	int sz;
}con;
void menu()
{
	printf("1.增加联系人\n");
	printf("2.删除联系人\n");
	printf("3.查找联系人\n");
	printf("4.修改联系人\n");
	printf("5.显示所有联系人\n");
	printf("6.删除所有联系人\n");
	printf("7.排序所有联系人\n");

}
void initcon(con* p)
{
	p->sz = 0;
	memset(p->data, 0, sizeof(p->data));
}
void  add(con* p)
{
	
	printf("input name\n");
	scanf("%s", p->data[p->sz].name);
	printf("input age\n");
	scanf("%d", &(p->data[p->sz].age));
	printf("input gender\n");
	scanf("%s", p->data[p->sz].gender);
	printf("input number\n");
	scanf("%s", p->data[p->sz].number);
	p->sz++;
}

void print(con* p)
{
	for (int i = 0; i < p->sz; i++)
	{
		printf("");
		printf("%-20s\t%-4d\t%-5s\t%-12s\n", p->data[i].name, p->data[i].age, p->data[i].gender, p->data[i].number);
	}
}
void del(con* p)
{
	printf("inout name you want to del\n");
	char name[20] = { 0 };
	scanf("%s", name);
	int pos = 0;
	for (int i = 0; i < p->sz; i++)
	{
		if (strcmp(p->data[i].name, name) == 0)
		{
			pos = i;
			break;
		}
	}
	for (int i = pos; i < p->sz-1; i++)
	{
		p->data[i] = p->data[i + 1];
	}
	p->sz--;
	printf("del successfully\n");

}
void check(con* p)
{
	printf("inout name you want to find\n");
	char name[20] = { 0 };
	scanf("%s", name);
	int i = 0;
	for ( i = 0; i < p->sz; i++)
	{
		if (strcmp(p->data[i].name, name) == 0)
		{
			
			break;
		}
	}
	printf("find it\n");
	printf("%-20s\t%-4d\t%-5s\t%-12s\n", p->data[i].name, p->data[i].age, p->data[i].gender, p->data[i].number);

}
void modify(con* p)
{
	printf("inout name you want to modify\n");
	char name[20] = { 0 };
	scanf("%s", name);
	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		if (strcmp(p->data[i].name, name) == 0)
		{

			break;
		}
	}
	printf("input name\n");
	scanf("%s", p->data[i].name);
	printf("input age\n");
	scanf("%d", &(p->data[i].age));
	printf("input gender\n");
	scanf("%s", p->data[i].gender);
	printf("input number\n");
	scanf("%s", p->data[i].number);
}
void delall(con* p)
{
	initcon( p);
	printf("del all!\n");
}
int cmp(void* e1, void* e2)
{
	return strcmp(((struct peoinfo*)e1)->name, ((struct peoinfo*)e2)->name);
	printf("sort successfully\n");
}
char* GetMemory(void)
{
	char p[] = "hello world";
	return p;
}
int main()
{

	char* str = NULL;
	str = GetMemory();
	printf(str);
	int input = 0;
	con con;
	//初始化
	initcon(&con);
	do
	{
		menu();
		printf("choose");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			add(&con);
			break;
		case 2:
			del(&con);
			break;
		case 3:
			check(&con);
			break;
		case 4:
			modify(&con);
			break;
		case 5:
			print(&con);
			break;
		case 6:
			delall(&con);
			break;
		case 7:
			qsort(con.data, con.sz,sizeof( con.data[0]), cmp);
			break;

		}
	} while (1);
	return 0;
}