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
#include<unordered_map>  
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



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node){
                ans += '#'+',';
                continue;
            }else ans+= to_string(node->val)+',';
            q.push(node->left);
            q.push(node->right);
        }
        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vec = str2char(data);
        return BT(vec);
    }
    vector<string> str2char(string data){
        int pre = 0;
        vector<string> ans;
        for(int i=0;i<=data.size();++i){
            if(data[i]==','||i==data.size()){
                ans.push_back(data.substr(pre,i-pre));
                pre =i+1;
            }
        }
        return ans;
    }
    TreeNode* BT(vector<string> vec){
        if(vec.size()==0)
            return nullptr;
        TreeNode* root = new TreeNode(stoi(vec[0]));
        queue<TreeNode*> q;
        q.push(root);
        for(int i=1;i<vec.size();){
            TreeNode* node = q.front();
            q.pop();
            // if(!node)
            //     continue;
            if(vec[i]=="#"){
               node->left = nullptr;
               ++i;
            }else 
                node->left = new TreeNode(stoi(vec[i++]));
            if(i>=vec.size()) break;
            if(vec[i]=="#"){
                node->right = nullptr;
                ++i;
            }
            else{
                node->right = new TreeNode(stoi(vec[i++]));
            }
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right); 
        }
        return root;
    }
};


int main(){
    Codec s;
    string str = "1,2,3,#,#,4,5,#,#";
    s.deserialize(str);

}