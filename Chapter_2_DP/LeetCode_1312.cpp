// 给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。
// 请你返回让 s 成为回文串的 最少操作次数 。
// 「回文串」是正读和反读都相同的字符串。
// 示例
// 输入：s = "zzazz"
// 输出：0
// 解释：字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。

// 思路 动态规划 定义二维dp[][]数组,dp[i][j]表示s[i..j]变成回文串的最小次数
// base case dp[i][j]当i>j时,dp[i][j]=0;dp[i][i]=0;因为一个单词就是回文串
// 状态转移方程 当s[i]==s[j],dp[i][j] = dp[i-1][j-1],
// 否则dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1);等于i+1到j是回文串的次数+1或则i到j-1是回文串的次数+1

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        // int dp[n][n];
        // //base case
        // for(int i=0;i<=n-1;i++){
        //     dp[i][i]=0;
        // }
        vector<vector<int>> dp(n,vector<int>(n,0));
        //状态转移
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else{
                    // dp[i][j]等于其两个子序列变成回文串次数+1
                    dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1;
                }
            }
        }
        return dp[0][n-1];
    }
};
