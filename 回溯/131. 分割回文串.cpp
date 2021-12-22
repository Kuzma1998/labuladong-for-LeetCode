/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-22 22:20:11
 */
// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
// 回文串 是正着读和反着读都一样的字符串。
// 输入：s = "aab"
// 输出：[["a","a","b"],["aa","b"]]


class Solution {
private:
    vector<vector<string>> ans;
    vector<string> path;
public:
    vector<vector<string>> partition(string s) {
        backtrack(s,0);
        return ans;
    }

    void backtrack(string s,int index){
        if(index>=s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=index;i<s.size();++i){
            if(isHuiwen(s,index,i)){
                path.push_back(s.substr(index,i-index+1)); //是回文加入路径，在回溯
            }
            else{
                continue;
            }
            backtrack(s,i+1);
            path.pop_back();
        }
    }
    bool isHuiwen(string s,int start,int end){
        for(;start<=end;++start,--end){
            if(s[start]!=s[end])
                return false;
        }
        return true;
    }
};