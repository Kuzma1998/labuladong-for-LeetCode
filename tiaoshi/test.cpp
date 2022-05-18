//基本头文件
#include <iostream>
//算法
#include <algorithm>
#include <functional>
#include <numeric>
#include <math.h>
//容器
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <stack>
#include <string>
#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<int> singleNumbers(vector<int>& nums) {
//         int n =0;
//         for(int i=0;i<nums.size();++i){
//             n ^= nums[i];
//         }
//         int m = 1;
//         // 找到n里面第一位不为0的，用这个来分界
//         while((n&m)==0){
//             m <<= 1;
//         }
//         int x=0,y=0;
//         for(auto num:nums){
//             if(num&m){
//                 x ^= num;
//             }else{
//                 y ^= num;
//             }
//         }
//         return {x,y};
//     }
// };

// int main(){
//     vector<int> nums{1,2,5,2};
//     Solution s;
//     vector<int> ans = s.singleNumbers(nums);
//     for(auto i:ans){
//         cout<<i<<endl;
//     }
// }

// class Solution {
// public:
//     vector<vector<int>> findContinuousSequence(int target) {
//         int l=1,r=2;
//         vector<vector<int>> ans;
//         int sum = 3;
//         while(l<r){
//             vector<int> path;
//             while(sum<target){
//                 ++r;
//                 sum +=r;
//             }
//             while(sum>=target){
//                 if(sum==target){
//                     for(int i=l;i<=r;++i){
//                         path.push_back(i);
//                     }
//                     ans.push_back(path);
//                 }
//                 sum -= l;
//                 ++l;
//             }
//         }
//         return ans;
//     }
// };

// int main(){
//     Solution s;
//     s.findContinuousSequence(9);
//     return 0;
// }

// class Solution {
// struct cmp{
//     bool operator()(pair<int,int> a,pair<int,int> b){
//         if(a.first==b.first)
//             return a.second<b.second;
//         return a.first<b.first;
//     }
// };
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int sz = nums.size();
//         if(!sz)
//             return {};
//         cmp c;
//         priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q(c);
//         for(int i=0;i<k;++i){
//             q.push({nums[i],i});
//         }
//         vector<int> ans;
//         ans.push_back(q.top().first);
//         for(int i=k;i<sz;++i){
//             cout<<q.top().first<<endl;
//             while(!q.empty()&&i-k>=q.top().second){
//                 q.pop();
//             }
//             q.push({nums[i],i});
//             ans.push_back(q.top().first);
//         }
//         return ans;
//     }
// };

// int main(){
//     Solution s;
//     vector<int> nums = {9,10,9,-7,-4,-8,2,-6};
//     s.maxSlidingWindow(nums,5);

// }

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// class Codec {
// public:
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         string ans = "";
//         if(!root)
//             return ans;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             TreeNode* node = q.front();
//             q.pop();
//             if(!node){
//                 ans += '#'+',';
//                 continue;
//             }else ans+= to_string(node->val)+',';
//             q.push(node->left);
//             q.push(node->right);
//         }
//         ans.pop_back();
//         return ans;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         vector<string> vec = str2char(data);
//         return BT(vec);
//     }
//     vector<string> str2char(string data){
//         int pre = 0;
//         vector<string> ans;
//         for(int i=0;i<=data.size();++i){
//             if(data[i]==','||i==data.size()){
//                 ans.push_back(data.substr(pre,i-pre));
//                 pre =i+1;
//             }
//         }
//         return ans;
//     }
//     TreeNode* BT(vector<string> vec){
//         if(vec.size()==0)
//             return nullptr;
//         TreeNode* root = new TreeNode(stoi(vec[0]));
//         queue<TreeNode*> q;
//         q.push(root);
//         for(int i=1;i<vec.size();){
//             TreeNode* node = q.front();
//             q.pop();
//             // if(!node)
//             //     continue;
//             if(vec[i]=="#"){
//                node->left = nullptr;
//                ++i;
//             }else
//                 node->left = new TreeNode(stoi(vec[i++]));
//             if(i>=vec.size()) break;
//             if(vec[i]=="#"){
//                 node->right = nullptr;
//                 ++i;
//             }
//             else{
//                 node->right = new TreeNode(stoi(vec[i++]));
//             }
//             if(node->left)
//                 q.push(node->left);
//             if(node->right)
//                 q.push(node->right);
//         }
//         return root;
//     }
// };

