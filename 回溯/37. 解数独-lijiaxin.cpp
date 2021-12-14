/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-14 22:19:19
 */



class Solution {
private:
bool backtracking(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {        // 遍历行
        for (int j = 0; j < board[0].size(); j++) { // 遍历列
            if (board[i][j] != '.') continue;
            for (char k = '1'; k <= '9'; k++) {     // (i, j) 这个位置放k是否合适
                if (isValid(i, j, k, board)) {
                    board[i][j] = k;                // 放置k
                    if (backtracking(board)) 
                        return true; // 如果找到合适一组立刻返回
                    board[i][j] = '.';              // 回溯，撤销k
                }
            }
            return false;                           // 9个数都试完了，都不行，那么就返回false
        }
    }
    return true; // 遍历完没有返回false，说明找到了合适棋盘位置了
}
bool isValid(int row, int col, char val, vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) { // 判断行里是否重复
        if (board[row][i] == val) {
            return false;
        }
    }
    for (int j = 0; j < 9; j++) { // 判断列里是否重复
        if (board[j][col] == val) {
            return false;
        }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == val ) {
                return false;
            }
        }
    }
    return true;
}
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};


class Solution
{
public:
    bool backtrack(vector<vector<char>> &board, int i, int j)
    {
        if (j == 9)
            return backtrack(board, i + 1, 0);
        if (i == 9)
        {
            return true;
        }
        if (board[i][j] != '.')
            return backtrack(board, i, j + 1);

        for (char num = '1'; num <= '9'; ++num)
        {
            if (!isValid(board, i, j, num))
                continue;
            board[i][j] = num;
            if (backtrack(board, i, j + 1))
                return true;
            board[i][j] = '.';
            
        }
        return false;
    }
    bool isValid(vector<vector<char>> &board, int i, int j, char num)
    {
        // for (int row = 0; row < 9; ++row)
        // {
        //     if (board[row][j] == num)
        //         return false;
        // }
        // for (int col = 0; col < 9; ++col)
        // {
        //     if (board[i][col] == '.')
        //         return false;
        // }
        // int sr = (i / 3) * 3;
        // int sc = (j / 3) * 3;
        // for (int subrow = sr; subrow < sr + 3; ++subrow)
        // {
        //     for (int subcol = sc; subcol < sc + 3; ++subcol)
        //     {
        //         if (board[subrow][subcol] == num)
        //             return false;
        //     }
        // }
        // return true;
            for (int r = 0; r < 9; r++) {
            // 判断行是否存在重复
            if (board[i][r] == num) return false;
            // 判断列是否存在重复
            if (board[r][j] == num) return false;
            // 判断 3 x 3 方框是否存在重复
            if (board[(i/3)*3 + r/3][(j/3)*3 + r%3] == num)
                return false;
        }
            return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        backtrack(board, 0, 0);
    }
};