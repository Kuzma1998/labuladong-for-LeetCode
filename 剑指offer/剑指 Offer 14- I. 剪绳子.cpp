// 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
// 每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，
// 我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1,0);
        dp[2] = 1;
        for(int i=3;i<=n;++i){
            for(int j=1;j<=i/2;++j){
                dp[i] = max(dp[i],max((i-j)*j,dp[i-j]*j));//状态转移方程，j只需要循环到i/2即可
            }
        }
        return dp[n];
    }
};