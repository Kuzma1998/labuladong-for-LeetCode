/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-31 16:01:47
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-11-03 20:40:05
 */
// 给你一个字符串 s ，逐个翻转字符串中的所有 单词 。
// 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
// 请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。
// 说明：
// 输入字符串 s 可以在前面、后面或者单词间包含多余的空格。
// 翻转后单词间应当仅用一个空格分隔。
// 翻转后的字符串中不应包含额外的空格。
// 输入：s = "  hello world  "
// 输出："world hello"
// 解释：输入字符串可以在前面或者后面包含多余的空格，但是翻转后的字符不能包括。


class Solution {
public:
    string reverseWords(string s) {
        // 删除多余空格
        deleteSpace(s);
        // cout<<s<<endl;
        // 反转整个字符串
        reverseString(s,0,s.size()-1);
        // cout<<s<<endl;
        // 反转单词
        for(int i=0;i<s.size();){
            int j=i;
            while(j<s.size()&&s[j]!=' ')
                ++j;
            reverseString(s,i,j-1);
            i =j+1;
        }
        return s;

    }
    void deleteSpace(string& s){
        for(int i=0;i<s.size()-1;){
            if(s[i]==' '&&s[i]==s[i+1])
                s.erase(s.begin()+i);
            else
                ++i;
        }
        if(s[0]==' ')
            s.erase(s.begin());
        if(s[s.size()-1]==' ')
            s.erase(s.begin()+(s.size()-1));
    }
    void reverseString(string& s,int start,int end){
        for(;start<end;++start,--end){
            char temp = s[end];
            s[end] = s[start];
            s[start] = temp;
        }
    }

};

// 双指针移除空格
void removeExtraSpaces(string& s) {
    int slowIndex = 0, fastIndex = 0; // 定义快指针，慢指针
    // 去掉字符串前面的空格
    while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
        fastIndex++;
    }
    for (; fastIndex < s.size(); fastIndex++) {
        // 去掉字符串中间部分的冗余空格
        if (fastIndex - 1 > 0
                && s[fastIndex - 1] == s[fastIndex]
                && s[fastIndex] == ' ') {
            continue;
        } else {
            s[slowIndex++] = s[fastIndex];
        }
    }
    if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') { // 去掉字符串末尾的空格
        s.resize(slowIndex - 1);
    } else {
        s.resize(slowIndex); // 重新设置字符串大小
    }
}