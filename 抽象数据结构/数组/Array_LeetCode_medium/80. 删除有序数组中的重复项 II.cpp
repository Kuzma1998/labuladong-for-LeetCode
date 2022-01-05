// 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。
// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
// 输入：nums = [1,1,1,2,2,3]
// 输出：5, nums = [1,1,2,2,3]
// 解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。 不需要考虑数组中超出新长度后面的元素。

// 思路1：双指针

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nums_length = nums.size();
        if(nums_length<=2){
            return nums_length;
        }
        int fast =2,slow =2;
        // fast代表遍历数组的位置，slow代表处理好的数组的位置
        while(fast<nums_length){
            if(nums[fast]!=nums[slow-2]){  //不相等，那么说明当前位置需要保存
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;//不需要保存则++fast
        }
        return slow;
    }
};

// 思路2：通解
class Solution {
public:
    int work(vector<int>& nums, int k) {
        int len = 0;//需要保留的位置
        for(auto num : nums)
            if(len < k || nums[len-k] != num)
                nums[len++] = num;
        return len;
    }
    int removeDuplicates(vector<int>& nums) {
        return work(nums, 2);
    }
};

// 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/solution/gong-shui-san-xie-guan-yu-shan-chu-you-x-glnq/
// 为了让解法更具有一般性，我们将原问题的「保留 2 位」修改为「保留 k 位」。
// 对于此类问题，我们应该进行如下考虑：
// 由于是保留 k 个相同数字，对于前 k 个数字，我们可以直接保留
// 对于后面的任意数字，能够保留的前提是：与当前写入的位置前面的第 k 个元素进行比较，不相同则保留
