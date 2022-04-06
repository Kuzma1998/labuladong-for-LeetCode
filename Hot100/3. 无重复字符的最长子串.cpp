// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
// 示例 1:
// 输入: s = "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 示例 2:
// 输入: s = "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 示例 3:
// 输入: s = "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 提示：
// 0 <= s.length <= 5 * 104
// s 由英文字母、数字、符号和空格组成

// 集合双指针

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        set<char> ss;
        int l=0,r=1;
        int ans = 1;
        ss.insert(s[0]);
        while(r<s.size()){
            // 右指针不在里面 一直加
            while(r<s.size()&&ss.find(s[r])==ss.end()){
                ss.insert(s[r]);
                ++r;
            }
            // 计算长度
            ans = max(r-l,ans);
            if(r==s.size())return ans;
            // 移除左指针对应元素 直到右指针不在
            while(ss.find(s[r])!=ss.end()){
                ss.erase(s[l]);
                ++l;
            }
        
    }
        return ans;
    }
};
