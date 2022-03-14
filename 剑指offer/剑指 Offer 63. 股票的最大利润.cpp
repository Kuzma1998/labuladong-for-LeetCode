/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-14 21:14:39
 */
// 假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
// 示例 1:
// 输入: [7,1,5,3,6,4]
// 输出: 5
// 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//      注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
// 思路：DP，最大利润等于前一天的最大和今天的卖价减去历史最小的购入价格
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        vector<int> dp(prices.size(),0);
        int minprices = prices[0];
        for(int i=1;i<dp.size();++i){
            dp[i] = max(dp[i-1],prices[i]-minprices);
            minprices = min(minprices,prices[i]);
        }
        return dp.back();
    }
};
