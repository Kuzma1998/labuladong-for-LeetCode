// 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
// 示例 1：
// 输入：nums = [1,5,11,5]
// 输出：true
// 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
// 示例 2：
// 输入：nums = [1,2,3,5]
// 输出：false
// 解释：数组不能分割成两个元素和相等的子集。

// 转换为背包问题，背包容量为1/2 sum;物品个数为n个，dp[i][j]表示前i个物体，背包容量为j，若装满为true，未满为false;
// base dp[..][0] 等于true，背包重量为0说明已经装满。dp[0][..]没有物品了为false;
// 状态转移 dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =0;
        int n = nums.size();
        for(int i=0;i<=n-1;i++)
            sum += nums[i];
        if(sum%2!=0)    
            return false; // 和为奇数直接返回false
        sum = sum/2;
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));// 定义dp
        for(int i=0;i<=n;i++){
            dp[i][0] = true; // base case
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=sum;j++){
                if(j-nums[i-1]<0) // 背包容量不够了，不能装
                    dp[i][j] = dp[i-1][j]; 
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]]; // 装入i或者不装，看看是否存在一种情况可以装满
            }
        return dp[n][sum];
    }
};