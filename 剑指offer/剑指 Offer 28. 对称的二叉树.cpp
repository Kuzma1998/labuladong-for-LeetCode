// 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
//     1
//    / \
//   2   2
//    \   \
//    3    3

// 思路： 递归
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return dg(root->left,root->right);
        
    }

    bool dg(TreeNode* left,TreeNode* right){
        if(!left&&!right)
            return true;
        else if(!left&&right)
            return false;
        else if(left&&!right)
            return false;
        else if(left->val!=right->val)
            return false;
        else
            return dg(left->left,right->right)&& dg(left->right,right->left);
    }
};