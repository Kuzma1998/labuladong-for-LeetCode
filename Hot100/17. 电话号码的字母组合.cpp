// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
// 示例 1：
// 输入：digits = "23"
// 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 示例 2：
// 输入：digits = ""
// 输出：[]
// 示例 3：
// 输入：digits = "2"
// 输出：["a","b","c"]
//  

// 回溯
class Solution {
vector<string> ans;
vector<string> num2str;
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};     
        num2str = {"","","abc","def","ghi",
        "jkl","mno","pqrs","tuv","wxyz"};
        backtrack(digits,0,"");
        return ans;
    }
    void backtrack(string digits,int index,string str){
        if(index==digits.size()){
            ans.push_back(str);
            return;
        }
        char c = digits[index];
        string temp =num2str[c-'0'];
        for(auto s:temp){
            backtrack(digits,index+1,str+s);
        }
        return;
    }
};