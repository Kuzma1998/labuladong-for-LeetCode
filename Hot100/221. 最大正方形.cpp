/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-21 19:50:09
 */
// 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

// 暴力法
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        int len = 0;
        if(m==0||n==0)
            return 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]=='1'){
                    len = max(len,1);
                    int maxlen = min(m-i,n-j);
                    for(int k=1;k<maxlen;++k){
                        bool flag = true;
                        if(matrix[i+k][j+k]=='0')
                            break;
                        for(int m=0;m<k;++m){
                            if(matrix[i+m][j+k]=='0'||matrix[i+k][j+m]=='0'){
                                flag = false;
                                break;
                            }
                        }
                        if(flag) len = max(len,k+1);
                        else break;
                    }
                }
            }
        }
        return len*len;
    }
};

// DP

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if(!m||!n)
            return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        int len = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if('1'==matrix[i][j]){
                    if(i==0||j==0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
                    len = max(len,dp[i][j]);
                }
            }
        }
        return len*len;
    }
};