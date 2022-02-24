// 找出数组中重复的数字。
// 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
// 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
// 示例 1：
// 输入：
// [2, 3, 1, 0, 2, 5, 3]
// 输出：2 或 3 
//  

// hash
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto i:nums){
            if(map.count(i)){
                // map[i]++;
                return i;
            }
            else
                map[i] =1;
        }
        return -1;
    }
};

// 原地修改叔祖，用下标做映射
// 有一个关键点是只有 nums[i] == i 的时候i才递增，这样保证找到相同元素前不会漏掉某些元素的处理，一定要用while
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] == i) {
                i++;
                continue;
            }
            if(nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[i],nums[nums[i]]);
        }
        return -1;
    }
};

