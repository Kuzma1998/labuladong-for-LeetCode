// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
// 如果数组中不存在目标值 target，返回 [-1, -1]。
// 进阶：
// 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？


// 二分搜索

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1,-1};
        }
        int left = binary_search_lower(nums,0,nums.size()-1,target);
        int right = binary_search_higher(nums,0,nums.size()-1,target);
        if(left==-1||right==-1)
            return {-1,-1};
        return {left,right};
    }

    int binary_search_lower(vector<int>& nums,int l,int r,int target){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                    r = mid-1;
            }
            else if(nums[mid]>target){
                r = mid-1;
            }
            else if(nums[mid]<target){
                l =mid+1;
            }
        }
        if(l<0||l>nums.size()-1||nums[l]!=target){
            return -1;
        }
        return l;
    }

    int binary_search_higher(vector<int>& nums,int l,int r,int target){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                    l = mid+1;
            }
            else if(nums[mid]>target){
                r = mid-1;
            }
            else if(nums[mid]<target){
                l =mid+1;
            }
        }
        if(r<0||r>nums.size()-1||nums[r]!=target){
            return -1;
        }
        return r;
    }
};