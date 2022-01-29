// 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
// 输入：prices = [3,3,5,0,0,3,1,4]
// 输出：6
// 解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
//      随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。

// DP,定义五个状态

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len,vector<int>(5,0));
        dp[0][0] = 0;//不变操作
        dp[0][1] = -prices[0];//第一次买入
        dp[0][2] = 0;//第一次卖
        dp[0][3] = -prices[0];//第二次买
        dp[0][4] = 0;//第二次买
        for(int i=1;i<len;++i){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);
            dp[i][2] = max(dp[i-1][2],dp[i-1][1]+prices[i]);
            dp[i][3] = max(dp[i-1][3],dp[i-1][2]-prices[i]);
            dp[i][4] = max(dp[i-1][4],dp[i-1][3]+prices[i]);
        }
        return dp[len-1][4];
    }
};

// 递归  超时

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return dp(false,0,prices,0);
    }
    int dp(bool has,int count,vector<int>& prices,int index){
        if(count>=2||index>=prices.size())
            return 0;
        // 若此时持有股票
        if(has){
            return max(dp(true,count,prices,index+1),
            dp(false,count+1,prices,index+1)+prices[index]);
        }else{ //若没有股票
            return max(dp(false,count,prices,index+1),
            dp(true,count,prices,index+1)-prices[index]);
        }
    }
};