// int main(){
//     Codec s;
//     string str = "1,2,3,#,#,4,5,#,#";
//     s.deserialize(str);

// }

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// class Solution
// {
// public:
//     ListNode *removeNthFromEnd(ListNode *head, int n)
//     {
//         int sz = 0;
//         ListNode *node = head;
//         while (node)
//         {
//             ++sz;
//             node = node->next;
//         }
//         if (n == sz)
//             return head->next;
//         int k = sz - n - 1;
//         node = head;
//         while (k--)
//         {
//             node = node->next;
//         }
//         ListNode *next = node->next->next;
//         node->next = next;
//         return head;
//     }
// };

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(!list1)
//             return list2;
//         if(!list2) 
//             return list1;
//         ListNode* dummy = new ListNode(0);
//         ListNode* ans = dummy;
//         while(list1&&list2){

//             if(list1->val<=list2->val){
//                 dummy->next = new ListNode(list1->val);
//                 cout<<list1->val<<endl;
//                 list1 = list1->next;
//             }else{
//                 dummy->next = new ListNode(list2->val);
//                 cout<<list2->val<<endl;
//                 list2 = list2->next;
//             }
//             dummy = dummy->next;
//         }
//         if(list1){
//             dummy->next = list1;
//         }else{
//             dummy->next = list2;
//         }
//         return ans->next;
//     }
// };

// int main(){

//     vector<int> l1 = {1,2,4};
//     vector<int> l2 = {1,3,4};
//     ListNode* dummy1 = new ListNode(0);
//     ListNode* head1 = dummy1;
//     for(int i=0;i<l1.size();++i){
//         dummy1->next = new ListNode(l1[i]);
//         dummy1 = dummy1->next;
//     }
//     head1 = head1->next;

//     ListNode* dummy2 = new ListNode(0);
//     ListNode* head2 = dummy2;
//     for(int i=0;i<l2.size();++i){
//         dummy2->next = new ListNode(l2[i]);
//         dummy2 = dummy2->next;
//     }
//     head2 = head2->next;



//     vector<int> ans;

//     Solution s;
//     ListNode* head = s.mergeTwoLists(head1,head2);
//     while (head)
//     {
//         ans.push_back(head->val);
//         head = head->next;
//     }
//     for(auto i:ans){
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// int main(){
//     int N=0;
//     cin>>N;
//     vector<int> nums(N,0);
//     for(int i=0;i<N;++i){
//         cin>>nums[i];
//     }
//     int rmost = 0;
//     bool flag = false;
//     for(int i=0;i<N;++i){
//         if(i<=rmost){
//             rmost = max(rmost,i+nums[i]);
//             if(rmost>=N-1){
//                 flag = true;
//                 break;
//             }
                
//         }
//     }
//     cout<<flag<<endl;

//     return 0;
// }

// int main(){
//     string str="";
//     vector<string> vec;
//     getline(cin,str);
//     int pre = 0;
//     for(int i=0;i<str.size();++i){
//         if(str[i]==' '||i==str.size()-1){
//             if(str[i]==' '){
//                 vec.push_back(str.substr(pre,i-pre));
//                 pre =i+1;
//             }
//             if(i==str.size()-1){
//                 vec.push_back(str.substr(pre));
//             }
//         }
//     }

//     set<int> ss;
//     for(int i=0;i<10;++i){
//         ss.insert(i);
//     }
//     int ans = 0;
//     sort(vec.begin(),vec.end(),[](string a,string b){
//         set<char> s1;
//         set<char> s2;
//         for(int i=0;i<3;++i){
//             s1.insert(a[i]);
//             s2.insert(b[i]);
//         }
//         return s1.size()>=s2.size();
//     });

//     for(auto s:vec){
//         bool flag = false;
//         for(auto c:s){
//             if(ss.find(c-'0')!=ss.end()){
//                 ss.erase(c-'0');
//                 flag = true;
//             }
//             if(ss.size()==0){
//                 break;
//             }

//         }
//     if(flag){
//                 ++ans;
//             }
//     }
//     if(ss.size()!=0)
//         cout<<-1<<endl;
//     cout<<ans<<endl;
// }



// int main(){
//     int T =0;
//     cin>>T;
//     while(T--){
//         pos.clear();
//         int m=0;int n=0;
//         cin>>m>>n;
//         vector<vector<int>> map(m,vector<int>(n,0));
//         for(int i=0;i<m;++i){
//             string str;
//             cin>>str;
//             for(int j=0;j<n;++j){
//                 map[i][j] = str[j]-'0';
//             }
//         }

