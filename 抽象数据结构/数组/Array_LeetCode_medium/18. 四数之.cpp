/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-07 16:53:07
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-07 18:18:46
 */
// 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] ：
// 0 <= a, b, c, d < n
// a、b、c 和 d 互不相同
// nums[a] + nums[b] + nums[c] + nums[d] == target
// 你可以按 任意顺序返回答案。


// 思路：通解，递归

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return nSum(nums,4,0,target);
    }


    // 递归求解n数之和
    vector<vector<int>> nSum(vector<int>& nums,int n, int start, int target){
        int length = nums.size();
        base case
        if(n<2||length<n)
            return {};
        vector<vector<int>> res;
        // n=2;
        if(n==2){
            int l = start,r=length-1;
            while(l<r){
                int left = nums[l],right = nums[r];
                int sum = nums[l]+nums[r];
                if(sum<target){
                    while(l<r&&nums[l]==left) ++l;
                }else if(sum>target){
                    while(l<r&&nums[l]==right) --r;
                }else{
                    res.push_back({nums[l]+nums[r]});
                    while(l<r&&nums[l]==left) ++l;
                    while(l<r&&nums[r]==right) --r;
                }
            }
        }else{ // 递归
            for(int i=start;i<length-1;++i){
                vector<vector<int>> subRes = nSum(nums,n-1,i+1,target-nums[i]);
                for(auto sub:subRes){
                    sub.push_back(nums[i]);
                    res.push_back(sub);
                }
                while(i<length-1&&nums[i]==nums[i+1]) ++i;
            }
        }
        return res;
    }
};