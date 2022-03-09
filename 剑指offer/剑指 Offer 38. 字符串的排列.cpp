// 输入一个字符串，打印出该字符串中字符的所有排列。
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

// 回溯
class Solution {
private:
    vector<string> ans;
    string path;
public:
    vector<string> permutation(string s) {
        int sz = s.size();
        sort(s.begin(),s.end(),[](const char& a,const char& b){return a<b;});
        vector<bool> used(sz,false);
        backtrack(s,used);
        return ans;
    }
    void backtrack(string& s,vector<bool>& used){
        if(path.size()==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<s.size();++i){
            if(used[i])
                continue;
            if(i>0&&s[i]==s[i-1]&&!used[i-1])
                continue;
            used[i] = true;
            path += s[i];
            backtrack(s,used);
            used[i] = false;
            path.pop_back();
        }
        return;
    }
};