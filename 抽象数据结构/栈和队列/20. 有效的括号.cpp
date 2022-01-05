
// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
// 有效字符串需满足：
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。

// 堆栈

class Solution
{
private:
    stack<char> stk;

public:
    bool isValid(string s)
    {
        int i = 0;
        if(s.size()==1) 
            return false;
        while (i < s.size())
        {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{')
                stk.push(s[i]);
            else
            {
                if (s[i] == ')')
                {
                    if (stk.empty())
                        return false;
                    if ('('== stk.top())
                    {
                        stk.pop();
                    }
                    else 
                        return false;
                }
                if (s[i] == ']')
                {
                    if (stk.empty())
                        return false;
                    if ('[' == stk.top())
                    {
                        stk.pop();
                    }
                    else
                        return false;
                }
                if (s[i] == '}')
                {
                    if (stk.empty())
                        return false;
                    if ('{' == stk.top())
                    {
                        stk.pop();
                    }
                    else 
                        return false;
                }
            }
            ++i;
        }
        if(!stk.empty())
            return false;
        return true;
    }
};