// 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

// 投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 1;
        int num = nums[0];
        for(int i=1;i<nums.size();++i){
            if(vote==0){
                num = nums[i];
                vote++;
                continue;
            }
            if(nums[i]==num){
                ++vote;
            }else{
                --vote;
            }
        }
        return num;
    }
};