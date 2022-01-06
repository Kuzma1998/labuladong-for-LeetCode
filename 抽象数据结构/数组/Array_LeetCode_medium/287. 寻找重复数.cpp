/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-25 21:16:42
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-25 21:46:49
 */

// 输入：nums = [1,3,4,2,2]
// 输出：2
// 方法2：二分搜索  搜索左边界
// 基本思想
// 若不存在重复得数，那么小于等于3的数只会等于3，但存在重复的数，那么小于等于3的数就可以大于3


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 若不存在重复得数，那么小于等于3的数只会等于3，但存在重复的数，那么小于等于3的数就可以大于3
        int n =nums.size();
        int left=1,right=n-1;
        int ans=0;
        while(left<=right){
            int mid=(left+right)/2;
            int cnt=0;
            for(auto num:nums){
                if(num<=mid)
                    ++cnt;
            }
            if(cnt>mid){
                right =mid-1;
                ans =mid;
            }else{
                left = mid +1;
            }
        }
        return ans;
    }
};

// 方法1：哈希表

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        for(auto num:nums){
            if(hashmap.count(num))
                return num;
            else{
                hashmap[num] =1;
            }
        }
        return 0;
    }
};