//         for(int i)
//         // 找到所有的1

//         // 判断会不会被淹没

//         //修改数组
       
//     }
// }



// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         if(n<2)
//             return 0;
//         vector<int> left(n,-1);
//         vector<int> right(n,-1);
//         int lmax = -1;
//         for(int i=1;i<n;++i){
//             lmax = max(lmax,height[i-1]);
//             if(height[i]<height[i-1])
//                 left[i] = height[i-1];
//             else{
//                 if(height[i]>lmax){
   
//                     left[i] = -1;
//                 }        
//             }
//         }

//         for(int i=n-2;i>=0;--i){
//             if(height[i]<height[i+1])
//                 right[i] = height[i+1];
//             else
//                 right[i] = right[i+1];
//         }
//         int ans = 0;
//         for(int i=1;i<n-1;++i){
//             if(left[i]==-1||right[i]==-1)
//                 continue;
//             ans += (min(right[i],left[i])-height[i]);
//         }
//         return ans;
//     }
// };

// int main(){
//     vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
//     Solution s;
//     cout<<s.trap(v)<<endl;
//     return 0;
// }


// class Solution {
// public:
//     string minWindow(string s, string t) {
//         if(t.size()>s.size()){
//             return "";
//         }
//         int l=0,r=0,len=100000;
//         int char_len = 0;
//         string ans;
//         unordered_map<char,int> mp1,mp2;
//         for(auto c:t)
//             mp1[c]++;
//         while(r<s.size()){
//             char c = s[r++];
//             if(mp1.count(c)){
//                 mp2[c]++;
//                 if(mp1[c]==mp2[c])
//                     ++char_len;
//             }
//             while(char_len==mp1.size()){
//                 if(r-l<len){
//                     len = r-l;
//                     cout<<len<<endl;
//                     ans = s.substr(l,r-l);
//                 }
//                 char rm_left = s[l++];
//                 if(mp1.count(rm_left)){
//                     mp2[rm_left]--;
//                     if(mp1[rm_left]>mp2[rm_left])
//                         --char_len;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// int main(){

//     string s = "ADOBECODEBANC";
//     string t = "ABC";
//     Solution solver;
//     cout<<solver.minWindow(s,t)<<endl;
// }



// class Solution {
// private:
//     vector<vector<int>> ans;
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<bool> used(nums.size(),false);
//         vector<int> path = {};
//         dfs(nums,used,path,0);
//         return ans;
//     }

//     void dfs(vector<int>& nums,vector<bool>& used,vector<int>& path,int index){
//         ans.push_back(path);
//         if(index>=nums.size()){
//             return;
//         }
//         for(int i=index;i<nums.size();++i){
//             if(used[i])
//                 continue;
//             path.push_back(nums[i]);
//             used[i] = true;
//             index+=1
//             dfs(nums,used,path,i+1);
//             used[i] = false;
//             path.pop_back();
//         }

//     }
// };


// int main(){
//     vector<int> nums = {1,2,3};
//     Solution solver;
//     auto ans = solver.subsets(nums);
// }



// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         // dp[j]表示s里面前j个是否可以由wordDict里的单词构成
//         vector<bool> dp(s.size()+1,false);
//         dp[0] = true;

//         for(int i=0;i<s.size();++i){
//             string str;
//             for(int j=0;j<wordDict.size();++j){
//                 str = wordDict[j];
//                 if(str==s.substr(i,str.size()))
//                     dp[i+str.size()] = dp[i+str.size()]||dp[i];
//             }
//         }
//         return dp.back();
//     }
// };

// int main(){
//     string s1 = "aaaa";
//     string s2 = "aaa";
//     vector<string> wordDict = {s1,s2};
//     string s("aaaaaaa");
//     Solution solver;
//     bool flag = solver.wordBreak(s,wordDict);

// }


// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         for(int i=k/2-1;i>=0;--i){
//             percDown(nums,i,k);
//         }
//         for(int i=k;i<nums.size();++i){
//             if(nums[i]>nums[0]){
//                 nums[0] = nums[i];
//                 percDown(nums,0,k);
//             }
//         }
//         return nums[0];
//     }
    
