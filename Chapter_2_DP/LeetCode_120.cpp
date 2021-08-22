// 给定一个三角形 triangle ，找出自顶向下的最小路径和。
// 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 
// 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
// 输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// 输出：11
// 解释：如下面简图所示：
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。


// 思路  定义dp[i][j] 表示到三角形第i+1行第j+1列的最小路径，
// 那么 dp[i][j] = triangle[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
// 存在特殊情况，当j-1小于0时， dp[i][j] = triangle[i][j] + dp[i-1][j];
// 当j不存在与上一行时，我们可以把dp[i-1][j]定义为一个很大的数即可


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,INT_MAX));
        dp[0][0] =triangle[0][0];
        for(int i=1;i<=m-1;i++){// 第二行开始
            for(int j=0;j<=i;j++){ // 第二行第0个元素到最后一个元素
                if(j-1>=0)
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                else{
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                }
            }
        }
// 寻找最小值
        int ans = INT_MAX;
        for(int i=0;i<=m-1;i++){
            ans = min(ans,dp[m-1][i]);
        }
        return ans;

    }

};
