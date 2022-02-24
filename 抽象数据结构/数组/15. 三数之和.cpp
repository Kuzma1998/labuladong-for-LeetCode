/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-06 17:03:03
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-06 17:10:33
 */

// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
// 注意：答案中不可以包含重复的三元组。

// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]


// 思路：转化成两数之和 https://labuladong.gitee.io/algo/1/11/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 数组排序
        sort(nums.begin(),nums.end());
        // 存结果
        vector<vector<int>> res;
        //
        for(int i=0;i<nums.size();++i){
            // 两数之和的目标为-nums[i]，找到和为-nums[i]的二元组
            vector<vector<int>> answers = twoSumTarget(nums,i+1,-nums[i]);
            
            for(auto ans:answers){
                ans.push_back(nums[i]);// 加入nums[i]变成三元组
                res.push_back(ans);// 添加结果
            }
            // 去重复
            while(i<nums.size()-1&&nums[i]==nums[i+1]){
                ++i;
            }
        }
        return res;
    }
    
    // 从数组start开始返回和为target的所有二元组
    vector<vector<int>> twoSumTarget(vector<int>& nums,int start, int target) {
        int l = start,r = nums.size()-1;
        vector<vector<int>> ans;
        while(l<r){
            int left = nums[l],right = nums[r];
            int sum = nums[l]+nums[r];
            
            if(sum>target){
                while(l<r&&nums[r]==right)// 去重复
                    --r;
            }
            else if(sum<target){
                while(l<r&&nums[l]==left)// 去重复
                    ++l;
            }
            else{
                ans.push_back({nums[l],nums[r]});// 去重复
                while(l<r&&nums[l]==left)
                    ++l;
                while(l<r&&nums[r]==right)
                    --r;
            }
        }
        return ans;
    }
};



// 直接求解
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int size = nums.size();
        if (size < 3)   return {};          // 特判
        vector<vector<int> >res;            // 保存结果（所有不重复的三元组）
        std::sort(nums.begin(), nums.end());// 排序（默认递增）
        for (int i = 0; i < size; i++)      // 固定第一个数，转化为求两数之和
        {
            if (nums[i] > 0)    return res; // 第一个数大于 0，后面都是递增正数，不可能相加为零了
            // 去重：如果此数已经选取过，跳过
            if (i > 0 && nums[i] == nums[i-1])  continue;
            // 双指针在nums[i]后面的区间中寻找和为0-nums[i]的另外两个数
            int left = i + 1;
            int right = size - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > -nums[i])
                    right--;    // 两数之和太大，右指针左移
                else if (nums[left] + nums[right] < -nums[i])
                    left++;     // 两数之和太小，左指针右移
                else
                {
                    // 找到一个和为零的三元组，添加到结果中，左右指针内缩，继续寻找
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    // 去重：第二个数和第三个数也不重复选取
                    // 例如：[-4,1,1,1,2,3,3,3], i=0, left=1, right=5
                    while (left < right && nums[left] == nums[left-1])  left++;
                    while (left < right && nums[right] == nums[right+1])    right--;
                }
            }
        }
        return res;
    }
};