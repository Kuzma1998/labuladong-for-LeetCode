
// DFS
bool wordBreak(string s, vector<string>& wordDict) {    
        set<string> word(wordDict.begin(),wordDict.end());  
        vector<int> memo(s.size(), -1);
        return dfs(s,word,memo,0);
    }

    bool dfs(string s,set<string>& word,vector<int>& memo,int start){
        if(start > s.size() - 1) return true;
        if(memo[start] != -1) return memo[start];
        for(int end = start + 1;end <= s.size();++end){
            if(word.find(s.substr(start,end - start)) != word.end() && dfs(s,word,memo,end)){
                memo[start] = 1;
                return true;
            }
        }
        memo[start] = 0;
        return false;
    }



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[j]表示s里面前j个是否可以由wordDict里的单词构成
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;

        for(int i=0;i<s.size();++i){
            string temp;
            for(int j=0;j<wordDict.size();++j){
                int sz = wordDict[j].size();
                temp = s.substr(i,sz);//
                if(temp==wordDict[j]){//i往前截取sz单词如果相等
                                        // 状态转移方程 ,若原来就是true，那就是true，若原来不是true，若dp[i]是true，那么它一定是true
                    dp[i+wordDict[j].size()] = dp[i+wordDict[j].size()]||dp[i];
                }
            }
        }
        return dp[s.size()];
    }
};