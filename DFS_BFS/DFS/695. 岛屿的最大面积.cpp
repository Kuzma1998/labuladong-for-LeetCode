/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-28 21:06:45
 */
// 给你一个大小为 m x n 的二进制矩阵 grid 。
// 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 
// 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
// 岛屿的面积是岛上值为 1 的单元格的数目。
// 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 


class Solution {
private:
    int ans = 0;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // int ans =0 ;
        int m = grid.size(),n=grid[0].size();
        for(int i=0;i<m;++i){
            int j=0;
            for(;j<n;++j){
                if(grid[i][j]==1){
                    int sub_ans = DFS(grid,i,j,0);
                    ans = max(sub_ans,ans);
                }
            }
        }
        return ans;
    }

    // 让DFS返回值即可
    int DFS(vector<vector<int>>& grid,int i,int j,int sub_ans){
        if(i<0||j<0||i==grid.size()||j==grid[0].size()){
            return 0;
        }
        if(grid[i][j]==0)
            return 0;

        if(grid[i][j]==1){
            grid[i][j]=0;
            ++sub_ans;
        }

        sub_ans+=DFS(grid,i+1,j,0);
        sub_ans+=DFS(grid,i-1,j,0);
        sub_ans+=DFS(grid,i,j-1,0);
        sub_ans+=DFS(grid,i,j+1,0);

        return sub_ans;
    }
};
