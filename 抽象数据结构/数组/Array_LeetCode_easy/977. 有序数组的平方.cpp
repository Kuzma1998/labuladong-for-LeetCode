/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-13 16:42:06
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-13 16:44:11
 */
// 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
// 示例 1：
// 输入：nums = [-4,-1,0,3,10]
// 输出：[0,1,9,16,100]
// 解释：平方后，数组变为 [16,1,0,9,100]
// 排序后，数组变为 [0,1,9,16,100]

// 思路：双指针，元素组平方之后最大的元素一定出现在数组两侧


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        
        int left=0,right=nums.size()-1;// 用于遍历原数组
       
        for(int j=right;j>=0;--j){// 修改result
            int A = nums[left]*nums[left],B=nums[right]*nums[right];
            if(A>B){
                res[j] = A;
                ++left;
            }else{
                res[j] = B;
                --right;
            }
        }
        return res;
    }
};