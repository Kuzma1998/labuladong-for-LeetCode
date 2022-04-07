// 给你一个字符串 s，找到 s 中最长的回文子串。
// 示例 1：
// 输入：s = "babad"
// 输出："bab"
// 解释："aba" 同样是符合题意的答案。
// 示例 2：
// 输入：s = "cbbd"
// 输出："bb"

//DP
class Solution {
public:
    string longestPalindrome(string s) {
        int sz  = s.size();
        if(sz<2)
            return s;
        vector<vector<bool>> dp(sz,vector<bool>(sz,false));
        int start = 0,end = 0;
        int len = 1;
        for(int i=0;i<sz;++i){
            dp[i][i] = true;
        }
        for(int i=1;i<sz;++i){
            for(int j=0;j<i;++j){
                // 状态转移方程
                if(s[i]==s[j]&&(i-j<=2||dp[j+1][i-1])){
                    dp[j][i] = true;
                    if(i-j+1>len){
                        len = i-j+1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};