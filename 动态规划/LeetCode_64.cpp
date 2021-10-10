// 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
// 说明：每次只能向下或者向右移动一步。

// 示例 1
// 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
// 输出：7
// 解释：因为路径 1→3→1→1→1 的总和最小。

// 示例 2：
// 输入：grid = [[1,2,3],[4,5,6]]
// 输出：12


// 思路 动态规划 定义dp[i][j] 表示到第i行第j列最少次数，要求的是dp[m-1][n-1]
// 状态转移方程如下：
// if(!i&&j)
//     dp[i][j] = grid[i][j] + dp[i][j-1];
// else if(i&&!j)
//     dp[i][j] = grid[i][j] + dp[i-1][j];
// else if(i==0&&j==0)
//     dp[i][j] = grid[i][j];
// else
//     dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        for(int i=0;i<=m-1;i++)
            for(int j=0;j<=n-1;j++){
                if(!i&&j)
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                else if(i&&!j)
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                else if(i==0&&j==0)
                    dp[i][j] = grid[i][j];
                else
                    dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        return dp[m-1][n-1];
    }
    
};