// 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
// 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
// 请你计算并返回达到楼梯顶部的最低花费。
// 输入：cost = [10,15,20]
// 输出：15
// 解释：你将从下标为 1 的台阶开始。
// - 支付 15 ，向上爬两个台阶，到达楼梯顶部。即越过数组 ，总花费为 15 。

// 思路：动态规划
// 我到台阶0或者1cost为0，那么我要到的位置3，越过数组，我可以从1开始，可以到达3，花费为dp[1]+cost[1]，也可以从2开始dp[2]+cost[2]
// 所以状态转移方程为dp[i] = min(cost[i-1]+dp[i-1],cost[i-2]+dp-[i-2])
// dp[i]代表到达某一层需要的cost
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
       vector<int> dp(cost.size()+1,0);
        for(int i=2;i<=cost.size();++i){
            dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[cost.size()];
    }
};