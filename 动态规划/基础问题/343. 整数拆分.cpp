// 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
// 输入: 2
// 输出: 1
// 解释: 2 = 1 + 1, 1 × 1 = 1。
// temp = max(dp[i-j]*j,j*(i-j));
// dp[i] = max(dp[i],temp);

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[2] = 1;
        for(int i=3;i<=n;++i)
            for(int j=1;j<i;++j)
                dp[i] = max(dp[i],max(j*(i-j),j*dp[i-j]));
        return dp[n];
    }
};