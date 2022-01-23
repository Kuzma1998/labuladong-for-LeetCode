// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
// 注意：给定 n 是一个正整数。
// 示例 1：
// 输入： 2
// 输出： 2
// 解释： 有两种方法可以爬到楼顶。
// 1.  1 阶 + 1 阶
// 2.  2 阶
// 思路 动态规划 dp[i]代表到第i层有多少方法，那么dp[i] = dp[i-1] +dp[i-2]  状态转移方程 等于爬到第i-1层再爬一下的方法+爬到i-2层爬2层的方法


class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        // base case
        dp[1] = 1;
        if(n==1)
            return dp[1];
        dp[2] = 2;
        //状态转移方程 状态是楼梯层数，选择是1or2
        for(int i=3;i<=n;i++){
            dp[i]= dp[i-1]+dp[i-2];
        }
        return dp[n];

    }
};


class Solution {
public:
    int climbStairs(int n) {
        int dp1 = 1;
        int dp2 = 2;
        int ways = 0;
        if(n==1)
            return dp1;
        if(n==2)
            return dp2;
        for(int i=3;i<=n;++i){
            ways = dp1+dp2;
            dp1 = dp2;
            dp2 = ways;
            
        }
        return ways;
    }
};