// 编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。
// 例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 右 -> 右 -> 下 -> 下，则骑士的初始健康点数至少为 7。
// -2 (K)	-3	3
// -5	-10	1
// 10	30	-5 (P)


// 思路 反向动态规划，设dp[i][j] 是骑士到i,j所需的血量 从dp[m-1][n-1]开始，最终返回dp[0][0]



class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        int dp[m][n];
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1&&j==n-1)
                    dp[i][j] = (-dungeon[i][j]>0)?-dungeon[i][j]+1:1; //初始化，若最后一个元素为负数，初始化为其相反数+1，为整数初始化为1
                else if(i==m-1&&j!=n-1)
                    dp[i][j] = (dp[i][j+1]-dungeon[i][j]>0)?  // 最后一行更新公式
                    dp[i][j+1]-dungeon[i][j]:1;
                else if(i!=m-1&&j==n-1)
                     dp[i][j] = (dp[i+1][j]-dungeon[i][j]>0)? // 最后一列的更新公式
                     dp[i+1][j]-dungeon[i][j]:1;
                else 
                    dp[i][j] =  (min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]>0)?  // 非特殊情况的状态转移方程
                                min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]: 1;
            }
            
        }
        return dp[0][0];
    }
};