// 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
// 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
// 你可以认为每种硬币的数量是无限的。
// 输入：coins = [1, 2, 5], amount = 11
// 输出：3 
// 解释：11 = 5 + 5 + 1

//思路，带记忆的递归或者动态规划

//递归
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount+1,0);//备忘录
        return dp(amount,coins,ans);
    }
    int dp(int n,vector<int>& coins,vector<int>& ans){
        if (n==0) // 初始状态
            return 0;
        if(n<0) // 初始状态
            return -1;
        if(ans[n]!=0) // 初始状态
            return ans[n];
        int res = INT_MAX;
        for(int coin :coins){//选择条件
            int subproblem = dp(n-coin,coins,ans);
            if(subproblem==-1)
                continue;
            res = min(res,1+subproblem);//状态转移
        }
        ans[n] = (res==INT_MAX)?-1:res;//更新ans
        return ans[n];
    }
};


//状态转移
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