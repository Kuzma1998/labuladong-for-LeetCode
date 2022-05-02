// 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
// 回文字符串 是正着读和倒过来读一样的字符串。
// 子字符串 是字符串中的由连续字符组成的一个序列。
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
// 示例 1：
// 输入：s = "abc"
// 输出：3
// 解释：三个回文子串: "a", "b", "c"
// 示例 2：
// 输入：s = "aaa"
// 输出：6
// 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
// DP

class Solution {
public:
    int countSubstrings(string s) {
        int sz = s.size();
        vector<vector<bool>> dp(sz,vector<bool>(sz,0));
        int ans=0;
        for(int i=sz-1;i>=0;--i){
            for(int j=sz-1;j>=i;--j){
                // 状态转移方程
                if(s[i]==s[j]){
                    if(j-i<2){
                        dp[i][j]=true;
                        ++ans;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                        if(dp[i][j])
                            ++ans;
                    }
                }

            }
        }
        return ans;
    }
};