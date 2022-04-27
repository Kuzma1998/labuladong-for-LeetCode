/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-23 16:41:05
 */
// 给你一个含 n 个整数的数组 nums ，
// 其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
// 示例 1：
// 输入：nums = [4,3,2,7,8,2,3,1]
// 输出：[5,6]
// 示例 2：
// 输入：nums = [1,1]
// 输出：[2]

// 原地修改数组
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();++i){
            while(nums[i]!=i+1){  //不相等就一直交换
                if(nums[i]==nums[nums[i]-1])
                    break; //若两个交换的相等  退出  若要找到相同的 这一步就可以break了
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=i+1)
                ans.push_back(i+1);
        }
        return ans;
    }
};

// 原地哈希 出现在里面的数字就加上数组的长度
// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         int n = nums.size();
//         for (auto& num : nums) {
//             int x = (num - 1) % n;
//             nums[x] += n;
//         }
//         vector<int> ret;
//         for (int i = 0; i < n; i++) {
//             if (nums[i] <= n) {
//                 ret.push_back(i + 1);
//             }
//         }
//         return ret;
//     }
// };