// 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
// 输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
// 输出：2
// 解释：
// 两个元组如下：
// 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
// 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

// 思路：哈希，两两分组数组，先求前两个数组之和，结果的次数存入哈希表，然后再求后两个数组求和，看相反数在不在哈希表里面。

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mp;
        int count = 0;
        int sum =0;
        for(auto i:nums1){
            for(auto j:nums2){
                sum = (i+j);
                if(!mp.count(sum)){
                    mp[sum] =1;
                }else
                    ++mp[sum];
            }
        }
        for(auto i:nums3){
            for(auto j:nums4){
                if(mp.find(0-(i+j))!=mp.end()){
                    count += mp[0-(i+j)];
                }
            }
        }
        return count;
    }
};