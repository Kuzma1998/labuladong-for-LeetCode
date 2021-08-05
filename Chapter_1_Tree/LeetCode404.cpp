
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

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        // 为了更好的理解,分步写

        // 将空节点排除
        if (root == nullptr)
        {
            // 默认 null 节点和为 0
            return 0;
        }

        int leftLeafValue = 0;
        // left leaf 值
        if (isLeftLeafNode(root))
        {
            leftLeafValue = root->left->val;
        }

        // left 树中 left leaf 值总和，递归
        int l = sumOfLeftLeaves(root->left);

        // right 树中 left leaf 值总和，递归
        int r = sumOfLeftLeaves(root->right);

        // 返回总和即可
        return leftLeafValue + l + r;
    }

private:
    bool isLeftLeafNode(TreeNode *node)
    {

        // 是否 left leaf 节点，需要满足 2 条件
        // 1. 当前节点的 left 节点不为空 2. left 节点不再有左右子节点
        if (node->left != nullptr &&
            node->left->left == nullptr &&
            node->left->right == nullptr)
        {
            return true;
        }

        // 其它情况均为 false
        return false;
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