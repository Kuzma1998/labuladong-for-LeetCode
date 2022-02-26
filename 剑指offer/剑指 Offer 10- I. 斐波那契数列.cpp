// 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：
// F(0) = 0,   F(1) = 1
// F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
// 斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。



class Solution {
public:
    int fib(int n) {
        if(n==0||n==1)
            return n;
        int temp1 = 0;
        int temp2 = 1;
        int ans;
        for(int i=2;i<=n;++i){
            ans = (temp1+temp2)%1000000007;
            temp1 = temp2;
            temp2 = ans;
        }
        return ans;
    }
};

// 思路2：带有优化的递归

class Solution {
private:
    unordered_map<int,int> map;
    const static int md  = 1000000007;//注意加const
public:
    int fib(int n) {
        if(n==0||n==1)
            return n;
        if(map[n])
            return map[n]%md;
        map[n] = (fib(n-1)+fib(n-2))%md;
        return map[n];
    }
};