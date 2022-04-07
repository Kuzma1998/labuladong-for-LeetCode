// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
// 有效字符串需满足：
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 示例 1：
// 输入：s = "()"
// 输出：true
// 示例 2：
// 输入：s = "()[]{}"
// 输出：true
// 示例 3：
// 输入：s = "(]"
// 输出：false
// 示例 4：
// 输入：s = "([)]"
// 输出：false
// 示例 5：
// 输入：s = "{[]}"
// 输出：true


// 栈

class Solution {
public:
    bool isValid(string s) {
        if(s.size()<2)
            return false;
        if(s[0]==')'||s[0]==']'||s[0]=='}')
            return false;
        stack<char> stk;
        stk.push(s[0]);
        for(int i=1;i<s.size();++i){
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                stk.push(s[i]);
            else if(s[i]==']'){
                if(stk.empty())
                    return false;
                if(stk.top()!='[')
                    return false;
                else{
                    stk.pop();
                }
            }
            else if(s[i]==')'){
                if(stk.empty())
                    return false;
                if(stk.top()!='(')
                    return false;
                else{
                    stk.pop();
                }
            }
            else if(s[i]=='}'){
                if(stk.empty())
                    return false;
                if(stk.top()!='{')
                    return false;
                else{
                    stk.pop();
                }
            }
        }
        return stk.empty()?true:false;
    }
};