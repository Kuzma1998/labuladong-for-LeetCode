// 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
// 在 S 上反复执行重复项删除操作，直到无法继续删除。
// 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一
// 输入："abbaca"
// 输出："ca"
// 解释：
// 例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。
// 之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。


// 自己写的垃圾代码

class Solution {
public:
    string removeDuplicates(string s) {
        if(s.size()==1||s.size()==0)
            return s;
        stack<char> stk;
        int i=0;
        while(i<s.size()){
            if(i==0){
                stk.push(s[i]);
                ++i;
            }
            else if(s[i]==stk.top()){
                stk.pop();
                s.erase(i-1,2);
                --i;
            }
            else{
                stk.push(s[i]);
                ++i;
            }
        }
        return s;

    }
};


// 优化
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        // 存到栈里的一定是不重复的元素
        for (char s : S) {
            if (st.empty() || s != st.top()) {// 只要与栈顶元素不同就放进去，栈顶就是上一个元素
                st.push(s);
            } else {
                st.pop(); // s 与 st.top()相等的情况
            }
        }
        string result = "";
        while (!st.empty()) { // 将栈中元素放到result字符串汇总
            result += st.top();
            st.pop();
        }
        reverse (result.begin(), result.end()); // 此时字符串需要反转一下
        return result;

    }
};
