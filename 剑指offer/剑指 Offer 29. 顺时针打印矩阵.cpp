// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
// 示例 1：
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]
// 示例 2：
// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// 输出：[1,2,3,4,8,12,11,10,9,5,6,7]

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size()==0)
            return {};
        int left = 0,right=matrix[0].size()-1,up =0,dowm = matrix.size()-1;
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