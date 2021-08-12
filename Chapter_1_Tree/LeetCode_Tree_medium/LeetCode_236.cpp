// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//后序遍历，看p或者q是不是在左子树或者右子树，若在两边，返回root，若都在左或者都在右，则返会左或者右


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)
            return nullptr;
        if(root==p||root==q)
            return root;
        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);
        if(l&&r)
            return root;//一左一右返回根
        return l?l:r;//否则返回左或者右
    }
};