/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-22 17:11:40
 */
// 给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。
// 返回所有可能的结果。答案可以按 任意顺序 返回。
// 示例 1：
// 输入：s = "()())()"
// 输出：["(())()","()()()"]
// 示例 2：
// 输入：s = "(a)())()"
// 输出：["(a())()","(a)()()"]
// 示例 3：
// 输入：s = ")("
// 输出：[""]
// DFS
class Solution {
public:
    vector<string> ans;
    vector<string> removeInvalidParentheses(string s) {
        // 统计s需要删除的右括号和左括号
        int l=0,r=0;
        for(auto c:s){
            if(c=='(')
                ++l;
            else if(c==')'){
                if(l<=0)
                    r++;
                else l--;
            }
        }
        backtrack(s,0,l,r);
        return ans;
    }

    void backtrack(string s,int start,int l,int r){
        if(l==0&&r==0){
            if(isvalid(s)) //判断是否符合
                ans.push_back(s); 
        }
        for(int i=start;i<s.size();++i){
            if(i!=start&&s[i]==s[i-1])// 剪枝
                continue;
            if(l+r>s.size())//剪枝
                return;
            if(l>0&&s[i]=='(')
                backtrack(s.substr(0,i)+s.substr(i+1),i,l-1,r);
            if(r>0&&s[i]==')')
                backtrack(s.substr(0,i)+s.substr(i+1),i,l,r-1);
        }
    }

    bool isvalid(string& s){
        int cnt = 0;
        for(auto c:s){
            if('('==c)
                ++cnt;
            else if(')'==c){
                --cnt;
                if(cnt<0)
                    return false;
            }
        }
        return true;
    }

};