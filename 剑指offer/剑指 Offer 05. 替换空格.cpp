// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
// 输入：s = "We are happy."
// 输出："We%20are%20happy."


// 思路：定义一个字符串存贮结果即可
class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for(auto c:s){
            if(c!=' '){
                ans += c;
            }else{
                ans+="%20";
            }
        }
        return ans;
    }
};