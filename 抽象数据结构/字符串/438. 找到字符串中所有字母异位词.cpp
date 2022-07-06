/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-11-03 22:22:48
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-11-04 21:42:31
 */
// 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
// 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
// 输入: s = "cbaebabacd", p = "abc"
// 输出: [0,6]
// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。

// 滑动窗口法

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())
            return {};
        vector<int> ans;
        vector<int> sv(26,0);// 对s建立向量，s[0]代表出现a的个数
        vector<int> pv(26,0);// 对p建立向量，p[0]代表出现a的个数
        for(auto i:p){
            pv[i-'a']++;
        }
        int left=0;
        for(int right=0;right<s.size();++right){
            sv[s[right]-'a']++;
            while(sv[s[right]-'a']>pv[s[right]-'a']){// 若sv对应的字母个数没有大于pv对应的字母个数不循环
                sv[s[left]-'a']--;// 若sv对应的字母个数大于pv对应的字母个数，若s出现了个新的字母，那么左移到右位置
                ++left;             // 若sv出现了重复字母，则左移动到重复字母之后一个
            }
            if(right-left==p.size()-1)// 当右减左等于p.size()-1
                ans.push_back(left);// 添加对应答案
        }
        return ans;
    }
};

// 哈希表
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int l1 = s.size(),l2=p.size();
        if(l1<l2)
            return ans;
        unordered_map<char,int> memo;
        unordered_map<char,int> expected;
        // 记录p的字符出现的次数
        for(auto c:p)
            memo[c]++;
        int count = 0;
        int i = 0;
        // 遍历s前p.size()个
        for(;i<p.size();++i){
            char c = s[i];
            expected[c]++;
            // 每当 有一个字符次数和memo里面的相同 递增count
            if(memo.find(c)!=memo.end()&&memo[c]==expected[c])
                ++count;
        }
        // 
        if(count==memo.size()) ans.push_back(i-p.size());
        // 遍历后面的
        for(;i<s.size();++i){
            // 待删除的字符
            char last = s[i-p.size()];
            expected[last]--;
            if(expected[last]==0)
                expected.erase(last);
                // 当第一次出现不同的时候，递减count
            if(memo.find(last)!=memo.end()&&expected[last]+1==memo[last]){
                --count;
            }
            // 待加入的字符
            char c = s[i];
            expected[c]++;
            //再次相等，count递增
            if(memo.find(c)!=memo.end()&&expected[c]==memo[c]){
                ++count;
            }
            if(count==memo.size())  ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};