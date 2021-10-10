// 爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。
// 最初，黑板上有一个数字 N 。在每个玩家的回合，玩家需要执行以下操作：
// 选出任一 x，满足 0 < x < N 且 N % x == 0 。
// 用 N - x 替换黑板上的数字 N 。
// 如果玩家无法执行这些操作，就会输掉游戏。
// 只有在爱丽丝在游戏中取得胜利时才返回 True，否则返回 False。假设两个玩家都以最佳状态参与游戏。

// 示例 1：
// 输入：2
// 输出：true
// 解释：爱丽丝选择 1，鲍勃无法进行操作。

// 示例 2：
// 输入：3
// 输出：false
// 解释：爱丽丝选择 1，鲍勃也选择 1，然后爱丽丝无法进行操作。

// 方法1 偶数赢奇数输

// 方法2 动态规划 dp[i] 代表从i开始谁先动谁输谁赢
// 若alice赢，那么一定可以找到一个数j，i可以整除j，并且dp[i-j] = false，代表i-j爱丽丝输掉，i-j爱丽丝输的话，从i开始可以得到i-j bob输掉

class Solution {
public:
    bool divisorGame(int n) {
       vector<bool> dp(n+1,false);
       dp[1] = false;
       dp[2] = true;
       for(int i=3;i<=n;i++){ // 从三开始遍历到n
           for(int j=1;j<=i-1;j++){  //除数不能大于被除数
                if((i%j==0) && dp[i-j]==false){  // 满足条件，那么alice赢，dp[i]==true;
                    dp[i] = true;
                    break;
                }
           }
       }
       return dp[n];
    }
};
 