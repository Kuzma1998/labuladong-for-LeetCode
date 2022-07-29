/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-30 21:12:57
 */
// 给定一个非空 01 二维数组表示的网格，一个岛屿由四连通（上、下、左、右四个方向）的 1 组成，你可以认为网格的四周被海水包围。
// 请你计算这个网格中共有多少个形状不同的岛屿。两个岛屿被认为是相同的，
// 当且仅当一个岛屿可以通过平移变换（不可以旋转、翻转）和另一个岛屿重合

// 思路：其实就给岛屿进行序列化，不过要有回退操作，不然会漏选

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
        DFS(grid,i,j+1,4,s);
        DFS(grid,i-1,j,2,s);
        DFS(grid,i,j-1,3,s);
        s = s+num2str(-num);
        s+= "-";
        
    }
    string num2str(int num){ //数字转字符串
        stringstream ss; //C++风格的字符串的输入输出的。可以读取写入字符串
        ss<<num;
        return ss.str();
    }
};



class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<string> s;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==1){
                    string str = "";
                    dfs(grid,i,j,111,str);
                    cout<<str<<endl;
                    s.insert(str);
                }
            }
        }
        return s.size();
    }
    void dfs(vector<vector<int>>& grid,int i,int j,int num,string& str){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0){
            return;
        }
        grid[i][j] = 0;
        // 根据遍历的顺序序列化
        str += to_string(num);
        // 进的次序
        str += '+';
        dfs(grid,i+1,j,1,str);
        dfs(grid,i-1,j,2,str);
        dfs(grid,i,j+1,3,str);
        dfs(grid,i,j-1,4,str);
        // 出的次序
        str +='-'+to_string(num);
    }
};