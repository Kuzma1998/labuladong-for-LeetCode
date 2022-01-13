// 给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（ 包括重复字符），
// 并以数组形式返回。你可以按 任意顺序 返回答案。

// 输入：words = ["bella","label","roller"]
// 输出：["e","l","l"]

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> hasmap(26,0);
        for(int i=0;i<words[0].size();++i){
            hasmap[words[0][i]-'a']++;
        }
        // vector<int> hasmap(26,0);
        for(int i=1;i<words.size();++i){
            vector<int> hasmap2(26,0); 
            for(int j=0;j<words[i].size();++j){
                hasmap2[words[i][j]-'a']++;
            }
            for(int k=0;k<26;k++){
                hasmap[k] = min(hasmap[k],hasmap2[k]);
            }
        }
        vector<string> ans;
        for(int i=0;i<26;++i){
            while(hasmap[i]){
                string temp(1,i+'a');
                ans.push_back(temp);
                hasmap[i]--;
            }
        }
        return ans;

    }
};