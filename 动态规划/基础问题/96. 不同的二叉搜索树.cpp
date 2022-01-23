// 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 
// 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

思路 动态规划,dp[i]代表i有多少个二叉搜索树,
dp[2] = 左1*右1
dp[3] = 左2*右0+左1*右1+右2*左1;


class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] =1;
        dp[1] =1;
        for(int i=2;i<=n;++i){
            for(int j=0;j<i;++j){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};