#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//硬币找零问题
// 解法一
//相当于N差树的遍历问题
class Solution {
    vector<int>count;
    int dp(vector<int>& coins, int rem) {
        if (rem < 0) return -1;
        if (rem == 0) return 0;
        if (count[rem - 1] != 0) return count[rem - 1];
        int Min = INT_MAX;//数组count是每个前数所需要的最少次数，先给一个很大的数
        for (int coin:coins) {
            int res = dp(coins, rem - coin);
            if (res >= 0 && res < Min) {//比之前的次数少
                Min = res + 1;
            }
        }
        count[rem - 1] = Min == INT_MAX ? -1 : Min;
        return count[rem - 1];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        count.resize(amount);//初始化数组为0
        return dp(coins, amount);
    }
};



int main(){
    vector<int> coins = {5,1,2};
    int amount = 2;
    Solution s;
    int c = s.coinChange(coins, amount);
    cout<<c<<endl;
}
