// 给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
// 输入: prices = [7,1,5,3,6,4]
// 输出: 7
// 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
//      随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。

// 思路1：贪心 我们只会在加个低的时候买入高价卖出，因此转换数组，用前一个元素减去后一个元素得到新的数组，把新的数组的正数加起来即可

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> ans;
        for(int i=1;i<prices.size();++i){
            ans.push_back(prices[i]-prices[i-1]);
        }
        int profit = 0;
        for(auto i:ans){
            if(i>0)
                profit+=i;
        }
        return profit;
    }
};


// dp dp[i][0]代表第i天持有股票的我们现在有多少钱，dp[i][1]代表第i天不持有股票我们有多少钱

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        dp[0][0] = -prices[0];
        for(int i=1;i<prices.size();++i){
            dp[i][0] = max(dp[i-1][1]-prices[i],dp[i-1][0]); // 状态转移方程
            dp[i][1] =  max(dp[i-1][1],dp[i-1][0] +prices[i]);// 状态转移方程
        }
        return max(dp[prices.size()-1][0],dp[prices.size()-1][1]);
    }
};