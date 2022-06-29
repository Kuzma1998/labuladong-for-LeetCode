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


// 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
// 差值是一个正数，其数值等于两值之差的绝对值。
// 中序遍历 这个值一定是相邻的两个节点之间取得

class Solution {
    int ans = INT_MAX; //结果
    int pre = -1; // 中序遍历前一个值
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        if(pre==-1){  //一直往左遍历找到最左边的节点 需要处理这一特殊情况
            pre = root->val; // 把pre置为当前节点的值
        }else{
            ans = min(ans,root->val-pre);
            pre = root->val;
        }
        inorder(root->right);
    }
};