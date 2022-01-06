/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-28 17:11:32
 */
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
// 此外，你可以假设该网格的四条边均被水包围。
// 输入：grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// 输出：1

// 整体思路，当遇到有1时，递增计数器，然后以此点为左边，遍历相连的所有的1，遍历到1就置为0.

// BFS

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<char,vector<int>>> q;
        set<pair<int ,int>> s;
        int ans =0;
        for(int i=0;i<grid.size();++i){
            int j=0;
            for(;j<grid[0].size();++j){
                if(grid[i][j]=='1'){
                    q.push({grid[i][j],vector<int>{i,j}});
                    s.insert({i,j});
                    ++ans;
                    while(!q.empty()){
                        int sz = q.size();
                        char cur = q.front().first;
                        int row =q.front().second[0],col = q.front().second[1];
                        q.pop();
                        grid[row][col] = '0';
                        while(sz--){
                            if(row-1>=0&&!s.count({row-1,col})&&grid[row-1][col]=='1'){
                                q.push({grid[row-1][col],vector<int>{row-1,col}});
                                s.insert({row-1,col});
                            }

                            if(row+1<grid.size()&&!s.count({row+1,col})&&grid[row+1][col]=='1'){
                                q.push({grid[row+1][col],vector<int>{row+1,col}});
                                s.insert({row+1,col});
                            }

                            if(col-1>=0&&!s.count({row,col-1})&&grid[row][col-1]=='1'){
                                q.push({grid[row][col-1],vector<int>{row,col-1}});
                                s.insert({row,col-1});
                            }

                            if(col+1<grid[0].size()&&!s.count({row,col+1})&&grid[row][col+1]=='1'){
                                q.push({grid[row][col+1],vector<int>{row,col+1}});
                                s.insert({row,col+1});
                            }

                        }
                    }
                }
            }
        }
        return ans;
    }
};

// 官方BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    grid[r][c] = '0';
                    queue<pair<int, int>> neighbors; //我仅需要存坐标就行了
                    neighbors.push({r, c});
                    while (!neighbors.empty()) {
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first, col = rc.second;
                        if (row - 1 >= 0 && grid[row-1][col] == '1') {
                            neighbors.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if (row + 1 < nr && grid[row+1][col] == '1') {
                            neighbors.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col-1] == '1') {
                            neighbors.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if (col + 1 < nc && grid[row][col+1] == '1') {
                            neighbors.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }

        return num_islands;
    }
};



// DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();++i){
            int j=0;
            for(;j<grid[0].size();++j){
                if(grid[i][j]=='1'){
                    ans++;
                    DFS(grid,i,j);
                }
            }
        }
        return ans;
    }
    
    void DFS(vector<vector<char>>& grid,int i,int j){
        if(i<0||j<0||i==grid.size()||j==grid[0].size()){
            return;
        }
        if(grid[i][j]=='0')
            return;

        if(grid[i][j]=='1')
            grid[i][j]='0';

        DFS(grid,i+1,j);
        DFS(grid,i-1,j);
        DFS(grid,i,j-1);
        DFS(grid,i,j+1);

    }
};
