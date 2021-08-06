// 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。。
//思路，维护一个私有属性counter，维护一个队列，里面存入结点，每次取出一个结点，递归寻找targetSum（先序遍历），找到了counter++，然后依次遍历每个结点

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include<string>
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

class Solution {
private:
    int counter = 0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* r = q.front();
            q.pop();
            preorder(r,targetSum);
            if(r->left)
                q.push(r->left);
            if(r->right)    
                q.push(r->right);
        }
        return counter;

    }
    void preorder(TreeNode* root, int targetSum){
        if(!root){
            return;
        }
        if(root->val==targetSum){
            counter++;
        }
        preorder(root->left,targetSum-root->val);
        preorder(root->right,targetSum-root->val);
    }
};