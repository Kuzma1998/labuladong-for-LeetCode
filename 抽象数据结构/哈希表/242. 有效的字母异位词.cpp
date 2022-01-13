// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
// 示例 1:
// 输入: s = "anagram", t = "nagaram"
// 输出: true


class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp1;
        map<char,int> mp2;
        if(s.size()!=t.size())
            return false;
        for(int i=0;i<s.size();++i){
            if(!mp1.count(s[i]))
                mp1[s[i]] =1;
            else
                mp1[s[i]] += 1;
            if(!mp2.count(t[i]))
                mp2[t[i]] =1;
            else
                mp2[t[i]] += 1;
        }
        return mp1==mp2;
    }
};


// 只需一个数组即可
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
                return false;
            }
        }
        // record数组所有元素都为零0，说明字符串s和t是字母异位词
        return true;
    }
};