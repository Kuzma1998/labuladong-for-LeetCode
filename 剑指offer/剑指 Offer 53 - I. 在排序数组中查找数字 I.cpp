//二分搜索

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return 0;
        int l = lower_binary_search(nums,0,nums.size()-1,target);
        int r = higher_binary_search(nums,0,nums.size()-1,target);
        if(-1==l&&-1==r)
            return 0;
        return r-l+1;
    }
    int lower_binary_search(vector<int>& nums,int l,int r, int target){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]<target){ // 小于l=mid+1
                l = mid+1;
            }
            else if(nums[mid]>target){ // 大于r=mid-1
                r = mid-1;
            }
            else if(nums[mid]==target)// 找到了不返回 继续缩小边界
                r = mid-1;
        }
        if (l >= nums.size() || nums[l] != target)
            return -1;
        return l;
    }
    int higher_binary_search(vector<int>& nums,int l,int r, int target){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]<target){
                l = mid+1;
            }
            else if(nums[mid]>target){
                r = mid-1;
            }
            else if(nums[mid]==target){ //找到了一样不返回 去右边再找
                l = mid+1;
            }
        }
        if(r>=nums.size()||nums[r]!=target)
            return -1;
        return r;
    }
};