// 给定一个二叉搜索树，请将它的每个节点的值替换成树中大于或者等于该节点值的所有节点值之和。
// 思路 中序遍历，右根左，维护一个全局变量，让他每次加上遍历过的根节点即可。

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
class Solution {
private:
    int sum = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        getSum(root);
        return root;
    }
    void getSum(TreeNode* root){
        if(!root)
            return;
        getSum(root->right);
        sum += root->val;
        root->val = sum;
        getSum(root->left);

    }
};