//     void percDown(vector<int>& nums,int i,int N){
//         int parent,child;
//         int temp = nums[i];
//         for(parent=i;parent*2+1<N;parent=child){
//             child = parent*2+1;
//             if(child!=N-1&&nums[child]>nums[child+1])
//                 child += 1;
//             if(temp<=nums[child])
//                 break;
//             else
//                 nums[parent] = nums[child];
//         }
//         swap(nums[parent],temp);
//     }
// };




// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         priority_queue<pair<int,int>> q;
//         vector<int> ans;
//         for(int i=0;i<k;++i){
//             q.push({nums[i],i});
//         }
//         ans.push_back(q.top().first);
//         for(int i=k;i<nums.size();++i){
//             while(i>=q.top().second+k){
//                 q.pop();
//             }
//             q.push({nums[i],i});
//             ans.push_back(q.top().first);
//         }
//         return ans;

//     }
// };


// int main(){

//     vector<int> nums = {9,10,9,-7,-4,-8,2,-6};
//     Solution solver;
//     solver.maxSlidingWindow(nums,5);
//     return 0; 
// }


// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> dp(n+1,INT_MAX);
//         int i=1;
//         dp[1] = 1;
//         dp[0] = 0;
//         for(int i=1;i<=n;++i){
//             for(int j=1;j*j<=i;++j){
//                 dp[i] = min(dp[i],dp[i-j*j]+1);
//             }
//         }
//         return dp[n];
//     }
// };

// int main(){
//     Solution s;
//     cout<<s.numSquares(13);
// }

// class Solution {
// public:
//     string decodeString(string s) {
//         stack<int> number;
//         stack<string> str;
//         int num = 0;
//         string res;
//         for(int i=0;i<s.size();++i){
//             if(s[i]-'0'>=0&&s[i]-'0'<=9){
//                 num += 10*num+s[i]-'0';
//             }
//             if(s[i]=='['){
//                 number.push(num);
//                 num = 0;
//                 str.push(res);
//                 res = "";
//             }
//             if(s[i]==']'){
//                 if(res==str.pop())
//                     res= 
//                 string temp = res;
//                 int times = number.top();
//                 number.pop();
//                 string top = str.top();
//                 str.pop();
//                 while(times--){
//                     top += temp;
//                 }
//                 str.push(top);
//                 res = str.top();
//             }
//             if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
//                 res += s[i];
//             }
//         }
//         return res;
//     }
// };

// int main(){
//     Solution solver;
//     string s = "3[a2[c]]";
//     cout<<solver.decodeString(s)<<endl;
// }


// class Solution {
// vector<vector<int>> ans;
// vector<int> path;
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         sort(coins.begin(),coins.end(),[](int a,int b){return a>b;});
//         int sz = INT_MAX;
//         dfs(coins,amount,0);
//         for(auto elem:ans){
//             int tmp = elem.size();
//             sz = min(sz,tmp);
//         }
//         return sz;
//     }
//     void dfs(vector<int>& coins, int amount,int index){
//         if(amount==0){
//             ans.push_back(path);
//         }
//         for(int i=index;i<coins.size();++i){
//             if(amount-coins[i]<0)
//                 continue;
//             if(i!=0&&coins[i]==coins[i-1])
//                 continue;
//             path.push_back(coins[i]);
//             dfs(coins,amount-coins[i],i);
//             path.pop_back();
//         }
//     }
// };

// int main(){
//     vector<int> coins = {1,2,5};
//     int  amount = 100;
//     Solution solver;
//     cout<<solver.coinChange(coins,amount);
// }


// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,pair<int,int>> mp;
//         for(auto num:nums){
//             mp[num].first = num;
//             mp[num].second++;
//         }
//         vector<pair<int,int>> hash;
//         vector<int> ans;
//         for(auto elem:mp){
//             hash.push_back(elem.second);
//         }
//         sort(hash.begin(),hash.end(),[](pair<int,int> a,pair<int,int>b){return a.second>b.second;});
//         for(int i=0;i<k;++i){
//             ans.push_back(hash[i].first);
//         }
//         return ans;
//     }
// };

// int main(){
//     Solution solver;
//     vector<int> nums{1,1,1,2,2,3};
//     solver.topKFrequent(nums,2);
// }

// class Solution {
// public:
//     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//         vector<vector<int>> sorted(people.begin(),people.end());
//         sort(sorted.begin(),sorted.end(),[](vector<int> a,vector<int> b){
//             if(a[0]==b[0])
//                 return a[1]<b[1];
//             return a[0]>b[0];
//         });
//         vector<vector<int>> ans;
//         for(auto person:sorted){
//             ans.insert(ans.begin()+person[1],person);
//         }
//         return ans;
//     }
// };

