// 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
// 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
//      注意，你可以重复使用字典中的单词。

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