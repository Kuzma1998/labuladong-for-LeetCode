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

// 递归法，直接看代码

class Solution {
private:
    unordered_map<string,int> memo; // 备忘录
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0)
            return 0;
        return dg(nums,target,0);
    }
    int dg(vector<int>& nums, int target,int i){
        int n = nums.size();
        if(i==nums.size()){ // 若i==数组长度，说明数组最近一个元素已经访问
            if(target==0)  //
                return 1; // 如果目标变为0，则返回一种方法
            return 0;
        }
        string key = to_string(i)+ " "+ to_string(target);
        if(memo.count(key))
            return memo[key];
        int res = dg(nums,target-nums[i],i+1) + dg(nums,target+nums[i],i+1); // 加或者减去当前元素的方法的和
        memo[key] = res;
        return res;
    }
};



 // 转换为dp问题
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        if(n==0)
            return 0;
        for(int i=0;i<=n-1;i++){
            sum += nums[i];
        }
        if((target+sum)%2!=0 || sum<target || target+sum<0 )
            return 0;
        target = (target+sum)/2;
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){ // j要从0开始因为可能nums前面都是0
                if(j-nums[i-1]<0)
                    dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
            }
        }       
        return dp[n][target];
    } 
};