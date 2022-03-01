// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
// 示例：
// 输入：nums = [1,2,3,4]
// 输出：[1,3,2,4] 
// 注：[3,1,2,4] 也是正确的答案之一。

// 双指针
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int left =0, right = nums.size()-1;
        for(auto num:nums){
            if(num%2){
                res[left] = num;
                ++left;
            }else{
                res[right] = num;
                --right;
            }
        }
        return res;
    }
};

// 本地修改