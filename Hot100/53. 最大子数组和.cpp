class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        if(sz==1)
            return nums[0];
        vector<int> dp(sz,0);
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i=1;i<sz;++i){
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
            ans = max(dp[i],ans);
        }
        return ans;
    }
};