// 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
// 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。
// （例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
// 输入：s = "abc", t = "ahbgdc"
// 输出：true

// 动态规划

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=t.size(),n=s.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        for(int i=0;i<=m;++i)
            dp[i][0] = true;
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j){
                if(t[i-1]==s[j-1])
                    dp[i][j] = dp[i-1][j-1]||dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        return dp[m][n]
    }
};


// 双指针

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n;
    }
};