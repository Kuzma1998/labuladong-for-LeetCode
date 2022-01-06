/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-31 17:04:30
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-11-01 20:45:28
 */
// 实现 strStr() 函数。
// 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 
// 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 
// "mississippi"
// "issip"
// 4

// 思路1 暴力遍历
class Solution {
public:
    int strStr(string haystack, string needle) {
        // 特殊情况
        if(needle=="")
            return 0;
        int l1 = haystack.size();
        int l2 = needle.size();
        if(l1<l2)
            return -1;
        // 
        int i=0,j=0;
        int count =0; // 计数器
        int index;// 返回的位置
        while(i<l1&&j<l2){
            j =0;// 每次循环置0
            i= count;// i每次+1
            ++count;
            if(haystack[i]!=needle[j])
                ++i;
            index = i; // 找到index
            while(j<l2&&i<l1){
                if(haystack[i]==needle[j])// 相等一直+1
                    {++j,++i;}
                else{
                    break;//不等break
                }
            }
        }
        if(j==l2)
            return index;
        return -1;
    }
};

// KMP算法

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
            return 0;
        int next[needle.size()];
        getNext(next,needle);
        int j=0;//模式串的索引
        for (int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
    void getNext(int* next,string needle){
        int i;// 后缀起始位置
        int j=0;// 前缀起始位置，也代表以i结尾的字符串的最大相等前后缀的长度
        next[0] =j;
        for(i =1;i<needle.size();++i){
            while(j>0&&needle[i]!=needle[j]){
                j = next[j-1];//不相等就一直回溯到 相等的位置
            }
            if(needle[i]==needle[j])
                ++j;
            next[i] = j;
        }
    }
};
