/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-16 16:49:45
 */

// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
// 输入：digits = "23"
// 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]


class Solution {
private:
    vector<string> ans;
    string path="";
    unordered_map<char,string> map;
public:
    vector<string> letterCombinations(string digits) {
        // vector<bool> used(digits.szize(),false);
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxzy";
        backtrack(digits,0);
        return ans;
    }

    void backtrack(string& digits,int start){  // start 为回溯的深度
        if(start==digits.size()){
            ans.push_back(path);// path为节点的结果
            return;
        }
        if(!isValid(digits[start]))
            backtrack(digits,start+1);
            // 单层的遍历
        for(int i=0;i<map[digits[start]].size();++i){
            path += map[digits[start]][i];
            backtrack(digits,start+1);
            path.pop_back();
        }
    }
    // 判断是否非法字符
    bool isValid(char c){
        if(!map.count(c))
            return false;   
        return true;
    }
};
