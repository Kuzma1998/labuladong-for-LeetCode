// 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

// 思路：维护四个指针，然后模拟遍历即可

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int left = 0,right=n-1,up =0,dowm = m-1;
        while(true){
            for(int i=left;i<=right;++i){
                ans.push_back(matrix[up][i]);
            }
            up++;
            if(up>dowm)
                break;
            for(int i=up;i<=dowm;++i){
                ans.push_back(matrix[i][right]);
            }
            --right;
            if(left>right)
                break;
            for(int i=right;i>=left;--i){
                ans.push_back(matrix[dowm][i]);
            }
            --dowm;
            if(up>dowm)
                break;
            for(int i=dowm;i>=up;--i){
                ans.push_back(matrix[i][left]);
            }
            ++left;
            if(left>right)
                break;
        }
        return ans;
    }
};