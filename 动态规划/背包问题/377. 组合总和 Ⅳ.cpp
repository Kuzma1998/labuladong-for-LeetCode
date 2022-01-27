// 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
// 题目数据保证答案符合 32 位整数范围。
// 输入：nums = [1,2,3], target = 4
// 输出：7
// 解释：
// 所有可能的组合为：
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// 请注意，顺序不同的序列被视作不同的组合。

// 回溯
class Solution {
private:
    unordered_map<int,int> mp;
public:
    int combinationSum4(vector<int>& nums, int target) {
        return backtrack(nums,target);
    }
    int backtrack(vector<int>& nums, int target){
        if(target==0){
            return 1;
        }
        if(target<0)
            return 0;
        if(mp.count(target))
            return mp[target];
        int res = 0;
        for(auto num:nums){
            res += backtrack(nums,target-num);
        }
        mp[target] = res;
        return res;
    }
};


// dp，本题求的是排列，因此要先遍历背包再遍历物品
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,0);
        dp[0] =1;
        for(int i=0;i<=target;++i){
            for(int j=0;j<nums.size();++j){
                if(i-nums[j]>=0&&dp[i]<INT_MAX-dp[i-nums[j]])
                    dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }

};