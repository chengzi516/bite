#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
typedef struct stack
{
    char* data;
    int size;
    int capacity;
}stack;
//³õÊ¼»¯
void stackinit(stack *p)
{
    p->data = (char*)malloc(sizeof(char) * 4);
    p->size = 1;
    p->capacity = 4;
}
//ÈëÕ»
void stackpush(stack *p,char x)
{
    if (p->capacity == p->size)
    {
        char* tmp = realloc(p->data, p->capacity * 2 * sizeof(char));
        p->data = tmp;
        p->capacity *= 2;

    }
    p->data[p->size] = x;
    p->size++;
}
bool isValid(char* s) {

    stack sk;
    stackinit(&sk);
    int flag = 0;
    for (int i = 0; s[i] != 0; i++)
    {
        switch (s[i])
        {
        case '{':
        case '(':
        case '[':
            stackpush(&sk, s[i]);
            flag++;
            break;
        case '}':
        case ')':
        case ']':
            if ((sk.data[sk.size - 1] == '{' && s[i] == '}') || (sk.data[sk.size - 1] == '[' && s[i] == ']') || (sk.data[sk.size - 1] == '(' && s[i] == ')'))
            {
                sk.size--;
                flag--;
            }
            else
            {
                return false;
            }
            break;
        }

    }
    if (flag == 0)
        return true;
    else
        return false;


}
int main()
{
    char s[] = "]";
    bool a=isValid(s);
    printf("%d", a);
   
}