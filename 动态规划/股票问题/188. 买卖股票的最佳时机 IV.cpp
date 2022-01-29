// 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

// 带备忘录的递归
class Solution {
private:
    unordered_map<string,int> mp;
public:
    int maxProfit(int k, vector<int>& prices) {
        dp(prices,0,0,0,k);
        return dp(prices,0,0,0,k);
    }
    int dp(vector<int>& prices,int index,int count,int has,int k){
        if((count==k&&has==0)||index>=prices.size())
            return 0;
        string str= to_string(index)+'-'+to_string(has)+'-'+to_string(count);
        cout<<str<<endl;
        if(mp.count(str))
            return mp[str];
        if(has){
            mp[str] = max(dp(prices,index+1,count,1,k),prices[index]+dp(prices,index+1,count,0,k));
            return mp[str];
        }else{
            mp[str] = max(dp(prices,index+1,count,0,k),-prices[index]+dp(prices,index+1,count+1,1,k));
            return mp[str];
        }
    }

};


// DP
// 类比奇数是买，偶数是卖
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        vector<vector<int>> dp(prices.size(),vector<int>(2*k+1,0));
        for(int i=1;i<2*k+1;i+=2){
                dp[0][i] = -prices[0];
        }
        for(int i=1;i<prices.size();++i){
            for(int j=0;j<2*k-1;j+=2){
                dp[i][j+1] = max(dp[i-1][j+1],dp[i-1][j]-prices[i]);
                dp[i][j+2] = max(dp[i-1][j+2],dp[i-1][j+1]+prices[i]);
            }
        }
        return dp[prices.size()-1][2*k];
    }
};