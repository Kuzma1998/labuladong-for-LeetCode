/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-09-08 09:19:56
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2022-09-08 09:56:54
 */

// 并查集

class Solution {
    struct UnionFind{
        int size;
        vector<int> parents;
        UnionFind(int _size) : size(_size) {
            parents.resize(size);
            for(int i = 0; i < size; ++i){
                parents[i] = i;
            }
        }
        void unions(int p, int q){
            int rootP = find(p);
            int rootQ = find(q);
            if(rootP == rootQ){
                return;
            }
            parents[rootP] = rootQ;
            --size;
            return;
        }
        int find(int x){
            // 层层递归往上找
            if(x != parents[x]){
                parents[x] = find(parents[x]);
            }
            return parents[x];
        }
        bool connect(int p, int q){
            return find(p) == find(q);
        }
    };
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int dummy = m*n;
        UnionFind UF(dummy+1);
        vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

        // 先把 边界的O联通起来

        for(int i = 0; i < n; ++i){
            if(board[0][i] == 'O'){
                UF.unions(i,dummy);
            }
            if(board[m-1][i] == 'O'){
                UF.unions((m-1)*n+i,dummy);
            }
        }

        for(int i = 0 ; i < m; ++i){
            if(board[i][0] == 'O'){
                UF.unions(i*n,dummy);
            }
            if(board[i][n-1] == 'O'){
                UF.unions(i*n+n-1,dummy);
            }
        }

        // 合并内部O周围的O，可能会与边界的O连通
        for(int i = 1; i < m - 1; ++i){
            for(int j = 1; j < n - 1; ++j){
                if(board[i][j] == 'O'){
                    for(int k = 0; k < 4; ++k){
                        int x = i + directions[k][0];
                        int y = j + directions[k][1];
                        if(board[x][y] == 'O'){
                            UF.unions(i*n+j,x*n+y);
                        }
                    }
                }
            }
        }

        // 不与边界联通的O置为X
        for(int i = 1; i < m - 1; ++i){
            for(int j = 1; j < n - 1; ++j){
                if(!UF.connect(dummy,i*n+j)){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};