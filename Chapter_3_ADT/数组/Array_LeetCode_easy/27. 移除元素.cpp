// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

// 思路一：与移动0一样，统计不为val的个数即可。
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;//数数组里面不为val的个数
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=val){
                nums[j] = nums[i];
                ++j;
            }
        }
        return j;
    }
};
// 时间复杂度：O(n)O(n)，其中 nn 为序列的长度。我们只需要遍历该序列至多2次。
// 空间复杂度：O(1)O(1)。我们只需要常数的空间保存若干变量。


// 思路2：双指针

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0;
        int right=nums.size();
        while(left<right){
            if(nums[left]==val){// 如果左值等于val，交换左与右，那么右的值一定为val，将右减一；
                nums[left] = nums[right-1];
                --right;
            }else{
                ++left;// 左值不等于val，递增即可
            }
        }
    }
};
// 时间复杂度：O(n)O(n)，其中 nn 为序列的长度。我们只需要遍历该序列至多一次。

// 空间复杂度：O(1)O(1)。我们只需要常数的空间保存若干变量。