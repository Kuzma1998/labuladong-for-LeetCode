

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        int i=1;
        dp[1] = 1;
        dp[0] = 0;
        for(int i=1;i<=n;++i){
            //  遍历 j到直到j平方大于i，求出i的最小次数
            for(int j=1;j*j<=i;++j){
                dp[i] = min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};