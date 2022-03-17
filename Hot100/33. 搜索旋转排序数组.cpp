/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-17 14:56:43
 */


class Solution {
    // 1. 首先明白，旋转数组后，从中间划分，一定有一边是有序的,一边可能有序可能无序
    // 2. 由于一定有一边是有序的，所以根据有序的两个边界值来判断目标值在有序一边还是无序一边
    // 3. 这题找目标值，遇到目标值即返回
    // 4. 注意：由于有序的一边的边界值可能等于目标值，所以判断目标值是否在有序的那边时应该加个等号
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        if(!sz)
            return -1;
        if(sz==1){
            return nums[0]==target?0:-1;
        }
        int l=0,r=sz-1;
        while(l<=r){
            int mid= l+(r-l)/2;
            if(nums[mid]==target)
                return mid;
                // l可能=mid
            if(nums[l]<=nums[mid]){ //l到mid有序
                if(nums[l]<=target&&nums[mid]>target)
                    r = mid -1;  //目标值在左边
                else
                    l = mid + 1;
            }else{ // Mid到r有序
                if(target<=nums[r]&&target>nums[mid]){  //注意等号
                    l = mid +1;
                }else{
                    r = mid -1;
                }
            }
        }
        return -1;
    }
    
};