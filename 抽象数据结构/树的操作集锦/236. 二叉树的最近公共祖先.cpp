/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-06 17:09:10
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-06 17:12:28
 */

// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
// 思路  递归，

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 递归终止条件
        if(!root)
            return nullptr;
        if(root==p||root==q)  // p或者q有一个和root相等，返回root
            return root;

        // 左右子树寻找
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        // 左右子树都找到了p或者q,那么根节点肯定时最近公共祖先
        if(left&&right)
            return root;
        // 都没找到返回null
        if(!left&&!right)
            return nullptr;
        // 找到一个，找到的这个肯定时最小公共祖先，假设左边找到了p，右边没找到，那么q肯定在左子树，那么公共祖先就是left
        return left==nullptr?right:left;
    }
};