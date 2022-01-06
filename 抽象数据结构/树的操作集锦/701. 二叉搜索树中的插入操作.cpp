// 给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 
// 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。
// 注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。

// 明确根节点要干啥，剩下交给递归，根节点就是比较大小，根节点为空，就在这插入，若根节点的值大于val则插入左边，反之插入右边

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* root = new TreeNode(val);
            return root;
        }
        if(root->val>val){
            root->left = insertIntoBST(root->left,val);
        }
        if(root->val<val){
            root->right = insertIntoBST(root->right,val);
        }
        return root;
    }
};