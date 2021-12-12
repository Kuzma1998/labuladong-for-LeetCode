/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-12 16:39:25
 */
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
        vector<int> path;
        trackback(path,nums,0);
        return ans;
    }

    void trackback(vector<int>& path,vector<int>& nums,int index){
        ans.push_back(path);
        if(path.size()==nums.size()){
            return;
        }
        for(int i=index;i<nums.size();++i){
            path.push_back(nums[i]);
            trackback(path,nums,i+1);
            path.pop_back();
        }
    }
};