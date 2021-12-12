/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-12 14:47:41
 */

// 给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
// 示例 1：
// 输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
// 输出： True
// 说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。

// 思路1:以数字的视角，数字要撞到K个桶里面去

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int> bucket(k,0);
        int sum = accumulate(nums.begin(),nums.end(),0); //求和
        if(sum%k)
            return false;
        int target = sum/k;
        sort(nums.begin(),nums.end(),[](int a,int b){return a>b;});// 排序,大到小
        return traceback(nums,bucket,target,0);
    }

    bool traceback(vector<int>& nums,vector<int>& bucket,int target,int index){
        // 满足条件，看结果是true还是false
        if(index==nums.size()){
            for(auto i:bucket){
                if(i!=target)
                    return false;
            }
            return true;
        }
        // 遍历所有的位置，如果nums[index]不能放进去则false
        // 选择列表就是bucket,若选择某个位置，则把nums[index]加进去
        for(int j=0;j<bucket.size();++j){
                if(bucket[j]+nums[index]>target)
                    continue; 
                bucket[j]+=nums[index]; // 选择某个bucket
                if(traceback(nums,bucket,target,index+1))
                    return true;
                bucket[j]-=nums[index]; // 撤销选择
            }
        return false;
    }
};


思路2：桶的视角，桶要遍历数组，看是否选择当前的数

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k)
            return false;
        int target = sum/k;
        vector<bool> used(nums.size(),false);
        // sort(nums.begin(),nums.end(),[](int a,int b){return a>b;});
        return trackback(nums,k,target,0,0,used);
    }
    // 路径是bucket，选择是nums
    bool trackback(vector<int>& nums,int k,int target,int bucket,int index,vector<bool>& used){
        if(k==0)
            return true;
        if(bucket==target)// 从0开始继续装
            return trackback(nums,k-1,target,0,0,used);
        // 遍历数组，看哪个能插入桶里面
        for(int i=index;i<nums.size();++i){
            if(used[i])
                continue;
            if(nums[i]+bucket>target)
                continue;
                // 进行选择
            used[i] = true;
            bucket += nums[i];
            if(trackback(nums,k,target,bucket,i+1,used))// 如果这条路径通了，直接返回true
                return true;
            used[i] = false;//此次选择不行，撤销
            bucket -= nums[i];
        }
        return false;
    }
};