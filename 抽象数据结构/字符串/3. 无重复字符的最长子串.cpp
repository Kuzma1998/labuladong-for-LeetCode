/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-11-04 21:48:46
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-11-05 20:25:21
 */

// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
// 输入: s = "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 
// 方法1：哈希表
class Solution {
private:
    unordered_map<char,int> map;
public:
    int lengthOfLongestSubstring(string s) {
        int max_len=1;
        int j=0;
        if(s.size()==0)
            return 0;
        for(int i=0;i<s.size();++i){
            while(j<s.size()&&!map.count(s[j])){
                map[s[j]]=1;
                ++j;
            }
            max_len=max(j-i,max_len);
            if(j==s.size())
                break;

            map.erase(s[i]);
        }
        return max_len;
    }
};

方法2：滑窗

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0,length=0;
        int n = s.size(), i=0,j=0;
        // d当j小于n
        while(j<n){
            char temp=s[j];// 保存第j个字符
            // for循环用于判断从i开始是否有元素与s[j]相等
            for(int index=i;index<j;++index){
                //若有，记录为index，有的话就改变i的位置
                if(s[index]==temp){
                    i=index+1;
                    length = j-i;//求长度
                    break;
                }
            }
            ++j;
            ++length;
            max_len = max(max_len,length);
        }
        return max_len;
    }
};