// 给定一个二叉树，返回它的 后序 遍历。

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
    vector<int> nums;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return nums;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* r;
        while(!stk.empty())
        {
            r = stk.top();
            stk.pop();
            if(r->left)
                stk.push(r->left);
            if(r->right)
                stk.push(r->right);
            nums.push_back(r->val);
        }
        reverse(nums.begin(),nums.end());
        return nums;
    }
};