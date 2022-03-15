/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-15 16:14:51
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0] = true;
        for(int i=2;i<=n;++i){
            if(p[i-1]=='*')
                dp[0][i] = dp[0][i-2]; // ""与 "a*b*"这类匹配
        }
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                // s的第i个与j的第i个相等
                if(s[i-1]==p[j-1]||p[j-1] =='.')
                    dp[i][j] = dp[i-1][j-1];
                    // s的第i个与j的第i个不相等
                else if(p[j-1]=='*'){
                    if(s[i-1]==p[j-2]||p[j-2]=='.')
                                    // 消掉前面    重复1次     重复2次
                        dp[i][j] = dp[i][j-2]||dp[i-1][j-1]||dp[i-1][j];
                        //若s[i]和p[j-1]不等于，只能消除p[j-1]了
                    else
                        dp[i][j] = dp[i][j-2];
                }  
            }
        }
        return dp[m][n];
    }
};