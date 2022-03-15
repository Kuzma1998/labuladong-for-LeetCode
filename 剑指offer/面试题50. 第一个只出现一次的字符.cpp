/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-15 16:50:31
 */
// 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
// 思路：有序hash
class Solution {
public:
    char firstUniqChar(string s) {
        vector<char> keys;
        unordered_map<char, bool> dic;
        for(char c : s) {
            if(dic.find(c) == dic.end())
                keys.push_back(c); //保存各个字符首次出现的顺序
            dic[c] = dic.find(c) == dic.end();//出现两次以上置为false，一次为true
        }
        for(char c : keys) {
            if(dic[c]) return c;
        }
        return ' ';
    }
};
