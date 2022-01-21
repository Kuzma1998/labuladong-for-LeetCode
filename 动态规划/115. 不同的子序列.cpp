// // 给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
// // 字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。
// // （例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
// 输入：s = "babgbag", t = "bag"
// 输出：5
// 解释：
// 如下图所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag



class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.size(),n=t.size();
        vector<vector<uint64_t>> dp(m+1,vector<uint64_t>(n+1,0));
        for(int i=0;i<=m;++i)
            dp[i][0] =1;
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(s[i-1]==t[j-1])
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};