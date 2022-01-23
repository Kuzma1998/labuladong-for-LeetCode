// 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
// 输入：
// A: [1,2,3,2,1]
// B: [3,2,1,4,7]
// 输出：3
// 解释：
// 长度最长的公共子数组是 [3, 2, 1] 。

// 思路：DP，dp[i][j]代表nums1以i-1结尾，nums2以j-1结尾i的最长公共子数组长度

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int ans =0;
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j){
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;//状态转移方程
                else
                    dp[i][j] = 0;//不相等的话就直接是0，因为子数组要求是连续的，子序列不是
                ans = max(ans,dp[i][j]);
            }
        return ans;
    }
};