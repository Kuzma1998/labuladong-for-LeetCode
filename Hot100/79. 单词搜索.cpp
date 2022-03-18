/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-18 16:37:10
 */

// 一个 m x n 二维字符网格 board 和一个字符串单词 word 。
// 如果 word 存在于网格中，返回 true ；否则，返回 false 。
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，
// 其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

// 本问题是典型的矩阵搜索问题，可使用 深度优先搜索（DFS）+ 剪枝 解决。

// 深度优先搜索： 可以理解为暴力法遍历矩阵中所有字符串可能性。DFS 通过递归，
// 先朝一个方向搜到底，再回溯至上个节点，沿另一个方向搜索，以此类推。
// 剪枝： 在搜索中，遇到 这条路不可能和目标字符串匹配成功 的情况（例如：
// 此矩阵元素和目标字符不同、此元素已被访问），则应立即返回，称之为 可行性剪枝 。


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
private:
    int rows, cols;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        if(i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k]) return false;
        if(k == word.size() - 1) return true;//一直到最后一个也相等  true
        board[i][j] = '\0';//用于去重复
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) || 
                      dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i , j - 1, k + 1);
        board[i][j] = word[k];
        return res;
    }
};


class Solution {
private:
    string path;
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(),col = board[0].size();
       
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                vector<vector<bool>> used(row,vector<bool>(col,false));
                if(backtrack(board,word,i,j,used))
                    return true;
            }
        }
        return false;
    }
    bool backtrack(vector<vector<char>>& board, string& word,int i,int j, vector<vector<bool>>& used){
        if(path.size()==word.size()){
            if(path==word)
                return true;
            else
                return false;
        }
        if(i>=board.size()||j>=board[0].size()||i<0||j<0||used[i][j]){
            return false;
        }
        path+=board[i][j];
        used[i][j] = true;
        bool flag = backtrack(board,word,i+1,j,used)||backtrack(board,word,i-1,j,used)
                    ||backtrack(board,word,i,j-1,used)||backtrack(board,word,i,j+1,used);
        path.pop_back();
        return flag;
    }
}