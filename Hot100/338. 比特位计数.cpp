/*
 * @Description:
 * @code:
 * @Author: Li Jiaxin
 * @Date: 2022-03-23 15:08:20
 */
// 给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。
// 输入：n = 5
// 输出：[0,1,1,2,1,2]
// 解释：
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);
        while (n >= 1)
        {
            ans[n] = countOnes(n);
            --n;
        }
        return ans;
    }
    // 计算n的二进制表示含有1的位数
    int countOnes(int n)
    {
        int cnt = 0;
        while (n > 0)
        {
            if (n & 1)
                cnt++;
            n >>= 1;
        }
        return cnt;
    }
};

// dp
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> bits(n + 1);
        int highBit = 0;
        for (int i = 1; i <= n; i++)
        {
            // 如果i是2的整数次幂，那么 if条件成立
            if ((i & (i - 1)) == 0)
            {
                highBit = i;
            }
            // 若i是2的正数字幂，结果为1
            // 否则  则为i-highbit的位数+1
            bits[i] = bits[i - highBit] + 1;
        }
        return bits;
    }
};

