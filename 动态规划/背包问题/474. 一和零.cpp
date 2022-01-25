// 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
// 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
// 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
// 输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
// 输出：4
// 解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。

// 思路：0-1背包问题，DP，只不过多了一个维度

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int k=0;k<strs.size();++k){
            bitset<100> bst(strs[k]);//二进制流
            for(int i=m;i>=0;--i){
                for(int j=n;j>=0;--j){
                    if(bst.count()>j||(strs[k].size()-bst.count()>i))//某个流的0的个数和1的个数不符合要求
                        dp[i][j] = dp[i][j];
                    else//状态转移
                        dp[i][j] = max(dp[i][j],1+dp[i-(strs[k].size()-bst.count())][j-bst.count()]);
                }
            }
        }
        return dp[m][n];
    }

};


// 代码优化,代码随想录的模板
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int k=0;k<strs.size();++k){
            bitset<100> bst(strs[k]);//二进制流
            for(int i=m;i>=(strs[k].size()-bst.count());--i){ // 遍历，且i要大于0的个数
                for(int j=n;j>=bst.count();--j){//j要大于1的个数

                        dp[i][j] = max(dp[i][j],1+dp[i-(strs[k].size()-bst.count())][j-bst.count()]);
                }
            }
        }
        return dp[m][n];
    }

};