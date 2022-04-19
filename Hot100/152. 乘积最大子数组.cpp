// 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
// 测试用例的答案是一个 32-位 整数。
// 子数组 是数组的连续子序列。
// 示例 1:
// 输入: nums = [2,3,-2,4]
// 输出: 6
// 解释: 子数组 [2,3] 有最大乘积 6。
// 示例 2:
// 输入: nums = [-2,0,-1]
// 输出: 0
// 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

// DP:保存两个数组
// 由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值imin
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        if(sz==1)
            return nums[0];
        vector<int> dp1(sz,0);
        vector<int> dp2(sz,0);
        dp1[0] = dp2[0] = nums[0];
        for(int i=1;i<sz;++i){
          dp1[i] = max(dp1[i-1]*nums[i],max(nums[i],dp2[i-1]*nums[i]));
          dp2[i] = min(dp1[i-1]*nums[i],min(nums[i],dp2[i-1]*nums[i]));
        }
        int ans = INT_MIN;
        for(auto i:dp1){
            ans = max(i,ans);
        }
        return ans;
    }
};