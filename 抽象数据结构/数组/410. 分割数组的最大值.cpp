/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-12 20:27:11
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-13 13:12:03
 */
// 给定一个非负整数数组 nums 和一个整数 m ，你需要将这个数组分成 m 个非空的连续子数组。
// 设计一个算法使得这 m 个子数组各自和的最大值最小。
// 输入：nums = [7,2,5,10,8], m = 2
// 输出：18
// 解释：
// 一共有四种方法将 nums 分割为 2 个子数组。 其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
// 因为此时这两个子数组各自的和的最大值为18，在所有情况中最小


class Solution {
private:
    int sum=0;
    int MAX=0;
public:
    int splitArray(vector<int>& nums, int m) {
        getMaxAndSum(nums);
        int left=MAX,right =sum;
        while(left<=right){
            int mid =left+(right-left)/2;
            if(split(nums,mid)>m){ // 数太小了，导致分的太多，扩大范围
                left =mid+1;
            }else{
                right =mid-1; // 找到的和刚好使nums分组小于等于m，假设上例找到19，应该继续搜寻左边界
            }
        }
        if(left>sum||split(nums,left)>m)
            return -1;
        return left;
    }

    /* 辅助函数，若限制最大子数组和为 max，当max为数组和，最小为1
    计算 nums 至少可以被分割成几个子数组 */
    int split(vector<int>& nums, int target){
        int count=1;
        int sum=0;
        for(int i=0;i<nums.size();++i){
            if(sum+nums[i]>target){
                count++;
                sum=nums[i];
            }else{
                sum += nums[i];
            }
        }
        return count;
    }
        // 获取二分搜索边界
    void getMaxAndSum(vector<int>& nums){
        for(auto num:nums){
            MAX = max(num,MAX);
            sum += num;
        }
        return;
    }
};



 