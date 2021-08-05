// 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，
// 判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
// 叶子节点 是指没有子节点的节点

#include <iostream>
#include <algorithm>
#include <vector>
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

//思路，递归。从根节点到叶子节点的值等于target，等价于从根节点的左右结点往下到叶节点 的值等于target-root->val;如此递归即可
//到叶节点，判断是不是相等即可
//递归就是dfs
class Solution {
public:
    bool dp(TreeNode* root,int targetSum){
        if(!root){
            return false;
        }
        //叶节点，判断是不是等于targetsum
        if(!root->left&&!root->right){
            return root->val==targetSum;
        }
        int tar = targetSum -(root->val);
        return dp(root->left,tar)||dp(root->right,tar);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dp(root,targetSum);

    }

};





//还有广度BFS算法，用队列
// 先我们可以想到使用广度优先搜索的方式，记录从根节点到当前节点的路径和，以防止重复计算。

// 这样我们使用两个队列，分别存储将要遍历的节点，以及根节点到这些节点的路径和即可。

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return false;
        }
        queue<TreeNode *> que_node;
        queue<int> que_val;
        que_node.push(root);
        que_val.push(root->val);
        while (!que_node.empty()) {
            TreeNode *now = que_node.front();
            int temp = que_val.front();
            que_node.pop();
            que_val.pop();
            if (now->left == nullptr && now->right == nullptr) {
                if (temp == sum) {
                    return true;
                }
                continue;
            }
            if (now->left != nullptr) {
                que_node.push(now->left);
                que_val.push(now->left->val + temp);
            }
            if (now->right != nullptr) {
                que_node.push(now->right);
                que_val.push(now->right->val + temp);
            }
        }
        return false;
    }
};
