#define _CRT_SECURE_NO_WARNINGS 1
bool isValid(char* s) {
    // oj题目给的提示：1 <= s.length <= 104  说明s中一定是有字符串的  不考虑空串或者s为空的情况
    int size = strlen(s);
    Stack st;
    StackInit(&st);
    bool isMatch = true;
    for (int i = 0; i < size; ++i)
    {
        // 如果是左括号则入栈
        if (('(' == s[i]) || ('[' == s[i]) || ('{' == s[i]))
        {
            StackPush(&st, s[i]);
        }
        else
        {
            // 拿到的是右括号
            // 此时: 需要从栈顶获取左括号来检测是否匹配
            // 注意：一定要保证栈中有元素才可以获取栈顶元素
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
                // 没有匹配
                // StackDestroy(&st);
                // return false;
                isMatch = false;
                break;
            }
        }
    }


    // 如果完全匹配，则循环结束时，栈一定是空的
    // 否则说明：左括号比右括号多
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
// Java答案
/*
    解题思路：
     该题比较简单，是对栈特性很好的应用，具体操作如下：
     循环遍历String中的字符，逐个取到每个括号，如果该括号是：
        1. 左括号，直接入栈
        2. 右括号，与栈顶的左括号进行匹配，如果不匹配直接返回false
           否则继续循环
     循环结束后，如果栈空则匹配，否则左括号比右括号多肯定不匹配
*/
class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            // 如果是左括号则入栈
            if ('(' == ch || '[' == ch || '{' == ch) {
                st.push(ch);
            }
            else {
                // ch为右括号
                // 此时应该到栈顶检测，是否和对应的左括号匹配
                // 注意：要检测必须要保证栈中有元素
                if (st.isEmpty()) {
                    return false;
                }

                char left = st.pop();
                // 如果ch表示右括号与栈顶左括号不匹配时直接返回
                if (!(('(' == left && ')' == ch) ||
                    ('[' == left && ']' == ch) ||
                    ('{' == left && '}' == ch))) {
                    return false;
                }

                // ch表示的右括号 和 left表示的栈顶左括号匹配
                // 继续循环检测
            }
        }
        // 左括号比右括号多，也不匹配
        if (!st.isEmpty()) {
            return false;
        }
        return true;
    }
}
