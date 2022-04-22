// 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
// 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
// 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

// DP
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int sz = nums.size();
       vector<int> left(sz,1);
       vector<int> right(sz,1);
       for(int i=1;i<sz;++i){
           left[i] = nums[i-1]*left[i-1];
       }
       for(int i=sz-2;i>=0;--i){
           right[i] = nums[i+1]*right[i+1];
       }
       vector<int> ans(sz,1);
       for(int i=0;i<sz;++i){
           ans[i] = left[i]*right[i];
       }
        return ans;
    }
};

// 进阶空间复杂度O（1）
// 输出的ans数组先用于求左数组
// 边求右数组 边求和
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> answer(length);

        // answer[i] 表示索引 i 左侧所有元素的乘积
        // 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
        answer[0] = 1;
        for (int i = 1; i < length; i++) {
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R 为右侧所有元素的乘积
        // 刚开始右边没有元素，所以 R = 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--) {
            // 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
            answer[i] = answer[i] * R;
            // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
            R *= nums[i];
        }
        return answer;
    }
};
