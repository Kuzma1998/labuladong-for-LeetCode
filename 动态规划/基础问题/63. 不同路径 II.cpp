// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
// 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// 输出：2
// 解释：
// 3x3 网格的正中间有一个障碍物。
// 从左上角到右下角一共有 2 条不同的路径：
// 1. 向右 -> 向右 -> 向下 -> 向下
// 2. 向下 -> 向下 -> 向右 -> 向右

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        if(obstacleGrid[0][0]==1) return 0;
        else{
            for(int i=0;i<m;++i)
                if(obstacleGrid[i][0]) break;
                else dp[i][0] =1;
            for(int j=0;j<n;++j)
                if(obstacleGrid[0][j]) break;
                else dp[0][j] =1;
            for(int i=1;i<m;++i)
                for(int j=1;j<n;++j){
                    if(obstacleGrid[i][j]) continue;
                    else dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
        }
        return dp[m-1][n-1];
        
    }
};