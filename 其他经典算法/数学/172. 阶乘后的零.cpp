// 给定一个整数 n ，返回 n! 结果中尾随零的数量。
// 提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1
// 思路：0由2和5变来，直接搜寻1到n可以分为多少个5即可

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int num =5;
        while(n>=5){
            ans += n/num;
            n=n/5;
        }
        return ans;
    }
};