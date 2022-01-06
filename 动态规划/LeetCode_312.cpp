// 有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
// 现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 
// 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。
// 求所能获得硬币的最大数量。
// 输入：nums = [3,1,5,8]
// 输出：167
// 解释：
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167


//思路 先把，1和1加到数组的两头，然后动态规划
// 定义dp数组dp[n+1][n+1]，都为0，dp[i][j]是(i，j)区间捏最大硬币数量
// 状态转移方程，dp[i][j] = dp[i][k]+dp[k,j]+nums[k]*nums[j]*nums[i],其中k是最后一次戳气球的索引.
// base case : 当j比i大1时为0；
// 遍历顺序为从下到上从左到右

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> points(n+2,1);
        for(int i=1;i<=n;i++)
            points[i] = nums[i-1];
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=0;i--){
            for(int j=i+1;j<n+2;j++){
                for(int k=i+1;k<j;k++){
                    dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]+points[i]*points[k]*points[j]);
                }
            }
        }
        return dp[0][n+1];
    }
};