/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-30 21:10:03
 */
// 给你两个 m x n 的二进制矩阵 grid1 和 grid2 ，它们只包含 0 （表示水域）和 1 （表示陆地）。
// 一个 岛屿 是由 四个方向 （水平或者竖直）上相邻的 1 组成的区域。任何矩阵以外的区域都视为水域。
// 如果 grid2 的一个岛屿，被 grid1 的一个岛屿 完全 包含，也就是说 grid2 中该岛屿的每一个格子都被 
// grid1 中同一个岛屿完全包含，那么我们称 grid2 中的这个岛屿为 子岛屿 。
// 请你返回 grid2 中 子岛屿 的 数目 。

// 思路：先从g1里面是海水但g2里面是陆地开始遍历，把这些能到的1都置为0
// 再遍历g2 里面的岛屿

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(),n=grid1[0].size();
        for(int i=0;i<m;++i){
            int j=0;
            for(;j<n;++j){
                if(grid1[i][j]==0&&grid2[i][j]==1)
                    DFS(grid2,i,j);
            }
        }
        int ans = 0;
        for(int i=0;i<m;++i){
            int j=0;
            for(;j<n;++j){
                if(grid2[i][j]==1){
                    DFS(grid2,i,j);
                    ++ans;
                }
            }
        }
        return ans;
    }
    void DFS(vector<vector<int>>& grid2,int i,int j){
        if(i<0||j<0||i==grid2.size()||j==grid2[0].size())
            return;
        if(grid2[i][j]==0)
            return;
        grid2[i][j] =0;
        DFS(grid2,i-1,j);
        DFS(grid2,i+1,j);
        DFS(grid2,i,j+1);
        DFS(grid2,i,j-1);
    }
};