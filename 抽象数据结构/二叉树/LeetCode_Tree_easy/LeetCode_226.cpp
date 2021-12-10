//翻转二叉树，左右结点都交换  后序遍历问题(递归)
// 这是一道很经典的二叉树问题。
// 显然，我们从根节点开始，递归地对树进行遍历，并从叶子节点的父节点先开始翻转。如果当前遍历到的节点root的左右两棵子树都已经翻转，
// 那么我们只需要交换两棵子树的位置，即可完成以root为根节点的整棵子树的翻转

//非递归就用层序遍历


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
        }
};



class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* r = Q.front();
            Q.pop();
            TreeNode* temp = r->left;
            r->left = r->right;
            r->right = temp;
            if(r->left){
                Q.push(r->left);
            }
            if(r->right){
                Q.push(r->right);
            }
        }
        return root;
        }
};