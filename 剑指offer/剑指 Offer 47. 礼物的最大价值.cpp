// 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
// 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，
// 请计算你最多能拿到多少价值的礼物？
// 示例 1:
// 输入: 
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// 输出: 12
// 解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物

// 思路：DP 
class Solution {
private:
    unordered_map<string,int> map;
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        if(0==m||0==n)
            return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = grid[0][0];
        for(int i=1;i<n;++i){
            dp[0][i] = dp[0][i-1]+grid[0][i];
        }
        for(int i=1;i<m;++i){
            dp[i][0] = dp[i-1][0]+grid[i][0];
        }
        for(int i=1;i<m;++i)
            for(int j=1;j<n;++j){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        return dp[m-1][n-1];
    }
   
};

// 记忆优化的DFS

class Solution {
private:
    unordered_map<string,int> map;
public:
    int maxValue(vector<vector<int>>& grid) {
        if(0==grid.size())
            return 0;
        return DFS(grid,0,0);
    }
    int DFS(vector<vector<int>>& grid,int i,int j){
        if(i>=grid.size()||j>=grid[0].size())
            return 0;
        string str = to_string(i)+'-'+to_string(j);
        if(map[str])
            return map[str];
        int ans = grid[i][j]+max(DFS(grid,i+1,j),DFS(grid,i,j+1));
        map[str] = ans;
        return ans;
        
    }
};