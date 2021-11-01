/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-28 21:33:00
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-28 21:33:00
 */
// 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
// 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size()-1;
        int i =0;
        while(i<n){
            char temp = s[n];
            s[n] = s[i];
            s[i] = temp;
            ++i;
            --n;
        }
        return;
    }
};