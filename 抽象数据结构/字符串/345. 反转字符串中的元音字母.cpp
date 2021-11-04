/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-11-03 21:12:43
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-11-03 21:12:44
 */
// 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
// 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。

// 输入：s = "hello"
// 输出："holle"

// 思路：双指针

class Solution {
private:
    string str = "AEIOUaeiou";
public:
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            while(i<j&&!isYuanYin(s[i]))
                ++i;
            if(i==j)
                break;
            while(i<j&&!isYuanYin(s[j]))
                --j;
            if(i==j)
                break;                
            if(isYuanYin(s[i])&&isYuanYin(s[j])){
            char temp;
            temp = s[j];
            s[j] = s[i];
            s[i] = temp;
            ++i;
            --j;
            }
        }
        return s;
    }
    bool isYuanYin(char c){
        for(auto i:str){
            if(i==c)
                return true;
        }
        return false;
    }
};