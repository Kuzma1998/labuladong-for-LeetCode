/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-28 16:51:00
 */

#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<set>
#include<queue>
#include<sstream>
using namespace std;


// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         queue<pair<char,vector<int>>> q;
//         set<pair<int ,int>> s;
//         int ans =0;
//         for(int i=0;i<grid.size();++i){
//             int j=0;
//             for(;j<grid[0].size();++j){
//                 if(grid[i][j]=='1'){
//                     q.push({grid[i][j],vector<int>{i,j}});
//                     s.insert({i,j});
//                     ++ans;
//                     while(!q.empty()){
//                         int sz = q.size();
//                         char cur = q.front().first;
//                         int row =q.front().second[0],col = q.front().second[1];
//                         q.pop();
//                         grid[row][col] = '0';
//                         while(sz--){
//                             if(row-1>=0&&!s.count({row-1,col})&&grid[row-1][col]=='1'){
//                                 q.push({grid[row-1][col],vector<int>{row-1,col}});
//                                 s.insert({row-1,col});
//                             }

//                             if(row+1<grid.size()&&!s.count({row+1,col})&&grid[row+1][col]=='1'){
//                                 q.push({grid[row+1][col],vector<int>{row+1,col}});
//                                 s.insert({row+1,col});
//                             }

//                             if(col-1>=0&&!s.count({row,col-1})&&grid[row][col-1]=='1'){
//                                 q.push({grid[row][col-1],vector<int>{row,col-1}});
//                                 s.insert({row,col-1});
//                             }

//                             if(col+1<grid[0].size()&&!s.count({row,col+1})&&grid[row][col+1]=='1'){
//                                 q.push({grid[row][col+1],vector<int>{row,col+1}});
//                                 s.insert({row,col+1});
//                             }

//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:// 先把四周的岛屿给淹了
//     int closedIsland(vector<vector<int>>& grid) {
//         int ans =0;
//         for(int i =0;i<grid.size();++i){
//             DFS(grid,i,0);
//             DFS(grid,i,grid[0].size()-1);
//         }
//         for(int j=0;j<grid[0].size();++j){
//             DFS(grid,0,j);
//             DFS(grid,grid.size()-1,j);
//         }
//         for(int i=0;i<grid.size();i++){
//             int j=0;
//             for(;j<grid[0].size();++j){
//                 if(grid[i][j]==0){
//                     ++ans;
//                     DFS(grid,i,j);
//                     }
//                 }
//             }
//         return ans;
//     }
//     void DFS(vector<vector<int>>& grid,int i,int j){
//         if(i<0||j<0||i==grid.size()||j==grid[0].size())
//             return;
//         if(grid[i][j]==1)
//             return;
//         grid[i][j] =1;
//         DFS(grid,i+1,j);
//         DFS(grid,i-1,j);
//         DFS(grid,i,j+1);
//         DFS(grid,i,j-1);
//     }
// };


// int main(){
//     Solution solver; 
//     vector<vector<char>> grid = {{'1','1','0','0','0'},
//     {'1','1','0','0','0'},
//     {'0','0','1','0','0'},
//     {'0','0','0','1','1'}};
//     cout<<solver.numIslands(grid)<<endl;

// }

// class Solution {
// public:
//     int numEnclaves(vector<vector<int>>& grid) {
//         int ans=0;
//         int m=grid.size()-1;
//         int n=grid[0].size()-1;
//         for(int i=0;i<=m;++i){
//             DFS(grid,i,0);
//             DFS(grid,i,n);
//         }
//         for(int j=0;j<=n;++j){
//             DFS(grid,0,j);
//             DFS(grid,m,j);
//         }

//         for(auto vec:grid){
//             for(auto num:vec){
//                 if(num==1)
//                     ++ans;
//             }
//         }
//         return ans;
//     }

//     void DFS(vector<vector<int>>& grid,int i,int j){
//         if(i<0||j<0||i==grid.size()||j==grid[0].size()){
//             return;
//         }
//         if(grid[i][j]==0)
//             return;

//         if(grid[i][j]==1)
//             grid[i][j]=0;

//         DFS(grid,i+1,j);
//         DFS(grid,i-1,j);
//         DFS(grid,i,j-1);
//         DFS(grid,i,j+1);
//     }
// };


// int main(){
//     Solution solver; 
//     vector<vector<int>> grid = {{0,0,0,0},{0,0,1,0},{0,1,1,0},{0,0,0,0}};
//     cout<<solver.numEnclaves(grid)<<endl;

// }

// class Solution {
// private:
//     int ans = 0;
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         // int ans =0 ;
//         int m = grid.size(),n=grid[0].size();
//         for(int i=0;i<m;++i){
//             int j=0;
//             for(;j<n;++j){
//                 if(grid[i][j]==1){
//                     int sub_ans = DFS(grid,i,j,0);
//                     ans = max(sub_ans,ans);
//                 }
//             }
//         }
//         return ans;
//     }

//     int DFS(vector<vector<int>>& grid,int i,int j,int sub_ans){
//         if(i<0||j<0||i==grid.size()||j==grid[0].size()){
//             return 0;
//         }
//         if(grid[i][j]==0)
//             return 0;

