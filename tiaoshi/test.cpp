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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=k/2-1;i>=0;--i){
            percDown(nums,i,k);
        }
        for(int i=k;i<nums.size();++i){
            if(nums[i]>nums[0]){
                nums[0] = nums[i];
                percDown(nums,0,k);
            }
        }
        return nums[0];
    }
    
    void percDown(vector<int>& nums,int i,int N){
        int parent,child;
        int temp = nums[i];
        for(parent=i;parent*2+1<N;parent=child){
            child = parent*2+1;
            if(child!=N-1&&nums[child]>nums[child+1])
                child += 1;
            if(temp<=nums[child])
                break;
            else
                nums[parent] = nums[child];
        }
        swap(nums[parent],temp);
    }
};

int main(){
    vector<int> nums{5,2,4,1,3,6,0};
    Solution s;
    cout<<s.findKthLargest(nums,4);
}