// int main(){
//    Solution s;
//    vector<vector<int>> people{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
//    s.reconstructQueue(people);
// }

// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         if(s.size()<p.size())
//             return {};
//         unordered_map<char,int> mp;
        
//         for(auto c:p){
//             mp[c]++;
//         }
//         int l=0,r=0;
//         vector<int> ans;
//         for(;r<s.size();++r){
//             unordered_map<char,int> mp2;
//             char c = s[r];
//             int sz = 0;
//             int cnt = 0;
//             while(mp.find(c)!=mp.end()&&sz<p.size()){
//                 mp2[c]++;
//                 if(mp2[c]==mp[c]){
//                     ++cnt;
//                 }
//                 if(cnt==mp.size())
//                     ans.push_back(r);
//                 sz++;
//                 c = s[r+sz];

//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         if(s.size()<p.size())
//             return {};
//         unordered_map<char,int> mp;
//         for(auto c:p){
//             mp[c]++;
//         }
//         vector<int> ans;
//         bool flag = false;
//         unordered_map<char,int> mp2;
//         for(int r=0;r<s.size();){
//             char c = s[r];
//             int sz = 0;
//             int cnt = 0;
//             if(flag){
//                 char last = s[r-p.size()];
//                 mp2[last]--;
//                 if(mp2[last]==0)
//                     mp2.erase(last);
//                 mp2[c]++;
//                 if(mp==mp2)
//                     ans.push_back(r-p.size()+1);
//             }
//             while(mp.find(c)!=mp.end()&&sz<p.size()&&!flag){
//                 mp2[c]++;
//                 if(mp2[c]==mp[c]){
//                     ++cnt;
//                 }
//                 if(cnt==mp.size()){
//                     ans.push_back(r);
//                     flag = true;
//                     r+=sz;
//                 }
//                 sz++;
//                 c = s[r+sz];
//             }
//             ++r;
//         }
//         return ans;
//     }
// };


// int main(){
//     string s = "cbaebabacd";
//     string p = "abc";
//     Solution solver;
//     solver.findAnagrams(s,p);
// }


// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         int n = nums.size();
//         for (auto& num : nums) {
//             int x = (num - 1) % n;
//             nums[x] += n;
//         }
//         vector<int> ret;
//         for (int i = 0; i < n; i++) {
//             if (nums[i] <= n) {
//                 ret.push_back(i + 1);
//             }
//         }
//         return ret;
//     }
// };


// int main(){
//     // vector<int> nums{4,3,2,7,8,2,3,1};
//     vector<int> nums{1,3,2,5,5};
//     Solution s;
//     s.findDisappearedNumbers(nums);
// }


// class Solution {
// public:
//     int hammingDistance(int x, int y) {
//         int max_num = max(x,y);
//         int min_num = min(x,y);
//         int ans = 0;
//         while(max_num){
//             if((max_num&1)!=(min_num&1)){
//                 ++ans;
//             }
//             max_num = max_num>>1;
//             min_num = min_num>>1;
//         }
//         return ans;
//     }
// };

// int main(){
//     int x = 1;
//     int y = 4;
//     Solution s;
//     s.hammingDistance(x,y);
// }


// class Solution {
// int ans = 0;
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         unordered_map<int,int> mp;
//         mp[0] = 1;
//         int prefixSum=0;
//         for(int i=0;i<nums.size();++i){
//             prefixSum+=nums[i];
//             if(mp.find(prefixSum-k)!=mp.end()){
//                 ans+=mp[prefixSum-k];
//             }
//             mp[prefixSum]++;
//         }
//         return ans;
//     }
// };


// int main(){
//     vector<int> ans{-1,1,0};
//     int k=0;
//     Solution s;
//     cout<<s.subarraySum(ans,k);
// }


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(),n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            if(obstacleGrid[i][0]==1)
                break;
            dp[i][0]=1;
        }
        for(int j=0;j<n;++j){
            if(obstacleGrid[0][j]==1)
                break;
            dp[0][j]=1;
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                if(obstacleGrid[i][j]==1)
                    continue;
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};


int main(){
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    Solution s;
    s.uniquePathsWithObstacles(obstacleGrid);
}