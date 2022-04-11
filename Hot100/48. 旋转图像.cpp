// 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
// 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

// 没有原地

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n =matrix.size();
        if(n==1)
            return;
        int times = n/2;
        auto new_mat = matrix;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                new_mat[j][n-i-1] = matrix[i][j];
            }
        }
        matrix = new_mat;
    }
};