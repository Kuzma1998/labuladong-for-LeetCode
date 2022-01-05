// 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

// 思路 ：动态规划，3 = 左1右1+左0右2+左2右0；
// 4 = 左1右2+左2右1+左3右0+右3左0；


class Solution {
public:
    int numTrees(int n) {
        vector<int> nums(n+1,0);
        nums[0] = 1;
        nums[1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=i-1;j++){
                nums[i] += nums[j]*nums[i-1-j];
            }
        }
        return nums[n];
    }
};