/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-25 20:43:47
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-25 21:03:06
 */
// 给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
// 输入: [1,2,3,4]
// 输出: [24,12,8,6]

// 思路：建立两个列表，一个L,R,L[i]表示nums[i]左边所有的数的积，R[i]代表nums[i]右边的数的乘积
// 那么ans[i] = R[i]*L[i];


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size();
        vector<int> L(n,0);
        vector<int> R(n,0);
        L[0] =1;
        for(int i=1;i<n;++i){
            L[i] =  nums[i-1]*L[i-1];
        }
        R[n-1]=1;
        for(int i=n-2;i>=0;--i){
            R[i] = R[i+1]*nums[i+1];
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;++i){
            ans[i] = L[i]*R[i];
        }
        return ans;
    }
};