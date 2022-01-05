/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-11-03 20:08:53
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-11-03 20:32:04
 */
// 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
// 输入: "abab"
// 输出: True
// 解释: 可由子字符串 "ab" 重复两次构成。

// 暴力匹配法
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if(n==1)
            return false;
        for(int i=n/2;i!=0;i--){
            if(n%i)
                continue;
            string temp;
            string s1 = s.substr(0,i);
            for(int j=n/i;j!=0;--j)
                temp+=s1;
            if(temp==s) 
                return true;
        }
        return false;
    }
};

// KMP算法  
// 数组长度减去最长相同前后缀的长度相当于是第一个周期的长度
// ，也就是一个周期的长度，如果这个周期可以被整除，就说明整个数组就是这个周期的循环。

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int next[s.size()];
        getNext(next,s);
        int l = s.size()-next[s.size()-1];
        if(next[s.size()-1]!=0&&(s.size()%l)==0)
            return true;
        return false;

    }
    // 建立表格
    void getNext(int* next,const string& s){
        int j=0;
        next[0]=j;
        for(int i=1;i<s.size();++i){
            while(j>0&&s[j]!=s[i]){
                j = next[j-1];
            }
            if(s[j]==s[i])
                ++j;
            next[i] =j;
        }
    }
};