// 给你一个整数数组 nums ，
// 请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积

// 输入: [2,3,-2,4]
// 输出: 6
// 解释: 子数组 [2,3] 有最大乘积 6。

// 思路：维护两个DP数组 一个存以i结尾的最大连续积，一个存最小积
// 可以写出如下状态转移方程
//             Fmax[i] = max(Fmax[i-1]*nums[i],max(nums[i],Fmin[i-1]*nums[i]));
//             Fmin[i] = min(Fmin[i-1]*nums[i],min(nums[i],Fmax[i-1]*nums[i]));

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        vector<int> Fmax(sz,0);
        vector<int> Fmin(sz,0);
        Fmax[0] = Fmin[0] = nums[0];
        for(int i=1;i<sz;++i){
            Fmax[i] = max(Fmax[i-1]*nums[i],max(nums[i],Fmin[i-1]*nums[i]));
            Fmin[i] = min(Fmin[i-1]*nums[i],min(nums[i],Fmax[i-1]*nums[i]));
        }
        return findmax(Fmax);

    }
    int findmax(vector<int>& Fmax){
        int num = Fmax[0];
        for(auto i:Fmax){
            if(i>num)
                num = i;
        }
        return num;
    }
   
};