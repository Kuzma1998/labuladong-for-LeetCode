// 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
// 现有矩阵 matrix 如下：
// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
// 给定 target = 5，返回 true。
// 给定 target = 20，返回 false。

// 思路1 ：二分搜索
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        // int n = matrix[0].size();
        bool flag = false;
        if(m==0)
            return false;
        m--;
        while(m>=0){
            flag = binary_search(matrix[m],target);
            if(flag)
                break;
            m--;
        }
        return flag;
    }
    bool binary_search(vector<int>& nums,int target){
        int left = 0,right =nums.size()-1;
        while(left<=right){
            int mid = left +(right-left)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]>target){
                 right=mid-1;
            }else if(nums[mid]<target)
                left = mid+1;
        }
        return false;
    }
};

// 思路2：线性查找，从左下往右上走，大于target往上，小于target往右
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) return false;
        int col = matrix[0].size();
        if(col == 0) return false;
        int i=row-1,j=0;
        while(i>=0 && j<col){
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] < target){
                j++;
            }
            else{
                i--;
            }
        }
        return false;
    }
};