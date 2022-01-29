// 给定一个数组 prices ，其中 prices[i] 表示股票第 i 天的价格。
// 在每一天，你可能会决定购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以购买它，然后在 同一天 出售。
// 返回 你能获得的 最大 利润 。
// 输入: prices = [7,1,5,3,6,4]
// 输出: 7
// 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
//      随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。

// 思路：贪心或者dp，主要是可以买卖多次
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        dp[0][0] = -prices[0];
        for(int i=1;i<prices.size();++i){
            //持有股票
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i]);
            // 没有股票
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);
        }
        return dp[prices.size()-1][1];
    }
};