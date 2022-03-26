// 给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
// 判断你是否能够到达最后一个下标。

// 输入：nums = [2,3,1,1,4]
// 输出：true
// 解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。

<<<<<<< Updated upstream
// 贪心
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_range=0;
        for(int i=0;i<=max_range;++i){
            max_range = max(max_range,i+nums[i]);
            if(max_range>=nums.size()-1)
                return true;
        }
        return false;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int max_step = nums[0];
        dp[0] = nums[0];
        for(int i=0;i<nums.size();++i){
            if(i>max_step)
                return false;
            dp[i] = max(dp[i-1],i+nums[i]);
            max_step = max(max_step,dp[i]);
            if(max_step>nums.size())
                return true;
        }
        return true;
    }
};