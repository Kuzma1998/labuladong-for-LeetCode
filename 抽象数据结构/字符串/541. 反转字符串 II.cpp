/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-31 11:22:00
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-31 15:44:55
 */

// 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
// 如果剩余字符少于 k 个，则将剩余字符全部反转。
// 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
// 输入：s = "abcdefg", k = 2
// 输出："bacdfeg"
class Solution {
public:
    string reverseStr(string s, int k) {
        int n =s.size();
        for(int i=0;i<n;i+=2*k){
            if(i+k>n){
                reverse(s,i,n-1);
                break;
            }
                reverse(s,i,i+k-1);
        }
        return s;
    }

    void reverse(string& s,int start,int end){
        for(;start<end;++start,--end){
            char temp = s[end];
            s[end] = s[start];
            s[start] = temp;
        }
    }
};