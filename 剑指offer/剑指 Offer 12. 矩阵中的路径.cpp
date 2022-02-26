// 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格
// 。同一个单元格内的字母不允许被重复使用。

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


// 自己写的超时
// class Solution {
// private:
//     string path;
// public:
//     bool exist(vector<vector<char>>& board, string word) {
     
//         for(int i=0;i<board.size();++i){
//             for(int j=0;j<board[0].size();++j){
//                 if(backtrack(board,i,j,word))
//                     return true;
//             }
//         }
//         return false;
//     }                   
//     bool backtrack(vector<vector<char>>& board,int i,int j,string& word){
//         if(i==board.size()||j==board[0].size()||i<0||j<0){
//           return path==word;
//         }
//         if(board[i][j]=='\0')
//             return false;
//         path += board[i][j];
//         char temp = board[i][j]; 
//         board[i][j] = '\0';
//         bool flag = backtrack(board,i+1,j,word)
//         || backtrack(board,i-1,j,word)
//         || backtrack(board,i,j+1,word)
//         || backtrack(board,i,j-1,word);
//         board[i][j] = temp;
//         path.pop_back();
//         return flag;                                     
//     }
// };