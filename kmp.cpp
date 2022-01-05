#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
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
    void getNext(int* next,const string& s){
        int i;// 后缀起始位置
        int j=0;// 前缀起始位置，也代表以i结尾的字符串的最大相等前后缀的长度
        next[0] =j;
        for(i =1;i<s.size();++i){
            while(j>0&&s[i]!=s[j]){
                j = next[j-1];//不相等就一直回溯到 相等的位置
            }
            if(s[i]==s[j])
                ++j;
            next[i] = j;
        }
    }
};

int main(){
    Solution s;
    string s1 = "aabaafaab";
    string s2 = "aabaaf";
    cout<<s.strStr(s1,s2)<<endl;
}