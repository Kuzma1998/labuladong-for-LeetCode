// 给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。
// 输入: "sea", "eat"
// 输出: 2
// 解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"


思路1：先求最长公共子串，再做减法
class Solution {
public:
    int minDistance(string word1, string word2) {
      // 先求最长公共子串，再求steps
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // dp[i][j]代表字符串1以i结尾和字符串2以j结尾的最长公共子串的长度
        // dp[0][j] = 0,dp[i][0]都初始化为0
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;++j){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
        }
        return m+n-2*dp[m][n];
    }

};


思路2：直接DP
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // dp[i][j]表示字符串以第i个结尾和字符串以第j个结尾相等需要删除的次数
        for(int i=0;i<=m;++i){
            dp[i][0]  = i;// 
        }
        for(int j=0;j<=n;++j){
            dp[0][j]  = j;
        }
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j){
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
                }
            }
        return dp[m][n];
    }
};