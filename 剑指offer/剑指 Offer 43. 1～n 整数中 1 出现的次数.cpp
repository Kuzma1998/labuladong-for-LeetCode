// 输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
// 例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。


// 找规律

class Solution {
public:
    int countDigitOne(int n) {
        long long mul =1;
        int ans = 0;
        for(int k=0;n>=mul;++k){
            ans += (n/(mul*10))*mul + min(
                max( n % ( 10 * mul) -mul + 1,0LL),mul);
                mul *= 10;
        }
        return ans;
    }
};