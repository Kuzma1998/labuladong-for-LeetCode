/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-24 17:17:25
 */
// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
// 输入：nums = [1,2,2]
// 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        backtrack(nums,0,used);
        return ans;
    }
    void backtrack(vector<int>& nums,int index,vector<bool>& used){
        ans.push_back(path);
        if(index==nums.size())
            return;
        for(int i=index;i<nums.size();++i){
            if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false)  // 树的层剪枝，同一层不能重复选取，而树的深度可以重复
                continue;
            if(used[i])
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums,i+1,used);
            used[i] = false;
            path.pop_back();
        }
    }
};