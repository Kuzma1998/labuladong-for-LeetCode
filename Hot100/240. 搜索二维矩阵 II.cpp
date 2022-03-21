/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-21 20:06:43
 */
// 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
// 每行的元素从左到右升序排列。
// 每列的元素从上到下升序排列。

// 二分搜索  or z型搜索
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();++i){
            if(binary_search(matrix[i],0,matrix[0].size()-1,target))
                return true;
        }
        return false;
    }
    bool binary_search(vector<int>& nums,int l,int r, int target){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[mid]>target)
                r = mid-1;
            else if(nums[mid]<target)
                l = mid+1;
        }
        return false;
    }
};