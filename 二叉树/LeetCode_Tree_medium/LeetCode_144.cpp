// 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

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
private:
    vector<int> nums;
public:
    vector<int> preorderTraversal(TreeNode* root) {
       preorder(root);
       return nums;
    }
    void preorder(TreeNode* root){
        if(!root){
            return;
        }
        nums.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
};
 

//非递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nums;
        if(!root)
            return nums;
        stack<TreeNode*> S;//维护一个堆栈，存入结点
        while(root||!S.empty()){//循环的条件
            while(root){//当root存在时
            S.push(root);//入栈
            nums.push_back(root->val);//打印
            root = root->left;//遍历左子树,左子树不存在就退出循环
            }
            if(!S.empty()){
            root = S.top();//出栈一个元素，遍历其右子树
            S.pop();
            root = root->right;
            }
        }
        return nums;
    }
}; 