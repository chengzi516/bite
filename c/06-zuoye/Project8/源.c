#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
void verse(char* s)
{
	int i = strlen(s) ;
again:
	i = i - 1;
	while (s[i] != ' '&& i>=0)
	{
		i--;
	}
	int a = i+1;
	while (s[a] != ' ' && a < strlen(s))
	{
		printf("%c", s[a]);
		a++;
	}
	if (i == -1)
		goto end;
	printf(" ");
	goto again;
end:
	;

}
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	for (int i = digitsSize - 1; i >= 0; i--)
	{
		if ((digits[i]++) != 9)
		{
			*returnSize = digitsSize;
			return digits;
		}
		else
			digits[i] = 0;

	}
	int* newarray = malloc((digitsSize + 1) * sizeof(int));
	for (int i = 1; i < digitsSize+1; i++)
	{
		newarray[i] = 0;
	}
	newarray[0] = 1;
	*returnSize = digitsSize + 1;
	return newarray;
}
int main()
{
	/*char s[100] = "";
	gets(s);
	verse(s);*/
	int nums[] = { 9 };
	int* p = nums;
	plusOne(nums, 1, *p);

}