// 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
// 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
// 你可以认为每种硬币的数量是无限的。
// 示例 1：
// 输入：coins = [1, 2, 5], amount = 11
// 输出：3 
// 解释：11 = 5 + 5 + 1

//dfs 
class Solution {
unordered_map<int,int> mp;
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end(),[](int a,int b){return a>b;});
        int sz = INT_MAX;
        return dfs(coins,amount);
    }
    int dfs(vector<int>& coins, int amount){
        int res = INT_MAX;
        if(amount==0){
            return 0;
        }
        if(amount<0)
            return -1;
        if(mp.find(amount)!=mp.end())
            return mp[amount];
        for(int i=0;i<coins.size();++i){
            if(amount-coins[i]<0)
                continue;
            if(i!=0&&coins[i]==coins[i-1])
                continue;
            int subproblem = dfs(coins,amount-coins[i]);
            if(subproblem == -1)
                continue;
            res = min(res,1+subproblem);
        }
        mp[amount] = (res==INT_MAX)?-1:res;
        return mp[amount];
    }
};

// DP
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount+1,amount+1);
        ans[0] = 0;//初始状态
        for(int i=0;i<=ans.size()-1;i++){//自底向上更新每个状态
            for(int coin:coins){ //选择条件
                if(i-coin<0)
                    continue;
                ans[i] = min(ans[i],ans[i-coin]+1);//状态转移方程
            }
        }
        return (ans[amount]==amount+1)?-1:ans[amount];
    }
};