// 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
// 示例 1：
// 输入：nums = [1,2,3]
// 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        vector<int> path = {};
        dfs(nums,used,path,0);
        return ans;
    }

    void dfs(vector<int>& nums,vector<bool>& used,vector<int>& path,int index){
        ans.push_back(path);
        if(index>=nums.size()){
            return;
        }
        for(int i=index;i<nums.size();++i){
            if(used[i])
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            // 注意i+1
            dfs(nums,used,path,i+1);
            used[i] = false;
            path.pop_back();
        }

    }
};