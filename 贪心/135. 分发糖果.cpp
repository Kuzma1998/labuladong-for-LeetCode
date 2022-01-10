// n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
// 你需要按照以下要求，给这些孩子分发糖果：
// 每个孩子至少分配到 1 个糖果。
// 相邻两个孩子评分更高的孩子会获得更多的糖果。
// 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
// 输入：ratings = [1,0,2]
// 输出：5
// 解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。

// 思路：贪心，扫描两次数组

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> dp(ratings.size(),1);
        for(int i=1;i<ratings.size();++i){
            //右大于左，必然右边比左边大1;
            if(ratings[i]>ratings[i-1])
                dp[i] = dp[i-1]+1;
        }
        //后往前遍历，前大于后，前=max(后+1，前)
        for(int i=ratings.size()-2;i>=0;--i){
            if(ratings[i]>ratings[i+1]){
                dp[i] = max(dp[i],dp[i+1]+1);
            }
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};