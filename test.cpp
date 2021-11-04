/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-30 19:47:56
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-11-03 21:46:40
 */
#include <iostream>
#include <string>
#include<vector>
#include<unordered_map>
using namespace std;

// class Solution {
// public:
//     string reverseWords(string s) {
//         // 删除多余空格
//         deleteSpace(s);
//         cout<<s<<endl;
//         // 反转整个字符串
//         reverseString(s,0,s.size()-1);
//         cout<<s<<endl;
//         // 反转单词
//         for(int i=0;i<s.size();){
//             int j=i;
//             while(j<s.size()&&s[j]!=' ')
//                 ++j;
//             reverseString(s,i,j-1);
//             i =j+1;
//         }
//         return s;

//     }
//     void deleteSpace(string& s){
//         for(int i=0;i<s.size()-1;){
//             if(s[i]==' '&&s[i]==s[i+1])
//                 s.erase(s.begin()+i);
//             else{
//                 ++i;
//             }
//         }
//         if(s[0]==' ')
//             s.erase(s.begin());
//         if(s[s.size()-1]==' ')
//             s.erase(s.begin()+s.size()-1);
//     }
//     void reverseString(string& s,int start,int end){
//         for(;start<end;++start,--end){
//             char temp = s[end];
//             s[end] = s[start];
//             s[start] = temp;
//         }
//     }

// };

// int main(){
//     Solution solver;
//     string str = "a good   example";
//     string new_s = solver.reverseWords(str);
//     cout<<new_s<<endl;
//     return 0;
// }

// class Solution {
// public:
//     bool repeatedSubstringPattern(string s) {
//         int n = s.size();
//         for(int i=n/2;i!=0;i--){
//             if(n%i)
//                 continue;
//             string temp;
//             string s1 = s.substr(0,i);
//             for(int j=n/i;j!=0;--j)
//                 temp+=s1;
//             if(temp==s) 
//                 return true;
//         }
//         return false;
       
//     }
// };

// int main(){
//     Solution solver;
//     string str = "b";
//     // int i= solver.repeatedSubstringPattern(str);
//     cout<< solver.repeatedSubstringPattern(str)<<endl;
//     return 0;
// }


// class Solution {
// private:
//     string str = "AEIOUaeiou";
// public:
//     string reverseVowels(string& s) {
//         int i=0,j=s.size()-1;
//         while(i<j){
//             while(i<j&&!isYuanYin(s[i]))
//                 ++i;
//             if(i==j)
//                 break;
//             while(i<j&&!isYuanYin(s[j]))
//                 --j;
//             if(i==j)
//                 break;                
//             if(isYuanYin(s[i])&&isYuanYin(s[j])){
//             char temp;
//             temp = s[j];
//             s[j] = s[i];
//             s[i] = temp;
//             ++i;
//             --j;
//             }
//         }
//         return s;
//     }
//     bool isYuanYin(char c){
//         for(auto i:str){
//             if(i==c)
//                 return true;
//         }
//         return false;
//     }
// };

// int main(){
//     Solution solver;
//     string str = "leetcode";
//     solver.reverseVowels(str);
//     cout<< str<<endl;
//     return 0;
// }

class Solution {
private:
    unordered_map<char,int> map;
    unordered_map<char,int> map2;
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int s_l = s.size(),p_l = p.size();
        if(s_l<p_l)
            return ans;
        for(auto i:p){
            if(!map.count(i))
                map[i] =1;
            else
                map[i] += 1;
        }
        for(int i=0;i<=s.size()-p_l;++i){
            map2 =map;
            for(auto c:s.substr(i,p_l)){
                if(map2.count(c)){
                    map2[c]-=1;
                    if(map2[c]==0){
                        map2.erase(c);
                    }
                }
            }
            if(map2.empty())
                ans.push_back(i);
        }
        return ans;
    }
};

int main(){
    Solution solver;
    string s1 = "cbaebabacd";
    string s2 = "abc";
    vector<int> ans = solver.findAnagrams(s1,s2);
    for(auto i:ans){
        cout<<" "<<i;
    }
    return 0;


    
}