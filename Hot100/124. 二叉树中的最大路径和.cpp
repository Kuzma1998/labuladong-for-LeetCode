// 路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 
// 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
// 路径和 是路径中各节点值的总和。
// 给你一个二叉树的根节点 root ，返回其 最大路径和 。


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
// 思路：递归求左右节点的返回值，若小于0，则截断为0 即不需要

class Solution {
int ans = -100000;
public:
    int maxPathSum(TreeNode* root) {
        dg(root);
        return ans;
    }
    int dg(TreeNode* root){
        if(!root)
            return 0;
        
        int left = max(dg(root->left),0);
        int right = max(dg(root->right),0);
        ans = max(ans,root->val+left+right);
        //返回值只能是根加左右里面较大的
        return root->val+max(left,right);
    }

};