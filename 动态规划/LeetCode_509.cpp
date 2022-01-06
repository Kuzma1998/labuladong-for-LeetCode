// 斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和



class Solution {
public:
    int fib(int n) {
        if(n==0)//初始状态
            return 0;
        if(n==1||n==2)//初始状态
            return 1;
        int pre=1,curr=1;
        int sum;
        for(int i=3;i<=n;i++){
            sum = pre+curr;//状态转移方程
            pre= curr;
            curr = sum;
        }
        return sum;

    }
};