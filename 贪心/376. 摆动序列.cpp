// 如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。
// 仅有一个元素或者含两个不等元素的序列也视作摆动序列。
// 例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。
// 相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，
// 第二个序列是因为它的最后一个差值为零。
// 子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。
// 给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。

// 输入：nums = [1,17,5,10,13,15,10,5,16,8]
// 输出：7
// 解释：这个序列包含几个长度为 7 摆动序列。
// 其中一个是 [1, 17, 10, 13, 10, 16, 8] ，各元素之间的差值为 (16, -7, 3, -3, 6, -8) 

// 思路1：贪心，遍历数组，维护两个差值即可

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 1;
        if(nums.size()<=1)
            return nums.size();
        int diff1 = 0,diff2 = 0;
        for(int i=1;i<nums.size();++i){
            diff1 = nums[i]-nums[i-1];
            if(diff1>0&&diff2<=0||diff1<0&&diff2>=0){
                ++ans;
                diff2=diff1;
            }
        }
        return ans;
    }
};

// 思路2：动态规划，

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(2,0));
        dp[0][0] = 1; //  dp[i][0]代表i结尾，i为波峰时的摆动子序列的长度
        dp[0][1] = 1; //  dp[i][1]代表i结尾，i为波谷时的摆动子序列的长度
        for(int i=0;i<nums.size();++i){
            dp[i][0] = dp[i][1] =1;
            for(int j =0;j<i;++j){
                if(nums[j]<nums[i])
                    dp[i][0] = max(dp[i][0],dp[j][1]+1);// j为波谷时+1，状态转移方程
            }
            for(int j=0;j<nums.size();++j){
                if(nums[j]>nums[i])
                    dp[i][1] = max(dp[i][1],dp[j][0]+1);// j为波峰+1，状态转移方程
            }
        }
        return max(dp[nums.size()-1][0],dp[nums.size()-1][1]);
    }
};
