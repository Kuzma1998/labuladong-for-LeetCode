// 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
// 说明：每次只能向下或者向右移动一步。



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            if(i==0)
                dp[i][0]=grid[i][0];
            else
                dp[i][0] = grid[i][0]+dp[i-1][0];
        }
        for(int i=1;i<n;++i){
            if(i==0)
                dp[0][i]=grid[0][i];
            else
                dp[0][i] = grid[0][i]+dp[0][i-1];
        }
        for(int i=1;i<m;++i){   
            for(int j=1;j<n;++j){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};