/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-30 19:47:56
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-12-07 09:19:37
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <deque>
#include <queue>
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

// class Solution {
// private:
//     unordered_map<char,int> map;
//     unordered_map<char,int> map2;
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> ans;
//         int s_l = s.size(),p_l = p.size();
//         if(s_l<p_l)
//             return ans;
//         for(auto i:p){
//             if(!map.count(i))
//                 map[i] =1;
//             else
//                 map[i] += 1;
//         }
//         for(int i=0;i<=s.size()-p_l;++i){
//             map2 =map;
//             for(auto c:s.substr(i,p_l)){
//                 if(map2.count(c)){
//                     map2[c]-=1;
//                     if(map2[c]==0){
//                         map2.erase(c);
//                     }
//                 }
//             }
//             if(map2.empty())
//                 ans.push_back(i);
//         }
//         return ans;
//     }
// };

// int main(){
//     Solution solver;
//     string s1 = "cbaebabacd";
//     string s2 = "abc";
//     vector<int> ans = solver.findAnagrams(s1,s2);
//     for(auto i:ans){
//         cout<<" "<<i;
//     }
//     return 0;

// }

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int max_len = 0,length=0;
//         int n = s.size(), i=0,j=0;
//         // d当j小于n
//         while(j<n){
//             char temp=s[j];// 保存第j个字符
//             // for循环用于判断从i开始是否有元素与s[j]相等
//             for(int index=i;index<j;++index){
//                 //若有，记录为index，有的话就改变i的位置
//                 if(s[index]==temp){
//                     i=index+1;
//                     length = j-i;//求长度
//                     break;
//                 }
//             }
//             ++j;
//             ++length;
//             max_len = max(max_len,length);
//         }
//         return max_len;
//     }
// };

// class Solution {
// private:
//     unordered_map<char,int> map;
// public:
//     int lengthOfLongestSubstring(string s) {
//         int max_len=1;
//         int j=0;
//         if(s.size()==0)
//             return 0;
//         for(int i=0;i<s.size();++i){
//             while(j<s.size()&&!map.count(s[j])){
//                 map[s[j]]=1;
//                 ++j;
//             }
//             max_len=max(j-i,max_len);
//             if(j==s.size())
//                 break;
//             map.erase(s[i]);
//         }
//         return max_len;
//     }
// };

// int main(){
//      Solution solver;
//      string s ="aab";
//      cout << solver.lengthOfLongestSubstring(s) << endl;
// }

// class Solution {
// private:
//     stack<char> stk;
// public:
//     bool isValid(string s) {
//         int i =0;
//         while(i<s.size()){
//             if(s[i]=='['||s[i]=='('||s[i]=='{')
//                 stk.push(s[i]);
//             if(s[i]==')'){
//                 if(stk.empty())
//                     return false;
//                 if(s[i]==stk.top()){
//                     stk.pop();
//                 }
//                 if(s[i]!=stk.top())
//                     return false;
//             }
//             if(s[i]==']'){
//                 if(stk.empty())
//                     return false;
//                 if(s[i]==stk.top()){
//                     stk.pop();
//                 }
//                 if(s[i]!=stk.top())
//                     return false;
//             }
//             if(s[i]=='}'){
//                 if(stk.empty())
//                     return false;
//                 if(s[i]==stk.top()){
//                     stk.pop();
//                 }
//                 if(s[i]!=stk.top())
//                     return false;
//             }
//             ++i;
//         }
//         return true;
//     }
// };

// int main(){
//      Solution solver;
//      string s ="()";
//      cout << solver.isValid(s) << endl;
// }

// class Solution {
// public:
//     int evalRPN(vector<string> tokens) {
//         stack<int> stk;
//         for(int i=0;i<tokens.size();++i){
//              if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/")
//                 stk.push(str2num(tokens[i]));
//             else{
//                 int nums1 = stk.top();
//                 stk.pop();
//                 int nums2 = stk.top();
//                 stk.pop();
//                 int nums3;
//                 if(tokens[i]=="+")
//                     nums3 = nums1+nums2;
//                 else if(tokens[i]=="-")
//                     nums3 = nums2-nums1;
//                 else if(tokens[i]=="*")
//                     nums3 = nums2*nums1;
//                 else if(tokens[i]=="/")
//                     nums3 = nums2/nums1;
//                 stk.push(nums3);
//             }
//         }
//         return stk.top();
//     }

//     int  str2num(string s){
//         int num;
//         stringstream ss(s);
//         ss>>num;
//         return num;
//     }
// };

// int main(){
//      Solution solver;
//      cout << solver.evalRPN({"10","6","9","3","+","-11","*","/","*","17","+","5","+"}) << endl;
//      return 0;
// }
// class MyQueue
// { //单调队列（从大到小）
// public:
//     deque<int> que; // 使用deque来实现单调队列
//     // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
//     // 同时pop之前判断队列当前是否为空。
//     void pop(int value)
//     {
//         if (!que.empty() && value == que.front())
//         {
//             que.pop_front();
//         }
//     }
//     // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
//     // 这样就保持了队列里的数值是单调从大到小的了。
//     void push(int value)
//     {
//         while (!que.empty() && value > que.back())
//         {
//             que.pop_back();
//         }
//         que.push_back(value);
//     }
//     // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
//     int front()
//     {
//         return que.front();
//     }
// };
// class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int> nums, int k)
//     {
//         MyQueue que;
//         vector<int> result;
//         for (int i = 0; i < k; i++)
//         { // 先将前k的元素放进队列
//             que.push(nums[i]);
//         }
//         result.push_back(que.front()); // result 记录前k的元素的最大值
//         for (int i = k; i < nums.size(); i++)
//         {
//             que.pop(nums[i - k]);          // 滑动窗口移除最前面元素
//             que.push(nums[i]);             // 滑动窗口前加入最后面的元素
//             result.push_back(que.front()); // 记录对应的最大值
//         }
//         return result;
//     }
// };

// int main()
// {
//     Solution solver;
//     vector<int> vec;
//     vec = solver.maxSlidingWindow({1, 3, -1, -3, 5, 3, 6, 7}, 3);
//     for (auto i : vec)
//         cout << i << endl;
//     return 0;
// }


class Solution {
public:
    vector<int> topKFrequent(vector<int> nums, int k) {
        unordered_map<int,int> map;
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(auto i:nums){
            if(map.count(i))
                map[i]++;
            else
                map[i] =1;
        }
        for(auto v:map){
            pair<int,int> p(v.first,v.second);
            pq.push(p);
        }
        for(int i=0;i<k;++i){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;

    }
};


int main(){
      Solution solver;
      vector<int> ans;
      ans = solver.topKFrequent({-1,-1},1);
      for(auto i:ans)
        cout<<i<<endl;
}