// 给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。

// 思路：排除法，填充表格；先初始化全为质数，那么这些质数的倍数都不是质数
class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes(n,1);
        for(int i=2;i*i<n;++i){//只需从2开始遍历到根号n
            if(primes[i]){
                for(int j=i*i;j<n;j+=i)//从i的平方开始。每加i变为非质数
                    primes[j] = false;
            }
        }
        int ans = 0;
        for(int i=2;i<n;++i)
            ans+=primes[i];
        return ans;
    }
};