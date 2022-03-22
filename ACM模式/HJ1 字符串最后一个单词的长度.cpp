/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-22 19:17:41
 */
// 描述
// 计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。（注：字符串末尾不以空格为结尾）
// 输入描述：
// 输入一行，代表要计算的字符串，非空，长度小于5000。
// 输出描述：
// 输出一个整数，表示输入字符串最后一个单词的长度。

#include<bits/stdc++.h>
using namespace std;

int getLastWord(string word){
    int sz = word.size();
    if(0==sz)
        return 0;
    int index = sz-1;
    for(;index>=0;--index){
        if(word[index]==' ')
            break;
    }
    return sz-index-1;
}

int main(){
    string word;
    while(getline(cin,word)){
        cout<<getLastWord(word)<<endl;
    }
    return 0;
}