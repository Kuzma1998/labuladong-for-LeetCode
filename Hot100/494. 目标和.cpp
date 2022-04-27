// 给你一个整数数组 nums 和一个整数 target 。
// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
// 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
// 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

// 示例 1：
// 输入：nums = [1,1,1,1,1], target = 3
// 输出：5
// 解释：一共有 5 种方法让最终目标和为 3 。
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

// dp 转化为背包问题


// dfs

class Solution {
unordered_map<string,int> mp;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums,target,0);
    }
    int dfs(vector<int>& nums, int target,int index){
        if(nums.size()==index){
            if(target==0)
                return 1;
            return 0;
        }
        string str = to_string(index)+'-'+to_string(target);
        if(mp.find(str)!=mp.end())
            return mp[str];
        mp[str] = dfs(nums,target-nums[index],index+1)+dfs(nums,target+nums[index],index+1);
        return mp[str];
    }
};