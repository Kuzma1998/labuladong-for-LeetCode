/*
 * @Descripttion:
 * @version:
 * @Author: Li Jiaxin
 * @Date: 2021-10-30 19:47:56
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-12-25 09:37:50
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


class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        backtrack(nums,0,used);
        return ans;
    }
    void backtrack(vector<int>& nums,int index,vector<bool>& used){
        ans.push_back(path);
        if(index==nums.size())
            return;
        for(int i=index;i<nums.size();++i){
            if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false)  // 树的层剪枝，而树的深度可以重复
                continue;
            if(used[i])
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums,i+1,used);
            used[i] = false;
            path.pop_back();
        }
    }
};


int main(){
    Solution solver; 
    vector<int> nums{1,2,2}; //
    vector<vector<int>> ans = solver.subsetsWithDup(nums);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}