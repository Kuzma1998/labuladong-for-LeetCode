/*
 * @Descripttion:
 * @version:
 * @Author: Li Jiaxin
 * @Date: 2021-10-30 19:47:56
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2022-02-26 20:52:03
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <numeric>
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

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int> nums, int k) {
//         unordered_map<int,int> map;
//         priority_queue<pair<int,int>> pq;
//         vector<int> ans;
//         for(auto i:nums){
//             if(map.count(i))
//                 map[i]++;
//             else
//                 map[i] =1;
//         }
//         for(auto v:map){
//             pair<int,int> p(v.first,v.second);
//             pq.push(p);
//         }
//         for(int i=0;i<k;++i){
//             ans.push_back(pq.top().first);
//             pq.pop();
//         }
//         return ans;

//     }
// };

// int main(){
//       Solution solver;
//       vector<int> ans;
//       ans = solver.topKFrequent({-1,-1},1);
//       for(auto i:ans)
//         cout<<i<<endl;
// }

// class Solution
// {
// private:
//     vector<vector<int>> res;

// public:
//     vector<vector<int>> permuteUnique(vector<int> &nums)
//     {
//         vector<int> road(0, nums.size());
//         vector<bool> used(nums.size(),0);
//         sort(nums.begin(), nums.end());
//         backtrack(road, nums, used);
//         return res;
//     }
//     // 回溯
//     void backtrack(vector<int> &road, vector<int> &nums, vector<bool> &used)
//     {
//         if (nums.size() == road.siz())
//         {
//             res.push_back(road);
//             return;
//         }

//         for (int i = 0; i < nums.size(); ++i)
//         {
//             if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
//                 continue;
//             if (used[i] == false)
//             {
//                 used[i] = true;
//                 int pp = nums[i];
//                 road.push_back(pp);
//                 backtrack(road, nums, used);
//                 road.pop_back();
//                 used[i] = false;
//             }
//         }
//     }
// };

// int main()
// {
//     Solution solver;
//     vector<int> input{1, 1, 3};
//     // vector<int> b(5,4);
//     // for(auto i:b)
//     //     cout<<i<<endl;

//     vector<vector<int>> ans = solver.permuteUnique(input);
//     for (auto i : ans)
//     {
//         for (auto j : i)
//         {
//             cout << j << " ";
//         }
//         cout << endl;
//     }
// }

// class Solution {
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int sum = accumulate(nums.begin(),nums.end(),0);
//         if(sum%k)
//             return false;
//         int target = sum/k;
//         vector<bool> used(nums.size(),false);
//         // sort(nums.begin(),nums.end(),[](int a,int b){return a>b;});
//         return trackback(nums,k,target,0,0,used);
//     }
//     // 路径是bucket，选择是nums
//     bool trackback(vector<int>& nums,int k,int target,int bucket,int index,vector<bool>& used){
//         if(k==0)
//             return true;
//         if(bucket==target)// 清空bucket，从0开始继续装
//             return trackback(nums,k-1,target,0,0,used);
//         // 遍历数组，看哪个能插入桶里面
//         for(int i=index;i<nums.size();++i){
//             if(used[i])
//                 continue;
//             if(nums[i]+bucket>target)
//                 continue;
//                 // 进行选择
//             used[i] = true;
//             bucket += nums[i];
//             if(trackback(nums,k,target,bucket,i+1,used))// 如果这条路径通了，直接返回true
//                 return true;
//             used[i] = false;//此次选择不行，撤销
//             bucket -= nums[i];
//         }
//         return false;
//     }
// };

// class Solution
// {
// public:
//     bool backtrack(vector<vector<char>> &board, int i, int j)
//     {
//         if (j == 9)
//             return backtrack(board, i + 1, 0);
//         if (i == 9)
//         {
//             return true;
//         }
//         if (board[i][j] != '.')
//             return backtrack(board, i, j + 1);

//         for (char num = '1'; num <= '9'; ++num)
//         {
//             if (!isValid(board, i, j, num))
//                 continue;
//             board[i][j] = num;
//             if (backtrack(board, i, j + 1))
//                 return true;
//             board[i][j] = '.';

//         }
//         return false;
//     }
//     bool isValid(vector<vector<char>> &board, int i, int j, char num)
//     {
//         // for (int row = 0; row < 9; ++row)
//         // {
//         //     if (board[row][j] == num)
//         //         return false;
//         // }
//         // for (int col = 0; col < 9; ++col)
//         // {
//         //     if (board[i][col] == '.')
//         //         return false;
//         // }
//         // int sr = (i / 3) * 3;
//         // int sc = (j / 3) * 3;
//         // for (int subrow = sr; subrow < sr + 3; ++subrow)
//         // {
//         //     for (int subcol = sc; subcol < sc + 3; ++subcol)
//         //     {
//         //         if (board[subrow][subcol] == num)
//         //             return false;
//         //     }
//         // }
//         // return true;
//             for (int r = 0; r < 9; r++) {
//             // 判断行是否存在重复
//             if (board[i][r] == num) return false;
//             // 判断列是否存在重复
//             if (board[r][j] == num) return false;
//             // 判断 3 x 3 方框是否存在重复
//             if (board[(i/3)*3 + r/3][(j/3)*3 + r%3] == num)
//                 return false;
//         }
//             return true;
//     }
//     void solveSudoku(vector<vector<char>> &board)
//     {
//         backtrack(board, 0, 0);
//     }
// };

// int main()
// {
//     Solution solver;
//     vector<vector<char>> v{
//         {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
//         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
//     solver.solveSudoku(v);
//     for (auto i : v)
//     {
//         for (auto j : i)
//             cout << j << " ";
//         cout << endl;
//     }
// }

// class Solution {
// private:
//     vector<string> ans;
// public:
//     vector<string> generateParenthesis(int n) {
//         string path = "";
//         vector<bool> used(2*n,false);
//         string choice(n,'(');
//         choice += string(n,')');
//         backtrack(path,used,choice);
//         return ans;
//     }
//     void backtrack(string& path,vector<bool>& used,string& choice){
//         if(path.size()==used.size()){
//             ans.push_back(path);
//             return;
//         }
//         for(int i=0;i<choice.size();++i){

//             if (i > 0 && choice[i] == choice[i - 1] && used[i - 1] == false) {
//                 continue;
//             }
//             if(used[i])
//                 continue;
//             if(!isValid(path,choice[i]))
//                 continue;
//             path += choice[i];
//             used[i] = true;
//             backtrack(path,used,choice);
//             path.pop_back();
//             used[i] = false;
//         }
//         return;
//     }
//     bool isValid(string str,char c){
//         str += c;
//         int count1=0;
//         int count2=0;
//         for(auto i:str){
//             if(i=='(')
//                 ++count1;
//             else
//                 ++count2;
//         }
//         if(count1>=count2)
//             return true;
//         return false;
//     }
// };

// int main(){
//     // Solution solver;
//     // vector<string> ans = solver.generateParenthesis(3);
//     // for(auto i :ans)
//     //     cout<<i<<endl;
//     int neighbors[6][3];
//     Array<int,2> neighbors(3,6,fortranArray);
// }
// class Solution {
// private:
//     vector<string> ans;
//     string path="";
//     unordered_map<char,string> map;
// public:
//     vector<string> letterCombinations(string digits) {
//         // vector<bool> used(digits.szize(),false);
//         map['2'] = "abc";
//         map['3'] = "def";
//         map['4'] = "ghi";
//         map['5'] = "jkl";
//         map['6'] = "mno";
//         map['7'] = "pqrs";
//         map['8'] = "tuv";
//         map['9'] = "wxzy";
//         backtrack(digits,0);
//         return ans;
//     }

//     void backtrack(string& digits,int start){
//         if(start==digits.size()){
//             ans.push_back(path);
//             return;
//         }
//         if(!isValid(digits[start]))
//             backtrack(digits,start+1);
//         for(int i=0;i<map[digits[start]].size();++i){
//             path += map[digits[start]][i];
//             backtrack(digits,start+1);
//             path.pop_back();
//         }
//     }
//     bool isValid(char c){
//         if(!map.count(c))
//             return false;
//         return true;
//     }
// };

// int main(){
//     Solution solution;
//     vector<string> ans = solution.letterCombinations("#23");
//     for(auto i:ans)
//         cout<<i<<endl;
// }

// class Solution {
// private:
//     vector<vector<string>> ans;
//     vector<string> path;
// public:
//     vector<vector<string>> partition(string s) {
//         backtrack(s,0);
//         return ans;
//     }

//     void backtrack(string s,int index){
//         if(index>=s.size()){
//             ans.push_back(path);
//             return;
//         }
//         for(int i=index;i<s.size();++i){
//             if(isHuiwen(s,index,i)){
//                 path.push_back(s.substr(index,i-index+1));
//             }
//             else{
//                 continue;
//             }
//             backtrack(s,i+1);
//             path.pop_back();
//         }
//     }
//     bool isHuiwen(string s,int start,int end){
//         for(;start<=end;++start,--end){
//             if(s[start]!=s[end])
//                 return false;
//         }
//         return true;
//     }
// };

// int main(){
//     Solution solver;
//     string s = "aab";
//     vector<vector<string>> ans = solver.partition(s);
//     for(auto i :ans){
//         for(auto j:i){
//             cout<<j<<endl;
//         }
//     }

// }

// class Solution
// {
// private:
//     vector<string> ans;
//     //  string path;
// public:
//     vector<string> restoreIpAddresses(string s)
//     {
//         // int size =s.size();
//         backtrack(s, 1, 0);
//         return ans;
//     }

//     void backtrack(string &s, int index, int num)
//     {
//         if (num == 3)
//         {
//             if (isValid(s, index - 1))
//                 ans.push_back(s);
//             return;
//         }
//         for (auto i = index; i < s.size() && i < index + 3; ++i)
//         {
//             if (can_insert(s, i))
//             {
//                 s.insert(i, ".");
//             }
//             else
//             {
//                 continue;
//             }
//             num++;
//             backtrack(s, i + 2, num);
//             s.erase(i, 1);
//             --num;
//         }
//     }
//     bool can_insert(string &s, int start)
//     {
//         int i = 3;
//         int j = start - 1;
//         while (j >= 0 && i)
//         {
//             if (s[j] == '.')
//             {
//                 break;
//             }
//             --i;
//             --j;
//         }
//         if (j < 0 && s.substr(0, (3 - i)) <= string("255"))
//             return true;
//         else if (j < 0 && s.substr(0, (3 - i)) >= string("255"))
//             return false;
//         if (s[j] != '.')
//             return false;
//         else if (s.substr(j + 1, (3 - i)).size()<3)
//             return true;
//         else if(s.substr(j + 1, (3 - i))[0]!='0'&&s.substr(j + 1, (3 - i))<=string("255"))
//             return true;
//         else
//             return false;
//     }
//     bool isValid(string &s, int pos)
//     {
//         if (s.substr(pos).size() > 3)
//             return false;
//         else if(s.substr(pos).size()==1)
//             return true;
//         else if (s.substr(pos)[0]=='0')
//             return false;
//         else if(s.substr(pos).size()<3)
//             return true;
//         else if (s.substr(pos)<= string("255"))
//             return true;
//         else
//             return false; 
  
//     }
// };

// bool isValid(string &s, int pos)
// {
//     if (s.substr(pos).size() > 3)
//         return false;
//     else if (s.substr(pos) > string("255"))
//         return false;
//     return true;
// }

// int main()
// {
//     Solution solver;
//     string s = "25525511135";
//     // cout << s.size() << endl;
//     // cout << isValid(s, 10);

//     // cout<<s.substr(2);
//     vector<string> ans = solver.restoreIpAddresses(s);
//     for(auto i:ans){
//         cout<<i<<endl;
//     }
// }


// class Solution {
// private:
//     vector<vector<int>> ans;
//     vector<int> path;
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<bool> used(nums.size(),false);
//         backtrack(nums,0,used);
//         return ans;
//     }
//     void backtrack(vector<int>& nums,int index,vector<bool>& used){
//         ans.push_back(path);
//         if(index==nums.size())
//             return;
//         for(int i=index;i<nums.size();++i){
//             if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false)
//                 continue;
//             if(used[i])
//                 continue;
//             path.push_back(nums[i]);
//             used[i] = true;
//             backtrack(nums,i+1,used);
//             used[i] = false;
//             path.pop_back();
//         }
//     }
// };

// int main(){
//     Solution slover;
//     vector<int> nums{1,2,2};
//     vector<vector<int>> ans = slover.subsetsWithDup(nums);
//     for(auto i:ans){
//         for(auto j:i){
//             cout<< j<<" "; //
//         }
//         cout<< endl;
//     }
// }

#include<set>
// class Solution {
// private:
//     vector<vector<int>> ans;
//     vector<int> path;
//     set<int> s;
// public:
//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         vector<bool> used(nums.size(),false);
//         backtrack(nums,0,used);
//         return ans;
//     }
//     void backtrack(vector<int>& nums,int index, vector<bool>& used){
//         if(path.size()>=2){
//             ans.push_back(path);
//         }
//         if(index==nums.size())
//             return;
//         for(int i=index;i<nums.size();++i){
//             if(path.size()==0&&s.find(nums[i])==s.end()){
//                 used[i] = true;
//                 s.insert(nums[i]);
//                 path.push_back(nums[i]);
//                 backtrack(nums,i+1,used);
//                 path.pop_back();
//                 used[i] = false;
//             }
//             if(i>0&& nums[i] == nums[i-1] && used[i - 1] == false)
//                 continue;
//             if(path.size()!=0&&path[path.size()-1]<=nums[i]){
//                 used[i] = true;
//                 path.push_back(nums[i]);
//                 backtrack(nums,i+1,used);
//                 path.pop_back();
//                 used[i] = false;
//             }else{continue;}
//         }
//     }
// };

// int main(){
//     Solution solver;
//     vector<int> nums{-100,-100,0,0,0,100,100,0,0};
//     vector<vector<int>> ans = solver.findSubsequences(nums);
//     for(auto i:ans){
//     for(auto j:i){
//         cout<< j<<" "; //
//     }
//     cout<< endl;
// }
// }


// class Solution {
// private:
//     vector<vector<int>> ans;
//     vector<int> path;
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<bool> used(nums.size(),false);
//         backtrack(nums,0,used);
//         return ans;
//     }
//     void backtrack(vector<int>& nums,int index,vector<bool>& used){
//         ans.push_back(path);
//         if(index==nums.size())
//             return;
//         for(int i=index;i<nums.size();++i){
//             if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false)  // 树的层剪枝，而树的深度可以重复
//                 continue;
//             if(used[i])
//                 continue;
//             path.push_back(nums[i]);
//             used[i] = true;
//             backtrack(nums,i+1,used);
//             used[i] = false;
//             path.pop_back();
//         }
//     }
// };


// int main(){
//     Solution solver; 
//     vector<int> nums{1,2,2}; //
//     vector<vector<int>> ans = solver.subsetsWithDup(nums);
//     for(auto i:ans){
//         for(auto j:i){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
// }


// class Solution {
// private:
//     vector<vector<int>> ans;
//     vector<int> path;
// public:
//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         backtrack(nums,0);
//         return ans;
//     }
//     void backtrack(vector<int>& nums,int index){
//         if(path.size()>=2){
//             ans.push_back(path);
//         }
//         if(index==nums.size()){return;}
//         set<int> s;
//         for(int i=index;i<nums.size();++i){
//             //跳过的条件,不递增或者该层去重
//             if(!path.empty()&&path.back()>nums[i]||s.find(nums[i])!=s.end())
//                 continue;
//             s.insert(nums[i]);
//             path.push_back(nums[i]);
//             backtrack(nums,i+1);
//             path.pop_back();
//         }
//     }
// };


// int main(){
//     Solution solver;
//     vector<int> nums{4,6,7,7};
//    vector<vector<int>> ans = solver.findSubsequences(nums);
//     for(auto i:ans){
//         for(auto j:i)
//             cout<<j<<" ";
//         cout<<endl;
//     }
// }

// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int s =0;
//         int e =1;
//         int steps = 0;
//         while(e<nums.size()){
//             int pos = 0;
//             for(int i=0;i<e;++i){
//                 pos = max(pos,nums[i]+i);
//             }
//             s = e;
//             e = pos+1;
//             steps++;
//         }
//         return steps;
//     }
// };

// int main(){
//     Solution solver;
//     vector<int> nums{7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
//     cout<<solver.jump(nums);
// }

// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int count =-1;
//         for(int i=0;i<gas.size();++i){
//             if(gas[i]<cost[i])
//                 continue;
//             int sum = 0;
//             int times = gas.size();
//             count = i;
//             int j = i;
//             while(times--){
//                 if(j==gas.size())
//                     j=0;
//                 sum += gas[j]-cost[j];
//                 if(sum<0)
//                     break;
//                 if(j<gas.size())
//                     j++;
//             }
//             if(sum>=0)
//                 return count;
//         }
//         return -1;
//     }
// };

// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         vector<int> dp(ratings.size(),1);
//         int i=0;
//         for(i=1;i<ratings.size();++i){
//             //右大于左，必然右边比左边大1;
//             if(ratings[i]>ratings[i-1])
//                 dp[i] = dp[i-1]+1;
//         }
//         for(int j=ratings.size()-2;j>=0;--j){
//             if(ratings[j]>ratings[j+1]){
//                 dp[j] = max(dp[j],dp[j+1]+1);
//             }
//         }
//         return accumulate(dp.begin(),dp.end(),0);
//     }
// };


// int main(){
//     vector<int> ratings = {1,0,2};
//     Solution solver;
//     cout<<solver.candy(ratings);
// }


// class MedianFinder {
// public:
//     MedianFinder() {

//     }
//     void addNum(int num) {
//         q.push(num);
//         ++size;
//     }
//     double findMedian() {
//         int sz = q.size()/2;
//         if(q.size()%2){
//             while(sz--){
//                 v.push_back(q.top());
//                 q.pop();
//             }
//             mean = q.top();
//             for(auto i:v){
//                 q.push(i);
//             }
//             v.clear();
//             return mean;
//         }else{
//             while(sz--){
//                 v.push_back(q.top());
//                 q.pop();
//             }
//             mean = (q.top()+v.back())/2;
//             for(auto i:v){
//                 q.push(i);
//             }
//             v.clear();
//             return mean;
//         }
//     }
// private:
//     priority_queue<double,vector<double>,greater<double>> q;
//     int size = 0;
//     vector<double> v;
//     double mean = 0.0;

// };

// int main(){
//     MedianFinder m;
//     m.addNum(1);
//     cout<<m.findMedian()<<endl;
//     m.addNum(2);
//     cout<<m.findMedian()<<endl;
// }


// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> ans(amount+1,0);//备忘录
//         return dp(amount,coins,ans);
//     }
//     // dp函数功能就是金额为n的情况下，最少需要多少张钞票
//     int dp(int n,vector<int>& coins,vector<int>& ans){
//         // cout<<"amount: "<<""<<n<<" nums: "<<res<<endl;
//         if (n==0) // 初始状态
//             return 0;
//         if(n<0) // 初始状态
//             return -1;
//         if(ans[n]!=0) // 备忘录不是初始状态
//             return ans[n];
//         int res = INT_MAX;
//         for(int coin :coins){//选择条件
//             int subproblem = dp(n-coin,coins,ans);
//             cout<<"amount: "<<""<<n-coin<<" nums: "<<subproblem<<endl;
//             if(subproblem==-1)
//                 continue;
//             res = min(res,1+subproblem);//状态转移
         
//         }
//         // cout<<"amount: "<<""<<n<<" nums: "<<res<<endl;
//         ans[n] = (res==INT_MAX)?-1:res;//更新ans
//         return ans[n];
//     }
// };

// int main(){
//     Solution s;
//     vector<int> coins{1,1,5};
//     int amount =11;
//     s.coinChange(coins, amount);
// }


// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         vector<bool> dp(s.size()+1,false);
//         dp[0] = true;
//         for(int i=0;i<s.size();){
//             string temp;
//             for(int j=0;j<wordDict.size();++j){
//                 int sz = wordDict[j].size();
//                 temp = s.substr(i,sz);
//                 if(temp==wordDict[j]){
//                     dp[i+wordDict[j].size()] = dp[i];
//                     break;
//                 }
//             }
//             i+=temp.size();
//             // i+=wordDict[j].size();
//         }
//         return dp[s.size()];
//     }
// };

// int main(){
//     Solution solver;
//     string s = "applepenapple";
//     vector<string> wordDict{"apple","pen"};
//     cout<<solver.wordBreak(s,wordDict)<<endl;
// }


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         return dp(false,0,prices,0);
//     }
//     int dp(bool has,int count,vector<int>& prices,int index){
//         if((count>=2&&has==false)||index>=prices.size())
//             return 0;
//         if(has){
//             return max(dp(true,count,prices,index+1),
//             dp(false,count+1,prices,index+1)+prices[index]);
//         }else{
//             return max(dp(false,count,prices,index+1),
//             dp(true,count,prices,index+1)-prices[index]);
//         }
//     }
// };

// int main()
// {
//     Solution solver;
//     vector<int> prices = {397,6621,4997,7506,8918,1662,9187,3278,3890,514,18,9305,93,5508,3031,2692,6019,1134,1691,4949,5071,799,8953,7882,4273,302,6753,4657,8368,3942,1982,5117,563,3332,2623,9482,4994,8163,9112,5236,5029,5483,4542,1474,991,3925,4166,3362,5059,5857,4663,6482,3008,3616,4365,3634,270,1118,8291,4990,1413,273,107,1976,9957,9083,7810,4952,7246,3275,6540,2275,8758,7434,3750,6101,1359,4268,5815,2771,126,478,9253,9486,446,3618,3120,7068,1089,1411,2058,2502,8037,2165,830,7994,1248,4993,9298,4846,8268,2191,3474,3378,9625,7224,9479,985,1492,1646,3756,7970,8476,3009,7457,8922,2980,577,2342,4069,8341,4400,2923,2730,2917,105,724,518,5098,6375,5364,3366,8566,8838,3096,8191,2414,2575,5528,259,573,5636,4581,9049,4998,2038,4323,7978,8968,6665,8399,7309,7417,1322,6391,335,1427,7115,853,2878,9842,2569,2596,4760,7760,5693,9304,6526,8268,4832,6785,5194,6821,1367,4243,1819,9757,4919,6149,8725,7936,4548,2386,5354,2222,8777,2041,1,2245,9246,2879,8439,1815,5476,3200,5927,7521,2504,2454,5789,3688,9239,7335,6861,6958,7931,8680,3068,2850,1181,1793,7138,2081,532,2492,4303,5661,885,657,4258,131,9888,9050,1947,1716,2250,4226,9237,1106,6680,1379,1146,2272,8714,8008,9230,6645,3040,2298,5847,4222,444,2986,2655,7328,1830,6959,9341,2716,3968,9952,2847,3856,9002,1146,5573,1252,5373,1162,8710,2053,2541,9856,677,1256,4216,9908,4253,3609,8558,6453,4183,5354,9439,6838,2682,7621,149,8376,337,4117,8328,9537,4326,7330,683,9899,4934,2408,7413,9996,814,9955,9852,1491,7563,421,7751,1816,4030,2662,8269,8213,8016,4060,5051,7051,1682,5201,5427,8371,5670,3755,7908,9996,7437,4944,9895,2371,7352,3661,2367,4518,3616,8571,6010,1179,5344,113,9347,9374,2775,3969,3939,792,4381,8991,7843,2415,544,3270,787,6214,3377,8695,6211,814,9991,2458,9537,7344,6119,1904,8214,6087,6827,4224,7266,2172,690,2966,7898,3465,3287,1838,609,7668,829,8452,84,7725,8074,871,3939,7803,5918,6502,4969,5910,5313,4506,9606,1432,2762,7820,3872,9590,8397,1138,8114,9087,456,6012,8904,3743,7850,9514,7764,5031,4318,7848,9108,8745,5071,9400,2900,7341,5902,7870,3251,7567,2376,9209,9000,1491,7030,2872,7433,1779,362,5547,7218,7171,7911,2474,914,2114,8340,8678,3497,2659,2878,2606,7756,7949,2006,656,5291,4260,8526,4894,1828,7255,456,7180,8746,3838,6404,6179,5617,3118,8078,9187,289,5989,1661,1204,8103,2,6234,7953,9013,5465,559,6769,9766,2565,7425,1409,3177,2304,6304,5005,9559,6760,2185,4657,598,8589,836,2567,1708,5266,1754,8349,1255,9767,5905,5711,9769,8492,3664,5134,3957,575,1903,3723,3140,5681,5133,6317,4337,7789,7675,3896,4549,6212,8553,1499,1154,5741,418,9214,1007,2172,7563,8614,8291,3469,677,4413,1961,4341,9547,5918,4916,7803,9641,4408,3484,1126,7078,7821,8915,1105,8069,9816,7317,2974,1315,8471,8715,1733,7685,6074,257,5249,4688,8549,5070,5366,2962,7031,6059,8861,9301,7328,6664,5294,8088,6500,6421,1518,4321,5336,2623,8742,1505,9941,1716,2820,4764,6783,906,2450,2857,7515,4051,7546,2416,9121,9264,1730,6152,1675,592,1805,9003,7256,7099,3444,3757,9872,4962,4430,1561,7586,3173,3066,3879,1241,2238,8643,8025,3144,7445,882,7012,1496,4780,9428,617,396,1159,3121,2072,1751,4926,7427,5359,8378,871,5468,8250,5834,9899,9811,9772,9424,2877,3651,7017,5116,8646,5042,4612,6092,2277,1624,7588,3409,1053,8206,3806,8564,7679,2230,6667,8958,6009,2026,7336,6881,3847,5586,9067,98,1750,8839,9522,4627,8842,2891,6095,7488,7934,708,3580,6563,8684,7521,9972,6089,2079,130,4653,9758,2360,1320,8716,8370,9699,6052,1603,3546,7991,670,3644,6093,9509,9518,7072,4703,2409,3168,2191,6695,228,2124,3258,5264,9645,9583,1354,1724,9713,2359,1482,8426,3680,6551,3148,9731,8955,4751,9629,6946,5421,9625,9391,1282,5495,6464,5985,4256,5984,4528,952,6212,6652,562,1476,6297,145,9182,8021,6211,1542,5856,4637,1574,2407,7785,1305,1362,2536,934,4661,4309,559,4052,1943,2406,516,4280,6662,2852,8808,7614,9064,1813,4529,6893,8110,4674,2427,2484,7237,3969,8340,1874,5543,7099,6011,3200,8461,8547,486,9474,9208,7397,9879,7503,9803,6747,1783,6466,9600,6944,432,8664,8757,4961,1909,6867,5988,4337,5703,3225,4658,4043,1452,6554,1142,7463,9754,5956,2363,241,1782,7923,7638,1661,5427,3794,8409,7210,260,8009,4154,692,3025,9263,2006,4935,2483,7994,5624,8186,7571,282,8582,9023,6836,6076,6487,6591,2032,8850,3184,3815,3125,7174,5476,8552,968,3885,2115,7580,8246,2621,4625,1272,1885,6631,6207,4368,4625,8183,2554,8548,8465,1136,7572,1654,7213,411,4597,5597,5613,7781,5764,8738,1307,7593,7291,8628,7830,9406,6208,6077,2027,833,7349,3912,7464,9908,4632,8441,8091,7187,6990,2908,4675,914,4562,8240,1325,9159,190,6938,3292,5954,2028,4600,9899,9319,3228,7730,5077,9436,159,7105,6622,7508,7369,4086,3768,2002,8880,8211,5541,2222,1119,216,3136,5682,4809,813,1193,4999,4103,4486,7305,6131,9086,7205,5451,2314,1287,528,8102,1446,3985,4724,5306,1355,5163,9074,9709,4043,7285,5250,2617,4756,1818,2105,6790,6627,2918,7984,7978,7021,2470,1636,3152,7908,8841,4955,222,6480,5484,4676,7926,5821,9401,3232,7176,916,8658,3237,1311,5943,8487,3928,7051,306,6033,3842,3285,8951,1826,7616,2324,648,9252,5476,8556,4445,6784};
//     cout<<solver.maxProfit(prices);
// }

// int Min = INT_MAX;

// void dfs(int* nums, int count, int deep){
//     int value;
//     for(int i=deep+1;i<count;i++){
//         value = abs(nums[i]-nums[deep]);
//         if(value<Min){
//             Min=value;
//         }
//         dfs(nums,count,deep+1);
//     }
    
// }

// int main(){
//     int nums[] = {6,9,4,4};
//     dfs(nums,4,0);
//     cout<<Min;
// }
class Solution {
private:
    string path;
public:
    bool exist(vector<vector<char>>& board, string word) {
     
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(backtrack(board,i,j,word))
                    return true;
            }
        }
        return false;
    }                   
    bool backtrack(vector<vector<char>>& board,int i,int j,string& word){
        if(i==board.size()||j==board[0].size()||i<0||j<0){
          return path==word;
        }
        if(board[i][j]=='\0')
            return false;
        path += board[i][j];
        char temp = board[i][j]; 
        board[i][j] = '\0';
        bool flag = backtrack(board,i+1,j,word)
        || backtrack(board,i-1,j,word)
        || backtrack(board,i,j+1,word)
        || backtrack(board,i,j-1,word);
        board[i][j] = temp;
        path.pop_back();
        return flag;                                     
    }
};


int getSum(int x){
    int ans = 0;
    while(x){
        ans += x%10;
        x /= 10;
    }
    return ans;
}

int main(){
    // vector<vector<char>> board ={{'F','Y','C','E','N','R','D'},{'K','L','N','F','I','N','U'},{'A','A','A','R','A','H','R'},{'N','D','K','L','P','N','E'},{'A','L','A','N','S','A','P'},{'O','O','G','O','T','P','N'},{'H','P','O','L','A','N','O'}};
    // string word = "poland";
    // Solution s;
    // // cout<<s.exist(board,word);
    int a =19;
    cout<<getSum(a);
}