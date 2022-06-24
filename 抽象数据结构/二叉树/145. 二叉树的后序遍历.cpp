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

// 根左右加逆序
class Solution {
vector<int> ans;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return ans;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while(!s.empty()||node){
            while(node){
                ans.push_back(node->val);
                s.push(node);
                node = node->right;
            }
            if(!s.empty()){
                TreeNode* res = s.top();
                s.pop();
                node = res->left;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};