



// 回溯 记得去重

class Solution {
vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        string left(n,'(');
        string right(n,')');
        string str = left+right;
        vector<bool> used(2*n,false);
        backtrack(str,used,"");
        return res;
    }
    void backtrack(string& str,vector<bool>& used,string s){
        if(s.size()==str.size()){
            if(isValid(s)){
                res.push_back(s);
            }
            return;
        }
        for(int i=0;i<str.size();++i){
            if(used[i])  // 去重
                continue;  
            if(i>0&&str[i]==str[i-1]&&!used[i-1])  //去重
                continue;
            used[i] = true;
            backtrack(str,used,s+str[i]);
            used[i] = false;
        }
    }

    bool isValid(string s){
        int sz = s.size();
        if(sz<2)
            return true;
        stack<char> stk;
        for(int i=0;i<sz;++i){
            if(s[i]=='(')
                stk.push(s[i]);
            else{
                if(stk.empty()){
                    return false;
                }
                stk.pop();
            }
        }
        return  stk.empty()?true:false;
    }
};