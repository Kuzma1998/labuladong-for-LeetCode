// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
// 如果数组中不存在目标值 target，返回 [-1, -1]。

// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]


// 思路：二分搜索，一次返回左边界，一次返回右边界
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = left_bound(nums,target);
        int right = right_bound(nums,target);
        return {left,right};
    }
    int left_bound(vector<int>& nums, int target){
        int left = 0,right = nums.size()-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]>target)
                right = mid-1;
            else if(nums[mid]<target)
                left = mid+1;
            else if(nums[mid]==target) // 相等，缩小right，继续寻找左边界。
                right = mid-1;
        }
        // 检查越界
        if(left>=nums.size()||nums[left]!=target)
            return -1;
        return left;

    }
    int right_bound(vector<int>& nums, int target){
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]>target)
                right = mid -1;
            else if(nums[mid]<target)
                left = mid+1;
            else if(nums[mid]==target) // 相等，扩大left，继续寻找右边界。
                left = mid+1;
        }
        // 检查越界
        if(right<=-1||nums[right]!=target)
            return -1;
        return right;
    }
};