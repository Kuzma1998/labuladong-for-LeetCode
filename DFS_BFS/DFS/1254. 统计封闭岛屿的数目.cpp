/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-28 19:12:35
 */

// 有一个二维矩阵 grid ，每个位置要么是陆地（记号为 0 ）要么是水域（记号为 1 ）。
// 我们从一块陆地出发，每次可以往上下左右 4 个方向相邻区域走，能走到的所有陆地区域，我们将其称为一座「岛屿」。
// 如果一座岛屿 完全 由水域包围，即陆地边缘上下左右所有相邻区域都是水域，那么我们将其称为 「封闭岛屿」。
// 请返回封闭岛屿的数目。
// 输入：grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
// 输出：2
// 解释：
// 灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。

// 思路：先把旁边能到的岛屿都淹没，然后和200题解法一样

class Solution {
public:// 先把四周的岛屿给淹了
    int closedIsland(vector<vector<int>>& grid) {
        int ans =0;
        for(int i =0;i<grid.size();++i){
            DFS(grid,i,0);
            DFS(grid,i,grid[0].size()-1);
        }
        for(int j=0;j<grid[0].size();++j){
            DFS(grid,0,j);
            DFS(grid,grid.size()-1,j);
        }
        for(int i=0;i<grid.size();i++){
            int j=0;
            for(;j<grid[0].size();++j){
                if(grid[i][j]==0){
                    ++ans;
                    DFS(grid,i,j);
                    }
                }
            }
        return ans;
    }
    void DFS(vector<vector<int>>& grid,int i,int j){
        if(i<0||j<0||i==grid.size()||j==grid[0].size())
            return;
        if(grid[i][j]==1)
            return;
        grid[i][j] =1;
        DFS(grid,i+1,j);
        DFS(grid,i-1,j);
        DFS(grid,i,j+1);
        DFS(grid,i,j-1);
    }
};
