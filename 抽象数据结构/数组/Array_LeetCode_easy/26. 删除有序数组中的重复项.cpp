/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-04 11:11:36
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-13 15:39:52
 */
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


// 双指针  自己写的和屎一样 再简单扩展一下，
// 如果给你一个有序链表，如何去重呢？这是力扣第 83 题，其实和数组去重是一模一样的，唯一的区别是把数组赋值操作变成操作指针而已：
// 还有leetcode 27
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

// standard
int removeDuplicates(int[] nums) {
    if (nums.length == 0) {
        return 0;
    }
    int slow = 0, fast = 0;
    while (fast < nums.length) {
        if (nums[fast] != nums[slow]) {
            slow++;
            // 维护 nums[0..slow] 无重复
            nums[slow] = nums[fast];
        }
        fast++;
    }
    // 数组长度为索引 + 1
    return slow + 1;
}