// 你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
// 子数组 是数组中的一个连续部分。

// 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
// 输出：6
// 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

// 思路1：贪心 遍历数组
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT32_MIN;
        int sum = 0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            if(sum>ans)
                ans = sum;
            if(sum<0) // 当sum小于0时，把sum置为0
                sum=0;
        }
        return ans;
    }
};

// 思路2：dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        //dp[i]代表以i结尾的，最大子序列的和
        dp[0] = nums[0];
        for(int i=1;i<nums.size();++i){
                dp[i] = max(nums[i],dp[i-1]+nums[i]);
        }
        return getMax(dp);
    }
    int getMax(vector<int>& dp){
        int maxnum = dp[0];
        for(int i=1;i<dp.size();++i){
            maxnum = max(maxnum,dp[i]);
        }
        return maxnum;
    }
};

