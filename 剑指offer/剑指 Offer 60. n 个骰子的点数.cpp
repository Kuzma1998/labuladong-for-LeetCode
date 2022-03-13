/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-11 21:25:54
 */

// 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
// 你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。


class Solution {
public:
    vector<double> dicesProbability(int n) {
        int sz = 6*n+1;
        vector<vector<double>> dp(n+1,vector<double>(sz,0));
        for(int i=1;i<=6;++i)
            dp[1][i] = 1.0/6;
        for(int i=2;i<=n;++i){
            for(int j=i;j<=i*6;++j){
                for(int k=1;k<=6;++k){
                    if(j-k<=0) break;
                    else
                        dp[i][j] += dp[i-1][j-k]/6;
                }
            }
        }
        vector<double> ans(5*n+1,0.0);
        for(int i=0;i<ans.size();++i){
            ans[i] = dp[n][n+i];
        }
        return ans;

    }
};