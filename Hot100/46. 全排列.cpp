// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
// 示例 1：
// 输入：nums = [1,2,3]
// 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


// 排列问题  需要used数组！！！
class Solution {
vector<vector<int>> ans;
vector<int> path;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int sz = nums.size();
        vector<bool> used(sz,false);
        backtrack(nums,used);
        return ans;
    }

    void backtrack(vector<int>& nums,vector<bool>& used){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(used[i])
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums,used);
            path.pop_back();
            used[i] = false;
        }
    }
};