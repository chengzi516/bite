#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char arr1[] = "this is amazing!";
//	char arr2[] = "****************";//�����������飬ʹ�����ͬ�����ȡ�
//	int left=0;
//	int right = strlen(arr1) - 1; //ͬ���ֲ�����ͬ��ʹ�������±��������ַ����ĸĶ���
//	printf("%s", arr2);
//	while (left<=right) //ѭ������Ҳͬ���ֲ��ң������±��ƶ�����ͬλ����ֹͣ��ӡ��
//	{
//		
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		printf("%s", arr2);
//		Sleep(1000); //ʹ��sleep����ʹ��ӡ���߲�θ�
//		system("cls");  //ִ��������Ļ��ָ��
//	}
//}
//#include<stdio.h>
//int main()
//{
//	char password[20] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("input the password\n");
//		scanf("%s", password);//�������Ѿ��ǵ�ַ������ȡַ��&
//		if ((strcmp(password, "123456")) == 0)
//		{
//			printf("right!\n");
//				break;
//		}
//		else
//		{
//			printf("try it again\n");
//		}
//	}
//	if (i == 3)
//		printf("exit\n");
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//void menu()
//{
//	printf("*****1 play game*****\n");
//	printf("*****0 game  over*****\n");
//}
//void game()
//{
//	int num = rand() % 100 + 1;//�κ�������100���������1-99֮�䣬�ټ�1������1-100
//	int b;
//	
//	while (1)
//	{
//		printf("input your number\n");
//		scanf("%d", &b);
//		if (b > num)
//		{
//			printf("your num is bigger\n");
//		}
//		else if (b < num)
//		{
//			printf("your num is smaller\n");
//		}
//		else
//		{
//			printf("right!\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int a = 0;
//	srand((unsigned)time(NULL));
//	do
//	{
//		menu();
//		printf("choose\n");
//		scanf("%d", &a);
//		switch (a)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("error,try it again");
//		}
//	} while (a);
//	return 0;
//}
//#include<stdio.h>
//
//int main()
//{
//
//	char a[20] = "";
//	system("shutdown -s -t 60"); //�ػ�ָ��Ϊshutdown -s��-t���������ڶ������
//again:
//	printf("�����ػ���������123456ֹͣ�ػ�����\n");
//	scanf("%s", a);
//	if ((strcmp(a, "123456")) == 0)
//	{
//		system("shutdown -a"); //ȡ���ػ�ָ��
//	}
//	else
//	{
//		goto again;
//	}
//
//	return 0;
//}