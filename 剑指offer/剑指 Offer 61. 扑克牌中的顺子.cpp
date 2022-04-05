/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-13 17:01:19
 */
// 从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。
// 示例 1:
// 输入: [1,2,3,4,5]
// 输出: True
// 示例 2:
// 输入: [0,0,1,2,5]
// 输出: True
// 思路：排序加比大小，最大减去最小不超过5
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int jokers = 0;
        for(int i=0;i<4;++i){
            if(nums[i]==0)
                ++jokers;
            else if(nums[i]==nums[i+1])
                return false;
        }
        return nums[4]-nums[jokers]<5;
    }
};

// 自己写的  
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        // 排序统计0的个数
        sort(nums.begin(),nums.end());
        int zero = 0; 
        for(auto num:nums){
            if(num==0)  
                ++zero;
        }
        // 没有0的话 后一个只能比前一个大一
        if(zero==0){
            for(int i=1;i<5;++i){
                if(nums[i]==nums[i-1])
                    return false;
                else if(nums[i]-nums[i-1]>1)
                    return false;
                else if(nums[i]==nums[i-1]+1)
                    continue;
            }
            return true;
        }
        // 有0的话 ，后一个比前一个差只能小于等于0的个数+1
        for(int i=zero+1;i<5;++i){
            if(nums[i]==nums[i-1])
                return false;
            else if(nums[i]-nums[i-1]>zero+1)
                return false;
            else if(nums[i]-nums[i-1]<=zero+1)
                continue;
        }
        return true;
    }
};