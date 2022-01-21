// 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
// 你可以对一个单词进行如下三种操作：
// 插入一个字符
// 删除一个字符
// 替换一个字符
// 输入：word1 = "horse", word2 = "ros"
// 输出：3
// 解释：
// horse -> rorse (将 'h' 替换为 'r')
// rorse -> rose (删除 'r')
// rose -> ros (删除 'e')

//思路 对每个单词有四种状态,跳过，替换，删除，添加。定义一个二维数组dp,dp[i][j]代表s1[0..i-1]变换到s2[0..j-1]需要的最少次数。
// 先初始化二维数组dp[0][j] = j;dp[i][0] =i;
//如果s1[i-1]==si[j-1],那么dp[i][j]=dp[i-1][j-1];
//否则 dp[i][j] = MIN(dp[i][j-1] +1, //插入
                        // dp[i-1][j]+1, //删除1
                        // dp[i-1][j-1]+1 //替换
                    

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
	    int dp[m+1][n+1];//定义二维数组
        // int[][] dp = new int[m+1][n+1];
        for(int j=0;j<=n;++j)
            dp[0][j] = j;
        for(int i=0;i<=m;++i)
            dp[i][0] = i;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = MIN(dp[i][j-1] +1, //插入
                        dp[i-1][j]+1, //删除1
                        dp[i-1][j-1]+1 //替换
                    );
                }
            }
        return dp[m][n];
    }
    int MIN(int a,int b,int c){
        return min(a,min(b,c));
    }
};
