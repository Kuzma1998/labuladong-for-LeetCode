// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
// 一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
// 也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，
// 因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
// DFS
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> used(m,vector<int>(n,0));
        return DFS(m,n,k,0,0,used);
    }
    int DFS(int m,int n,int k,int row,int col,vector<vector<int>>& used){
        if(row<m&&col<n&&!used[row][col]&&(getSum(row)+getSum(col))<=k){
            used[row][col]=1;
            return 1+DFS(m,n,k,row+1,col,used)+DFS(m,n,k,row,col+1,used);
            
        }else
            return 0;
    }

    // 计算数位之和
    int getSum(int x){
        int ans = 0;
        while(x){
            ans += x%10;
            x /= 10;
        }
        return ans;
    }
};

// BFS
class Solution {
public:
    int movingCount(int m, int n, int k) {
        if(k==0)
            return 1;
        vector<vector<int>> used(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        int ans =1;
        used[0][0] =1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if((row+1)<m&&col<n&&!used[row+1][col]&&(getSum(row+1)+getSum(col)<=k)){
                ++ans;
                used[row+1][col]=1;
                q.push({row+1,col});
            }
            if((col+1)<n&&row<m&&!used[row][col+1]&&(getSum(row)+getSum(col+1)<=k)){
                ++ans;
                used[row][col+1]=1;
                q.push({row,col+1});
            }
        }
        return ans;
    }

    int getSum(int x){
        int ans = 0;
        while(x){
            ans += x%10;
            x /= 10;
        }
        return ans;
    }
};