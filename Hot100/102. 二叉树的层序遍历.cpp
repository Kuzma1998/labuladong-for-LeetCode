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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            int sz = s.size();
            vector<int> path;
            while(sz--){
                TreeNode* node = s.front();
                s.pop();
                path.push_back(node->val);
                if(node->left)
                    s.push(node->left);
                if(node->right)
                    s.push(node->right);
            }
            ans.push_back(path);
        }
        return ans;
    }
};