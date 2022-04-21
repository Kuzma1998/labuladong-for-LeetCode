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

// 层序遍历 bfs

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            auto left = node->right;
            node->right = node->left;
            node->left = left;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return root;
    }
};

// dfs
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return nullptr;
        TreeNode* left = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = left;
        return root;
    }
};


//深度优先遍历 非递归
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        stack<TreeNode*> nodeStack;
        TreeNode *currNode = root;
        while (currNode || !nodeStack.empty()) {
            while (currNode) {
                nodeStack.push(currNode);
                currNode = currNode->left;
            }
            currNode = nodeStack.top();
            nodeStack.pop();
            TreeNode *temp = currNode->left;
            currNode->left = currNode->right;
            currNode->right = temp;

            currNode = currNode->left;
        }
        return root;
    }
};
