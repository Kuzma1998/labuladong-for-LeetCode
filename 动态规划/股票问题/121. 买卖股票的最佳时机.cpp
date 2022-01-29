// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

// 贪心算法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1)
            return 0;
        int price = prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();++i){
            if(prices[i]-price>=profit)
                profit = prices[i]-price;
            price = min(prices[i],price);
        }
        return profit;
    }
};

// dp

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        dp[0][0] = -prices[0];
        for(int i=1;i<prices.size();++i){
            //持有股票
            dp[i][0] = max(dp[i-1][0],-prices[i]);
            // 没有股票
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);
        }
        return dp[prices.size()-1][1];
    }
};