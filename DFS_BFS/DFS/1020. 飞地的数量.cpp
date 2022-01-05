/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-28 20:13:58
 */
// 给出一个二维数组 A，每个单元格为 0（代表海）或 1（代表陆地）。
// 移动是指在陆地上从一个地方走到另一个地方（朝四个方向之一）或离开网格的边界。
// 返回网格中无法在任意次数的移动中离开网格边界的陆地单元格的数量。

// 输入：[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// 输出：3
// 解释： 
// 有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。


// 思路：
// 先将边界能到的1全部置为0，数一下数组的元素有多少 1

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size()-1;
        int n=grid[0].size()-1;
        for(int i=0;i<=m;++i){
            DFS(grid,i,0);
            DFS(grid,i,n);
        }
        for(int j=0;j<=n;++j){
            DFS(grid,0,j);
            DFS(grid,m,j);
        }

        for(auto vec:grid){
            for(auto num:vec){
                if(num==1)
                    ++ans;
            }
        }
        return ans;
    }

    void DFS(vector<vector<int>>& grid,int i,int j){
        if(i<0||j<0||i==grid.size()||j==grid[0].size()){
            return;
        }
        if(grid[i][j]==0)
            return;

        if(grid[i][j]==1)
            grid[i][j]=0;

        DFS(grid,i+1,j);
        DFS(grid,i-1,j);
        DFS(grid,i,j-1);
        DFS(grid,i,j+1);
    }
};