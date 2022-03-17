/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-17 10:49:06
 */
// 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
// 示例 1：
// 输入：s = "(()"
// 输出：2
// 解释：最长有效括号子串是 "()"
// 示例 2：
// 输入：s = ")()())"
// 输出：4
// 解释：最长有效括号子串是 "()()"
// 示例 3：
// 输入：s = ""
// 输出：0

// 思路：栈

class Solution {
public:
    int longestValidParentheses(string s) {
    // 具体做法是我们始终保持栈底元素为当前已经遍历过的元素中
    // 「最后一个没有被匹配的右括号的下标」，
    // 这样的做法主要是考虑了边界条件的处理，
    // 栈里其他元素维护左括号的下标：
        int ans = 0;
        if(s.size()==0||s.size()==1)
            return ans;
        stack<int> stk;
        stk.push(-1);
        for(int i=0;i<s.size();++i){
            if(s[i]=='(')
                stk.push(i);
            else{
                stk.pop();
                if(stk.empty()){
                    stk.push(i); // 未匹配的右括号放进去
                }else{
                    ans = max(ans,i-stk.top());
                }
            }
        }
        return ans;
       
    }
};


//dp