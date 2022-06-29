// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//后序遍历，看p或者q是不是在左子树或者右子树，若在两边，返回root，若都在左或者都在右，则返会左或者右


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) //root不存在 返回nullptr
            return root;
        if(root==p||root==q) //root等于p,q之一
            return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);  //去左子树寻找
        TreeNode* right = lowestCommonAncestor(root->right,p,q); // 去右子树寻找
        if(left&&right)  //左右都找到了 说明要返回根节点
            return root;
        return left?left:right; //否则返回left或者right
    }
};