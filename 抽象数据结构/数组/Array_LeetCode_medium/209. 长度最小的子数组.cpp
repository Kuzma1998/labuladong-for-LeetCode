/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-13 20:08:04
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-25 19:23:33
 */
// 给定一个含有 n 个正整数的数组和一个正整数 target 。
// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 
// [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

// 方法一，滑动窗口

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i =0,j=0; // 滑动窗口法，i为左边，j为右边
        int sum =0;
        int size=10000000;
        while(j<nums.size()){
            sum+=nums[j];// 遍历数组，累加到sum
            ++j;
            while(sum>=target){ // sum大于等于target
                sum -= nums[i];// sum减去nums[i]，滑窗
                ++i;
                size = min(size,j-i+1); // 求size的最小值
            }
        }
        return size==10000000?0:size;// 返回size
        
    }
};



// 方法二  暴力发 O（n2）

class Solution {
private:
    int size=1000000;
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            int sum=0;
            for(int j=i;j<nums.size();++j){
                sum += nums[j];
                if(sum>=target){
                    size = min(size,j-i+1);
                    break;
                }
            }
        }
        if(size==1000000)
            return 0;
        return size;
    }
};