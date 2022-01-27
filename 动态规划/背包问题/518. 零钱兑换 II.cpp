// 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
// 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
// 假设每一种面额的硬币有无限个。 
// 题目数据保证结果符合 32 位带符号整数。
// 示例 1：
// 输入：amount = 5, coins = [1, 2, 5]
// 输出：4
// 解释：有四种方式可以凑成总金额：
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1

// 示例 2：
// 输入：amount = 3, coins = [2]
// 输出：0
// 解释：只用面额 2 的硬币不能凑成总金额 3 。



// 示例 3：
// 输入：amount = 10, coins = [10] 
// 输出：1

// 未压缩空间
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n+1,0));
        //dp[i][j]表示金额为i，用前j个coin有多少次
        // base case
        for(int i=0;i<=n;i++)
            dp[0][i] = 1;
        for(int i=1;i<=amount;i++)
            for(int j=1;j<=n;j++){
                if(i-coins[j-1]<0) //防止越界
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = dp[i-coins[j-1]][j]+dp[i][j-1];// 装进去有多少方法加上不装与多少方法
            }
        return dp[amount][n];
    }
};

// 本题求的是组合，因此先遍历物品再遍历背包
// 压缩空间的动态规划
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int& coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

