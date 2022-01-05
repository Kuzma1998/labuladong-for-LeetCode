// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
// 示例:
// 输入: [0,1,0,3,12]
// 输出: [1,3,12,0,0]

// 思路1：替换法
// 把不为0的数替换到最前面，记录不为0的个数j，然后把j到最后的数变为0；
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]){
                nums[j] = nums[i];
                ++j;
            }
        }
        for(;j<nums.size();++j){
            nums[j]=0;
        }
    }
};


// 思路2：双指针法，左指针指向以排好序的部分，右指针指向为处理的部分，当右指针的数不为0就与左指针替换，然后左值针移动；
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left =0, right= 0;
        while(right<nums.size()){
            if(nums[right]){
                swap(nums[left],nums[right]);// 移动不为0的数
                left++;// 左值针与右指针交换才移动
            }
            right++;//右指针一直移动
        }
    }
};