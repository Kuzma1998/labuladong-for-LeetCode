// 给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。
// 下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。
// 在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。
// 具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。
// 输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
// 输出：13
// 解释：下面是两条和最小的下降路径，用加粗+斜体标注：
// [[2,1,3],      [[2,1,3],
//  [6,5,4],       [6,5,4],
//  [7,8,9]]       [7,8,9]]

思路：简单的DP
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.size();
        vector<int> dp(matrix[0]);
        vector<int> res = dp;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;++j){
                if(j==0)
                    res[j] =  min(dp[j],dp[j+1])+matrix[i][j];
                else if(j==n-1)
                    res[j] = min(dp[j],dp[j-1])+matrix[i][j];
                else 
                    res[j] = min(min(dp[j-1],dp[j]),dp[j+1])+matrix[i][j];
            }
            dp = res;
        }
        return findmin(res);

    }
    int findmin(vector<int>& nums){
        int num = nums[0];
        for(auto i:nums){
            if(i<num)
                num = i;
        }
        return num;
    }
};