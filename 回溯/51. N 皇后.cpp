/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-09 21:19:40
 */
// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。(不能在同一列，同一行，或者对角线)
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。



class Solution {
private:
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        string sub(n,'.');
        vector<string> board(n,sub);
        backtrack(board,0);
        return res;
    }
// 路径：board 中小于 row 的那些行都已经成功放置了皇后
// 选择列表：第 row 行的所有列都是放置皇后的选择
// 结束条件：row 超过 board 的最后一行
    void backtrack(vector<string>& board,int row){
        if(board.size()==row){
            res.push_back(board);
            return;
        }
        int n = board.size();
        for(int col=0;col<n;++col){
            if(!isValid(board,row,col)){ // 如果位置不合法，跳过
                continue;
            }
            board[row][col] = 'Q';
            backtrack(board,row+1);
            board[row][col] = '.';
        }
    }
    bool isValid(vector<string>& board,int row,int col){
        int n = board.size();
        // 检查同一列
        for(int i=0;i<n;++i){
            if((board[i][col])=='Q')
                return false;
        }
        // 检查左上方
        for(int i=row-1,j=col-1;i>=0&&j>=0;--i,--j){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        // 检查右上方
        for(int i=row-1,j=col+1;i>=0&&j<n;--i,++j){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }

};