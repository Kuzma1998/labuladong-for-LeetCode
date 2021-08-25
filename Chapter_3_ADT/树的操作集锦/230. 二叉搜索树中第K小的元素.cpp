// 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
// 中序非递归算法可以节约空间时间，只需要遍历K次

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
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while(root||!s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            if(!s.empty()){
                root = s.top();
                s.pop();
                k--;
                if(k==0)
                    break;// 中序遍历是第二次遇到才打印
                else
                    root = root->right;
            }
        }
        return root->val;
    }
};