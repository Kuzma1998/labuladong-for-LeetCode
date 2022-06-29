// 给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），
// 使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

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

// 后续遍历
class Solution {
    int pre = 10001;
public:
    TreeNode* convertBST(TreeNode* root) {
        postorder(root);
        return root;
    }
    // 后序遍历即可
    void postorder(TreeNode* root){
        if(!root) return;
        postorder(root->right);
        if(pre==10001)  //最边的节点  直接把pre变成根节点的值 不需要操作
            pre = root->val;
        else{
            root->val += pre; //更新根节点和pre
            pre = root->val;
        }
        postorder(root->left);
    }
};