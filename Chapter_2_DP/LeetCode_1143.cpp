// 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
// 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
// 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
// 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
//思路，动态规划。对于两个序列，一般定义二维动态规划数组,dp[i][j]意思就是数组1长度为i，数组2长度为j的最长公共子序列
//那么初始状态，dp[0][i] or dp[i][0]都为0。如果s[i-1]==s[j-1]，那么dp[i][j]=dp[i-1][j-1]+1;
//如果s[i-1]!=s[j-1],那么dp[i][j] =max(dp[i-1][j],dp[i][j-1]);因为dp[i][j]由dp[i-1][j] or dp[i][j-1]变来。



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;++j){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        return dp[m][n];
    }
};