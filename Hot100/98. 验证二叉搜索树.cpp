// 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
// 有效 二叉搜索树定义如下：
// 节点的左子树只包含 小于 当前节点的数。
// 节点的右子树只包含 大于 当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树


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

// 中序遍历 yong pre记录下前一个节点 ，前一个节点必然要小于当前节点
class Solution {
private:
    long long pre = LONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }

    bool inorder(TreeNode* root){
        if(!root)
            return true;
        bool left = inorder(root->left);
        // 比较 和更新
        if(root->val<=pre)
            return false;
        pre = root->val;
        bool right = inorder(root->right);
        return left&&right;
    }
};