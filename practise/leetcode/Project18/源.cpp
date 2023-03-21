#define _CRT_SECURE_NO_WARNINGS 1
bool isValid(char* s) {
    // oj��Ŀ������ʾ��1 <= s.length <= 104  ˵��s��һ�������ַ�����  �����ǿմ�����sΪ�յ����
    int size = strlen(s);
    Stack st;
    StackInit(&st);
    bool isMatch = true;
    for (int i = 0; i < size; ++i)
    {
        // ���������������ջ
        if (('(' == s[i]) || ('[' == s[i]) || ('{' == s[i]))
        {
            StackPush(&st, s[i]);
        }
        else
        {
            // �õ�����������
            // ��ʱ: ��Ҫ��ջ����ȡ������������Ƿ�ƥ��
            // ע�⣺һ��Ҫ��֤ջ����Ԫ�زſ��Ի�ȡջ��Ԫ��
            if (StackEmpty(&st))
            {
                //StackDestroy(&st);
                //return false;
                isMatch = false;
                break;
            }


            char top = StackTop(&st);
            if ((top == '(' && s[i] == ')') ||
                (top == '[' && s[i] == ']') ||
                (top == '{' && s[i] == '}'))
            {
                StackPop(&st);
            }
            else
            {
                // û��ƥ��
                // StackDestroy(&st);
                // return false;
                isMatch = false;
                break;
            }
        }
    }


    // �����ȫƥ�䣬��ѭ������ʱ��ջһ���ǿյ�
    // ����˵���������ű������Ŷ�
    if (!StackEmpty(&st))
    {
        //StackDestroy(&st);
        //return false;
        isMatch = false;
    }


    StackDestroy(&st);
    return isMatch;
}

///////////////////////////////////////////////////////////////////////
// Java��
/*
    ����˼·��
     ����Ƚϼ򵥣��Ƕ�ջ���Ժܺõ�Ӧ�ã�����������£�
     ѭ������String�е��ַ������ȡ��ÿ�����ţ�����������ǣ�
        1. �����ţ�ֱ����ջ
        2. �����ţ���ջ���������Ž���ƥ�䣬�����ƥ��ֱ�ӷ���false
           �������ѭ��
     ѭ�����������ջ����ƥ�䣬���������ű������Ŷ�϶���ƥ��
*/
class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            // ���������������ջ
            if ('(' == ch || '[' == ch || '{' == ch) {
                st.push(ch);
            }
            else {
                // chΪ������
                // ��ʱӦ�õ�ջ����⣬�Ƿ�Ͷ�Ӧ��������ƥ��
                // ע�⣺Ҫ������Ҫ��֤ջ����Ԫ��
                if (st.isEmpty()) {
                    return false;
                }

                char left = st.pop();
                // ���ch��ʾ��������ջ�������Ų�ƥ��ʱֱ�ӷ���
                if (!(('(' == left && ')' == ch) ||
                    ('[' == left && ']' == ch) ||
                    ('{' == left && '}' == ch))) {
                    return false;
                }

                // ch��ʾ�������� �� left��ʾ��ջ��������ƥ��
                // ����ѭ�����
            }
        }
        // �����ű������Ŷ࣬Ҳ��ƥ��
        if (!st.isEmpty()) {
            return false;
        }
        return true;
    }
}
