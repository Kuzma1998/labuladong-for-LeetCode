// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
// 示例 1：
// 输入：[1,2,3,1]
// 输出：4
// 解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//      偷窃到的最高金额 = 1 + 3 = 4 。
// 示例 2：
// 输入：[2,7,9,3,1]
// 输出：12
// 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//      偷窃到的最高金额 = 2 + 9 + 1 = 12 。
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 递归

class Solution {
private:
    int money;
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n,-1);//初始化为一个不可能的数字
        return dp(nums,0,memo);
    }
    int dp(vector<int>& nums,int start,vector<int>& memo){
        if(start>=nums.size())
            return 0;
        if(memo[start]!=-1)
            return memo[start];
        money = max(dp(nums,start+2,memo)+nums[start],dp(nums,start+1,memo));
        memo[start] = money;
        return money;
    }
};

// dp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2,-1);
        dp[n+1] = 0;
        dp[n] = 0;
        for(int i=n-1;i>=0;i--){
            dp[i] = max(dp[i+2]+nums[i],dp[i+1]);
        }
        return dp[0];
    }

};

// 状态压缩dp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+2,-1);
        int dp_2 = 0;
        int dp_1 = 0;
        int dp = -1;
        for(int i=n-1;i>=0;i--){
            dp = max(dp_2+nums[i],dp_1);
            dp_2 = dp_1;
            dp_1 = dp;
        }
        return dp;
    }

};



// int main(){
//     Solution solution;
//     vector<int> nums(2,0);
//     nums[0] = 1;
//     nums[1] = 2;
//     cout<<solution.rob(nums)<<endl;
// }