//         if(grid[i][j]==1){
//             grid[i][j]=0;
//             ++sub_ans;
//         }

//         sub_ans+=DFS(grid,i+1,j,0);
//         sub_ans+=DFS(grid,i-1,j,0);
//         sub_ans+=DFS(grid,i,j-1,0);
//         sub_ans+=DFS(grid,i,j+1,0);

//         return sub_ans;
//     }
// };


// int main(){
//     Solution solver; 
//     vector<vector<int>> grid ={{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
//     cout<<solver.maxAreaOfIsland(grid)<<endl;

// }


// class Solution {
// private:
//     vector<set<pair<int,int>>> v1;
//     vector<set<pair<int,int>>> v2;
//     int ans = 0;
// public:
//     int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
//         int m =grid1.size(),n = grid2[0].size();
//         for(int i=0;i<m;++i){
//             int j=0;
//             for(;j<n;++j){
//                 if(grid1[i][j]==1){
//                     set<pair<int,int>> s1;
//                     DFS1(grid1,i,j,s1);
//                     if(!s1.empty()){
//                         v1.push_back(s1);
//                     }
//                 }
//             }
//         }
//         for(int i=0;i<m;++i){
//             int j=0;
//             for(;j<n;++j){
//                 if(grid2[i][j]==1){
//                     set<pair<int,int>> s2;
//                     DFS2(grid2,i,j,s2);
//                     if(!s2.empty())
//                         v2.push_back(s2);
//                 }
//             }
//         }

//         for(auto vec1:v1){
//             for(auto vec2:v2){
//                 if(check(vec1,vec2)){
//                     ++ans;
//                 }

//             }
//         }
//         return ans;
//     }
//     void DFS1(vector<vector<int>>& grid1, int i ,int j,set<pair<int,int>>& s1){
//         if(i<0||j<0||i==grid1.size()||j==grid1[0].size())
//             return;
//         if(grid1[i][j]==0)
//             return;
//         grid1[i][j] =0;
//         s1.insert({i,j});
//         DFS1(grid1,i-1,j,s1);
//         DFS1(grid1,i+1,j,s1);
//         DFS1(grid1,i,j+1,s1);
//         DFS1(grid1,i,j-1,s1);
//     }
//     void DFS2(vector<vector<int>>& grid2, int i ,int j, set<pair<int,int>>& s2){
//         if(i<0||j<0||i==grid2.size()||j==grid2[0].size())
//             return;
//         if(grid2[i][j]==0)
//             return;
//         grid2[i][j] =0;
//         s2.insert({i,j});
//         DFS2(grid2,i-1,j,s2);
//         DFS2(grid2,i+1,j,s2);
//         DFS2(grid2,i,j+1,s2);
//         DFS2(grid2,i,j-1,s2);
//     }
//     bool check(set<pair<int,int>> s1,set<pair<int,int>> s2) {
//         if(s1.size()<s2.size()) return false;
//         for(auto i:s2){
//             if(!s1.count(i))
//                 return false;
//         }
//         return true;
//     }
// };


// int main(){
//     // vector<vector<int>> grid1 = {{1,1,1,1,0,0},{1,1,0,1,0,0},{1,0,0,1,1,1},{1,1,1,0,0,1},{1,1,1,1,1,0},{1,0,1,0,1,0},{0,1,1,1,0,1},{1,0,0,0,1,1},{1,0,0,0,1,0},{1,1,1,1,1,0}};
//     // vector<vector<int>> grid2 = {{1,1,1,1,0,1},{0,0,1,0,1,0},{1,1,1,1,1,1},{0,1,1,1,1,1},{1,1,1,0,1,0},{0,1,1,1,1,1},{1,1,0,1,1,1},{1,0,0,1,0,1},{1,1,1,1,1,1},{1,0,0,1,0,0}};
//     vector<vector<int>> grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
//     vector<vector<int>> grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
//     Solution solver; 
//     cout<<solver.countSubIslands(grid1,grid2);
// }


class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        set<string> se;
        for(int i=0;i<m;++i){
            int j =0;
            for(;j<n;++j){
                if(grid[i][j]==1){
                string s = "";
                DFS(grid, i,j,111,s);
                se.insert(s);
                }
            }
        }
        return se.size();
    }
    void DFS(vector<vector<int>>& grid,int i,int j,int num,string& s){
        if(i<0||j<0||i==grid.size()||j==grid[0].size()){
            return;
        }
        if(grid[i][j]==0)
            return;
        s = s+num2str(num);
        s += "-";
        grid[i][j] = 0;
        DFS(grid,i+1,j,1,s);    
        DFS(grid,i-1,j,2,s);
        DFS(grid,i,j-1,3,s);
        DFS(grid,i,j+1,4,s);
        s = s+num2str(-num);
        s+= "-";
        
    }
    string num2str(int num){
        stringstream ss;
        ss<<num;
        return ss.str();
    }
};

int main(){
    vector<vector<int>> grid = {{1,1,0},{0,1,1},{0,0,0},{1,1,1},{0,1,0}};
    Solution solver;
    cout<<solver.numDistinctIslands(grid);
}