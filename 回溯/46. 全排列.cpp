/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-10 09:44:56
 */

// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
// 示例 1：
// 输入：nums = [1,2,3]
// 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> road;
        backtrack(road,nums);
        return res;
    }

    // 回溯
    void backtrack(vector<int>& road,vector<int>& nums){
        if(nums.size()==0){
            res.push_back(road);
            return;
        }
        for(int i=0;i<nums.size();++i){
            int pp = nums[i];
            road.push_back(pp);
            swap(nums[i],nums[nums.size()-1]);
            nums.pop_back();
            backtrack(road,nums);
            road.pop_back();
            nums.push_back(pp);
            swap(nums[i],nums[nums.size()-1]);// 交换为原顺序
        }
    }
};


// 回溯就是一个n叉树的遍历问题
class Solution {
private:
    vector<vector<int>> res;  //存结果
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> road;
        vector<bool> used(nums.size(),false); // 用来判断nums里面有哪些是用过的，即判断选择列表里面哪些是有用的
        backtrack(road,nums,used);
        return res;
    }
    // 回溯
    void backtrack(vector<int>& road,vector<int>& nums,vector<bool>& used){ 
        if(road.size()==nums.size()){
            res.push_back(road);
            return;
        }
        // 选择列表，也就是树的这一层的宽度
        for(int i=0;i<nums.size();++i){
            if(!used[i]){ // nums[i]没有使用过就递归回溯
                used[i]=true;
                road.push_back(nums[i]);
                backtrack(road,nums,used);
                // 撤销选择
                road.pop_back();
                used[i] = false;
            }
        }
    }

};