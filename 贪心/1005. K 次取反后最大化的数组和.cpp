// 给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：
// 选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
// 重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
// 以这种方式修改数组后，返回数组 可能的最大和 。
// 输入：nums = [4,2,3], k = 1
// 输出：5
// 解释：选择下标 1 ，nums 变为 [4,-2,3] 。

//、思路：贪心，先按照绝对值排序，把负数变为正数，再动绝对值最小的

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),[](int a,int b){return abs(a)>abs(b);});
        for(int i=0;i<nums.size();++i){
            if(nums[i]<0&&k>0){
                nums[i] *= -1;
                --k;
            }
        }
        if(k%2)
            nums[nums.size()-1] *= -1;
        return accumulate(nums.begin(),nums.end(),0);
    }
};