/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-31 15:45:45
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-31 16:00:28
 */
// 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
// 比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
// 输入: s = "abcdefg", k = 2
// 输出: "cdefgab"

// 反转三次字符串
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverseString(s,0,s.size()-1);
        reverseString(s,0,s.size()-n-1);
        reverseString(s,s.size()-n,s.size()-1);
        return s;
    }

    void reverseString(string& s,int start,int end){
        for(;start<end;++start,--end){
            char temp = s[end];
            s[end] = s[start];
            s[start] = temp;
        }
    }
};


// 存前k个字符串，并删除前k个字符串，把二者相加
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string ans;
        for(int i=0;i<n;++i){
            ans+=s[0];
            s.erase(s.begin());
        }   
        return s+ans;
    }
};