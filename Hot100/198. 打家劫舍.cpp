

class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if(sz==1)
            return nums[0];
        if(sz==2)
            return max(nums[0],nums[1]);
        vector<int> dp(sz,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<sz;++i){
            // 第i天的最大等于前两天的加今天的或昨天的  取最大
          dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp.back();
        
    }
};