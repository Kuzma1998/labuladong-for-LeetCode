// 给你一个整数数组 nums 和一个整数 target 。
// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
// 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
// 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
// 输入：nums = [1,1,1,1,1], target = 3
// 输出：5
// 解释：一共有 5 种方法让最终目标和为 3 。
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3


class Solution {
private:
    int ans = 0;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums,target,0);
        return ans;
    } 
    void backtrack(vector<int>& nums,int target,int index){
        if(index==nums.size()){
            if(target==0)
                ans++;
            return;
        }
        // 减法
        target += nums[index];
        backtrack(nums,target,index+1);
        target -=nums[index];
        // 加法
        target -= nums[index];
        backtrack(nums,target,index+1);
        target +=nums[index];
    }
};