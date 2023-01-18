#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int MyStrlen(char* arr)
{
	int ret = 0;
	while (*arr != 0)
	{
		ret++;
		arr++;
	}
	return ret;
}
void Mystrcpy(char* arr,char *arr1)
{
	while (*arr1 != 0)
	{
		*(arr++) = *(arr1++);
	}
}
int Mystrcmp(int* arr, int* arr1)
{
	while ((*arr != 0) && (*arr1 != 0))
	{
		while (*arr1 == *arr)
				{
					if (*arr == '\0')
						return 0;
					arr++;
					arr1++;
				}
				if (*arr > *arr1)
					return 1;
				else
					return -1;
	}
}
//int main()
//{
//	char arr[] = "abcdef";
//	char arr1[] = "abfgh";
//	//int ret = MyStrlen(arr);
//	// Mystrcpy(arr,arr1);
//	int ret = Mystrcmp(arr, arr1);
//	if (ret == 1)
//		printf("arr>arr1");
//	else if (ret == -1)
//		printf("arr<arr1");
//	else
//		printf("arr=arr1");
//}

void MyStrcat(char* arr1, char* arr2)
{
	char* s = arr1;
	while (*arr1 )
		arr1++;
	while (*arr2 )
	{
		*arr1 = *arr2;
		arr2++;
		arr1++;
	}
	*(++arr1) = 0;
	printf("%s", s);
}
//int main()
//{
//	char arr1[10] = "abc";
//	char arr2[] = "def";
//	MyStrcat(arr1, arr2);
//}

char* my_strstr(const char* str1, const char* str2)
{
	//assert(str1 && str2);
	if (*str2 == '\0')
	{
		return (char*)str1;
	}
	const char* s1 = NULL;
	const char* s2 = NULL;
	const char* cp = str1;

	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while (*s1 !='\0' && *s2!='\0' && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)cp;
		}
		cp++;
	}

	return NULL;
}

//int main()
//{
//	/*char str[] = "a.b.c.d";
//	char* p;
//	p = strtok(str, ".");
//	while (p != NULL)
//	{
//		printf("%s\n", p);
//		p = strtok(NULL, ".");
//	}*/
//
//	int i = 0;
//	char str[] = "aAbBcC";
//	char c;
//	while (str[i])
//	{
//		c= str[i];
//		if (isupper(c))
//			c = tolower(c);
//		putchar(c);
//		i++;
//	}
//}

void* memcpy(void* dst, void* src, size_t count)
{
	void* ret = dst;
	while (count--)
	{
		*(char*)dst = *(char*)src;
		dst = (char*)dst + 1;
		src = (char*)src + 1;
	}
	return ret;

}
#include<string.h>;
//int main()
//{
//	char src[50] = "hello,world";
//	printf("%d", strlen(src));
//}

int main()
{
	int errorNums[2] = {0};
	int nums[4] = { 1, 2, 2, 4 };
	int numsSize = 4;
	int* a = nums;
	a++;
	int* b = nums;
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = 0; j < numsSize - 1 - i; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				int tmp;
				tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
		}
	}
	while (1)
	{

		if ((*a) == (*b))
		{
			errorNums[0] = *b;
			errorNums[1] = *a;
			break;
		}
		if (*a - *b > 1)
		{
			errorNums[0] = *b;
			errorNums[1] = *b + 1;
			break;
		}

		b++;
		a++;
	}

}