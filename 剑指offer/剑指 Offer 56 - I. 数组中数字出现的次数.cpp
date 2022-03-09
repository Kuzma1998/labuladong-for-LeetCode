// 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
// 示例 1：
// 输入：nums = [4,1,4,6]
// 输出：[1,6] 或 [6,1]
// 示例 2：
// 输入：nums = [1,2,10,4,1,4,3,3]
// 输出：[2,10] 或 [10,2]

// 位运算
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
       int x = 0,y=0,m=1,n=0;
       for(auto num:nums){
           n ^= num;
       }
       while((n&m)==0)
            m<<=1;// m左移
        for(auto num:nums){
            if(m&num)
                x ^= num;
            else
                y ^= num;
        }
        return {x,y};
    }
};

// 排序加遍历
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end(),[](int& a,int& b){return a<b;});
        for(int i=1;i<nums.size();){
            if(nums[i]!=nums[i-1]){
                ans.push_back(nums[i-1]);
                ++i;
            }else
                i+=2;
        }
        if(ans.size()==1)
            ans.push_back(nums.back());
        return ans;
        
    }
};