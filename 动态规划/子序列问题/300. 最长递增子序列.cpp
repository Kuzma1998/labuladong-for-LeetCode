// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
// 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

//思路 ：定义dp[i]是nums[i]结尾的最长递增子序列长度;假设要求dp[5],遍历nums[1-4],如果nums[5]比其大,dp[5] = max(dp[5],1+dp[i])


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = nums.size();
        vector<int> dp(length,1);//初始状态dp[0] =1;
        for(int i=1;i<=length-1;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){//选择条件
                    dp[i] = max(dp[i],1+dp[j]);//状态转移
                }
            }
        }
        int ans = 0;
        for(int i=0;i<=dp.size()-1;i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};


// 二分查找