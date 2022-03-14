/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-14 21:16:15
 */
// 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
// 示例 1：
// 输入: n = 3
// 输出: 6
// 示例 2：
// 输入: n = 9
// 输出: 45
// 思路：递归

class Solution {
private: 
    int ans = 0;//结果
public:
    int sumNums(int n) {
        ans = n;
        dg(n);
        return ans;
    }
    int dg(int n){
        n&&(ans +=dg(n-1));
        return n;
    }
};
