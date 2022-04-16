// 给你一个二叉树的根节点 root ， 检查它是否轴对称。

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return dg(root->left,root->right);
    }
    bool dg(TreeNode* left,TreeNode* right){
        if(!left&&right)
            return false;
        if(left&&!right)
            return false;
        if(!left&&!right)
            return true;
        return left->val==right->val&&dg(left->left,right->right)&&dg(left->right,right->left);
    }
};

 