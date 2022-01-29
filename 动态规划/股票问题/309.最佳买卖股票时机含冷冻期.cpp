// 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
// 输入: prices = [1,2,3,0,2]
// 输出: 3 
// 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        if(prices.size()<=1)
            return 0;
        // dp[i][0]代表第i天持股，dp[i][1]代表未持股
        dp[0][0] = -prices[0];
        dp[1][0] = max(-prices[0],-prices[1]);
        dp[1][1] = max(dp[0][1],dp[0][0]+prices[1]);
        for(int i=2;i<prices.size();++i){
            // 第i天持股的最大利润可以是昨天天持股与前天不持股然后今天买入的最大值
            dp[i][0] =max(dp[i-1][0],dp[i-2][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);
        }
        return dp[prices.size()-1][1];
    }
};