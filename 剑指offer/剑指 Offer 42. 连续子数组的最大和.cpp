// 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

// 要求时间复杂度为O(n)。

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);//dp[i]代表截至下表i的连续子数组的和
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i=1;i<nums.size();++i){
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
            ans = max(ans,dp[i]);
        }
        return ans;

    }
};