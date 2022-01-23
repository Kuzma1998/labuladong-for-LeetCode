// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

//思路 动态规划，dp[i]表示nums[i]结尾的最大子列和，那么base状态dp[0] = nums[0];
//dp[i] = max(nums[i],dp[i-1]+nums[i]);

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        int* ans = new int[n];//new一个数组
        ans[0] = nums[0];
        for(int i=1;i<=n-1;++i){
            ans[i] = max(nums[i],ans[i-1]+nums[i]);
        }
        int res = INT_MIN;
        for(int i=0;i<=n-1;i++){
            res = max(res,ans[i]);
        }
        return res;
    }
};



//带压缩感知的动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        int dp_0 = nums[0];
        int dp_1;
        int ans = dp_0;
        for(int i=1;i<=n-1;i++){
            dp_1 = max(nums[i],dp_0+nums[i]);
            dp_0 = dp_1;
            ans = max(ans,dp_0);
        }
        return ans;
    }
};