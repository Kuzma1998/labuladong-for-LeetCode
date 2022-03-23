/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-23 17:31:50
 */
// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的连续子数组的个数。
// 示例 1：
// 输入：nums = [1,1,1], k = 2
// 输出：2
// 示例 2：
// 输入：nums = [1,2,3], k = 3
// 输出：2

// 暴力
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int sz = nums.size();
        for(int i=0;i<sz;++i){
            int sum = 0;
            for(int j=i;j<sz;++j){
                sum += nums[j];
                if(sum==k)
                    cnt++;
            }
        }
        return cnt;
    }
};


// 前缀和

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, sum =0;
        int sz = nums.size();
        unordered_map<int,int> map;
        map[0] = 1;
        for(int i=0;i<sz;++i){
            sum+= nums[i];
            if(map.find(sum-k)!=map.end())
                cnt += map[sum-k];
            map[sum]++;
        }
        return cnt;
    }
};
