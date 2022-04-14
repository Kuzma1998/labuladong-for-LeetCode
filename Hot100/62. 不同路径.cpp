// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
// 问总共有多少条不同的路径？

// dfs
class Solution {
map<pair<int,int>,int> mp;
public:
    int uniquePaths(int m, int n) {
        int i=1,j=1;
        int ans = dfs(i,j,m,n);
        return ans;
    }

    int dfs(int i,int j,int m,int n){
        if(i>m||j>n)
            return 0;
        if(i==m&&j==n)
            return 1;
        if(mp.find({i,j})!=mp.end()){
            pair<int,int> p = {i,j};
            return mp[p];
        }
        int count = dfs(i+1,j,m,n)+dfs(i,j+1,m,n);
        pair<int,int> p = {i,j};
        mp[p] = count;
        return count;
    }
};

// dp