/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 深度优先搜索
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        // 所有的结果数就是根节点递归加上左右节点递归
        return dg(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
    int dg(TreeNode* root,long long targetSum){
        if(!root)
            return 0;
        targetSum = targetSum-root->val;
        if(targetSum==0)    // 当前节点是一条有效路径 继续往下找
            return 1+dg(root->left,targetSum)+dg(root->right,targetSum);
        // 当前节点不是一条有效路径 继续往下找
        return dg(root->left,targetSum)+dg(root->right,targetSum);
    }
};