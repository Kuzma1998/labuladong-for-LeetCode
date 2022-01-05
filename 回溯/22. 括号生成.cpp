/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-15 20:42:57
 */
// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合
// 输入：n = 3
// 输出：["((()))","(()())","(())()","()(())","()()()"]

class Solution {
private:
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        string path = ""; // 路径
        vector<bool> used(2*n,false); // bool数组辅助选择列表的选择是否已经选了
        string choice(n,'(');
        choice += string(n,')');// 选择列表
        backtrack(path,used,choice); // 回溯
        return ans;
    }
    void backtrack(string& path,vector<bool>& used,string& choice){
        if(path.size()==used.size()){ // 当路径的长度等于2n，添加到结果，返回
            ans.push_back(path); 
            return;
        }
        for(int i=0;i<choice.size();++i){  // 选择列表

            if (i > 0 && choice[i] == choice[i - 1] && used[i - 1] == false) { //树的层级剪枝
                continue;
            }
            if(used[i]) // 用过的i跳过
                continue;
            if(!isValid(path,choice[i]))// 判断这个能够插入到path里面,条件是插入之后左括号要大于等于右括号
                continue;
            path += choice[i];
            used[i] = true;
            backtrack(path,used,choice);
            path.pop_back();
            used[i] = false;
        }
        return;
    }
    bool isValid(string str,char c){
        str += c;
        int count1=0;
        int count2=0;
        for(auto i:str){
            if(i=='(')
                ++count1;
            else
                ++count2;
        }
        if(count1>=count2)
            return true;
        return false;
    }
};