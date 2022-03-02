class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        // 先序遍历
        if(!root)
            return root;
        TreeNode* left = root->left;
        root->left = root->right;
        root->right = left;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};



class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        // 中序遍历
        if(!root)
            return root;
       
        mirrorTree(root->left);
        TreeNode* left = root->left;
        root->left = root->right;
        root->right = left;
        //left与right交换过了，因此变成left
        mirrorTree(root->left);
        return root;
    }
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        // 后序遍历
        if(!root)
            return root;
        mirrorTree(root->left);
        mirrorTree(root->right);
        TreeNode* left = root->left;
        root->left = root->right;
        root->right = left;
        return root;
    }
};


// 层序
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            TreeNode* left = node->left;
            node->left = node->right;
            node->right = left;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return root;
    }
};