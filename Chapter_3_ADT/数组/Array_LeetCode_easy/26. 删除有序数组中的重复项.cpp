// 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
// 输入：nums = [1,1,2]
// 输出：2, nums = [1,2]
// 解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。

// [1,1,2]
// [1,1]
// [1]
// [0,0,1,1,1,2,2,3,3,4]


// [1,2]
// [1]
// [1]
// [0,1,2,3,4]


// 双指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length==0||length==1)
            return length;
        int i=0,j=0;
        while(j<length){
            while(j<length&&nums[i]==nums[j]){
                ++j;
            }
            if(j==length){
            break;
            }
            else{
            ++i;
            nums[i] = nums[j];
            ++j;
            }
        }
        ++i;
        return i;
    }
};