/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-27 20:07:54
 */

// 在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示.
// 一次移动定义为选择 0 与一个相邻的数字（上下左右）进行交换.
// 最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。
// 给出一个谜板的初始状态，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。

// 输入：board = [[4,1,2],[5,0,3]]
// 输出：5
// 解释：
// 最少完成谜板的最少移动次数是 5 ，
// 一种移动路径:
// 尚未移动: [[4,1,2],[5,0,3]]
// 移动 1 次: [[4,1,2],[0,5,3]]
// 移动 2 次: [[0,1,2],[4,5,3]]
// 移动 3 次: [[1,0,2],[4,5,3]]
// 移动 4 次: [[1,2,0],[4,5,3]]
// 移动 5 次: [[1,2,3],[4,5,0]]

// 思路：BFS


class Solution {
private:
    vector<vector<int>> target{{1,2,3},{4,5,0}};
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<vector<vector<int>>> q;
        set<vector<vector<int>>> s; // f防止走回头路
        q.push(board);
        int times =0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                vector<vector<int>> cur = q.front();
                q.pop();
                s.insert(cur);
                if(isRight(cur))
                    return times;// 满足要求，return 次数
                int i= Find(cur).first,j=Find(cur).second;
                vector<vector<int>> temp;
                temp = Down(cur,i,j);
                if(!s.count(temp))
                    q.push(temp);

                temp = Up(cur,i,j);
                if(!s.count(temp))
                    q.push(temp);

                temp = Left(cur,i,j);
                if(!s.count(temp))
                    q.push(temp);

                temp = Right(cur,i,j);
                if(!s.count(temp))
                    q.push(temp);
            }
            ++times;
        }
        return -1;

    }

    vector<vector<int>> Down(vector<vector<int>> board,int i,int j){
        if(i==1)
            return board;
        else{
            swap(board[i][j],board[i+1][j]);
            return board;
        }

    }
    vector<vector<int>> Up(vector<vector<int>> board,int i,int j){
        if(i==0)
            return board;
        else{
            swap(board[i][j],board[i-1][j]);
            return board;
        }
    }
    vector<vector<int>> Left(vector<vector<int>> board,int i,int j){
        if(j==0)
            return board;
        else{
            swap(board[i][j],board[i][j-1]);
            return board;
        }
    }
    vector<vector<int>> Right(vector<vector<int>> board,int i,int j){
        if(j==2)
            return board;
        else{
            swap(board[i][j],board[i][j+1]);
            return board;
        }
    }

    bool isRight(vector<vector<int>> board){
        int i,j;
        for(i=0;i<2;++i){
            j=0;
            for(;j<3;++j){
                if(board[i][j]!=target[i][j])
                    return false;
            }
        }
        return true;
    }

    pair<int,int> Find(vector<vector<int>> board){
        int i,j;
        for(i=0;i<2;++i){
            int j=0;
            for(;j<3;++j){
                if(board[i][j]==0)
                    return pair<int,int>{i,j};
            }
        }
        return pair<int,int>{i,j};
    }
};