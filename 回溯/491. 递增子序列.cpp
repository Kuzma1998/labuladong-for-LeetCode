/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-24 21:02:24
 */


// 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
// 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
// 输入：nums = [4,6,7,7]
// 输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]


// 不能排序去重，利用set去重，同一层不能使用重复元素

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums,0);
        return ans;
    }
    void backtrack(vector<int>& nums,int index){
        if(path.size()>=2)
            ans.push_back(path);
        if(index==nums.size())
            return ;
        set<int> s;
        for(int i=index;i<nums.size();++i){
            if(!path.empty()&&nums[i]<path.back()||s.find(nums[i])!=s.end()){
                continue;
            }
            s.insert(nums[i]);
            path.push_back(nums[i]);
            backtrack(nums,i+1);
            path.pop_back();
        }
    }
};
