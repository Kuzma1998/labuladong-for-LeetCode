// 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
// 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
// 示例 1:
// 输入: s = "cbaebabacd", p = "abc"
// 输出: [0,6]
// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。

// 暴力匹配
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())
            return {};
        unordered_map<char,int> mp;
        
        for(auto c:p){
            mp[c]++;
        }
        int l=0,r=0;
        vector<int> ans;
        for(;r<s.size();++r){
            unordered_map<char,int> mp2;
            char c = s[r];
            int sz = 0;
            int cnt = 0;
            while(mp.find(c)!=mp.end()&&sz<p.size()){
                mp2[c]++;
                if(mp2[c]==mp[c]){
                    ++cnt;
                }
                if(cnt==mp.size())
                    ans.push_back(r);
                sz++;
                c = s[r+sz];

            }
        }
        return ans;
    }
};

// 双指针移动
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())
            return {};
        vector<int> pCount(26,0);
        vector<int> sCount(26,0);
        for(int i=0;i<p.size();++i){
            ++sCount[s[i]-'a'];
            ++pCount[p[i]-'a'];
        }
        vector<int> ans;
        if(sCount==pCount)
            ans.push_back(0);
        // 1加1减 如果两个矩阵一样 那么加入答案
        for(int i=0;i<s.size()-p.size();++i){
            --sCount[s[i]-'a'];
            ++sCount[s[i+p.size()]-'a'];
            if(sCount==pCount)
                ans.push_back(i+1);
        }
        return ans;
    }
};