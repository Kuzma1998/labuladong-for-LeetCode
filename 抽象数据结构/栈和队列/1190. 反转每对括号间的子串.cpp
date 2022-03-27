// 给出一个字符串 s（仅含有小写英文字母和括号）。

// 请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。
// 注意，您的结果中 不应 包含任何括号
// 示例 1：
// 输入：s = "(abcd)"
// 输出："dcba"
// 示例 2：
// 输入：s = "(u(love)i)"
// 输出："iloveu"
// 解释：先反转子字符串 "love" ，然后反转整个字符串。
// 示例 3：
// 输入：s = "(ed(et(oc))el)"
// 输出："leetcode"
// 解释：先反转子字符串 "oc" ，接着反转 "etco" ，然后反转整个字符串。

// 两个栈

class Solution {
public:
    string reverseParentheses(string s) {
        int sz = s.size();
        stack<char> stk;
        stack<string> res;
        string ans="";
        for(int i=0;i<s.size();++i){
            if(s[i]>='a'&&s[i]<='z'){
                ans += s[i];
            }
            if(s[i]=='('){
                stk.push(s[i]);
                res.push(ans);
                ans = "";
            }
            if(s[i]==')'){
                stk.pop();
                reverse(ans.begin(),ans.end());
                res.top() += ans;
                ans = res.top();
                res.pop();
            }
        }
        return ans;
    }
};