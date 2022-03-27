// 给你一个整数数组 nums ，你需要找出一个 连续子数组 ，
// 如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
// 请你找出符合题意的 最短 子数组，并输出它的长度。
// 示例 1：
// 输入：nums = [2,6,4,8,10,9,15]
// 输出：5
// 解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
// 示例 2：
// 输入：nums = [1,2,3,4]
// 输出：0
// 示例 3：
// 输入：nums = [1]
// 输出：0


// 快排+比较
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int sz = nums.size();
        // if(is_sorted(nums.begin(),nums.end()))
        //     return 0;
        vector<int> sorted_num(nums.begin(),nums.end());
        quick_sort(sorted_num,0,sz-1);
        int l = 0;
        while(l<sz&&nums[l]==sorted_num[l])
            ++l;
        if(l==sz)
            return 0;
        int r = sz-1;
        while(r>=0&&nums[r]==sorted_num[r])
            --r;
        return r-l+1;

    }

    void quick_sort(vector<int>& nums, int l,int r){
        if(l<r){
            int pivot = nums[l];
            int i=l+1,j=r;
            while(i<=j){
                while(i<=j&&nums[j]>pivot)
                    --j;
                while(i<=j&&nums[i]<=pivot)
                    ++i;
                if(i>j)
                    break;
                else
                    swap(nums[i],nums[j]);
            }
            swap(nums[l],nums[j]);
            quick_sort(nums,l,j-1);
            quick_sort(nums,j+1,r);
        }
    }
};