// 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

//dp

class Solution {
private:
    int mod = 1000000007;
public:
    int numWays(int n) {
        if(n==0||n==1)
            return 1;
        vector<int> ans(n+1,1);
        for(int i=2;i<=n;++i){
            ans[i] = (ans[i-1]+ans[i-2])%mod;
        }
        return ans[n];
    }
};