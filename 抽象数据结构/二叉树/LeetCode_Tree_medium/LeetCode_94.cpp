// 给定一个二叉树的根节点 root ，返回它的 中序 遍历。

#include <iostream>
#include <algorithm>
#include<vector>
#include<utility>
#include<stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nums;
        inorder(root,nums);
        return nums;
    }
    void inorder(TreeNode* root,vector<int>& nums){
        if(!root)
            return;
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
};

//非递归


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nums;
        if(root==nullptr)
            return nums;
        stack<TreeNode*> S;
        while(root||!S.empty()){
            while(root){
                S.push(root);
                root = root->left;
            }
            if(!S.empty()){
                root = S.top();
                S.pop();
                nums.push_back(root->val);
                root = root->right;
            }
        }
        return nums;
    }

};