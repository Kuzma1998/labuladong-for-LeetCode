
// 计算给定二叉树的所有左叶子之和
//递归加DFS  对应先序

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
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
    int ans = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        dg(root,0);
        return ans;
    }
    void dg(TreeNode* root, int flag){
        if(!root) return;
        if(flag&&!root->left&&!root->right)
            ans += root->val;
        dg(root->left,1);
        dg(root->right,0);
    }
};

//队列加广度优先搜索，对用层序遍历
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int sum = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *r = q.front();
            q.pop();
            if (r->left && r->left->left == nullptr && r->left->right == nullptr)
            {
                sum += r->left->val;
            }
            if (r->left)
            {
                q.push(r->left);
            }
            if (r->right)
            {
                q.push(r->right);
            }
        }
        return sum;
    }
};