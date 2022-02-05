// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
// 输入：s = "aa" p = "a*"
// 输出：true
// 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。


class Solution {
    private:
    map<string,bool> map;
public:
     bool dp(string s,int i, string p, int j){
        int m = s.size();
        int n = p.size();
        // base case 当模式串走到最后，看匹配串走到哪
        if(j==n){
            return i==m;
        }
        //匹配串走到尾，模式串后面的要匹配空字符串.
        if(i==m){
            if((n-j)%2==1){
                // if((n-j==1)&&p[j]=='*')
                //     return true;
                return false;
            }
            for(;j+1<p.size();j+=2){
                if(p[j+1]!='*')
                    return false;
            }
            return true;
        }

        string key = to_string(i)+","+to_string(j);
        //备忘录
        if(map.count(key))
            return map[key];
        
        bool res = false;
        //
        if((s[i]==p[j])||p[j]=='.'){
            if((j<n-1)&&p[j+1]=='*'){
                res= dp(s,i,p,j+2)||dp(s,i+1,p,j);// 匹配0次或者匹配多次
            }
            else
                res= dp(s,i+1,p,j+1);//正常匹配
            }
        else{
            if(j<n-1&&p[j+1]=='*')
                res= dp(s,i,p,j+2);//匹配0次
            else
                res= false;//不相等并且无“*“号
            }
        map[key] = res;
        return res;
        }
    bool isMatch(string s, string p) {
        return dp(s,0,p,0); 
    }
   
};


// DP

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(),n = p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0] = true;//空串可以匹配
        for(int i=2;i<=n;++i)
            if(p[i-1]=='*') dp[0][i] = dp[0][i-2];
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(s[i-1]==p[j-1]||p[j-1]=='.'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1]=='*'){
                    if(s[i-1]==p[j-2]||p[j-2]=='.')
                    // 消失，重复一次，重复多次
                        dp[i][j] = dp[i][j-2]||dp[i-1][j-2]||dp[i-1][j];
                    else
                        dp[i][j] = dp[i][j-2];
                }
            }
        }
        return dp[m][n];
    }
};