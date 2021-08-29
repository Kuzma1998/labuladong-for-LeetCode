// 给你二叉树的根结点 root ，请你将它展开为一个单链表：
// 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
// 展开后的单链表应该与二叉树 先序遍历 顺序相同。

// 对于树的递归，首先定义递归函数，就是把以root为根节点的树变成链表。
// 递归的终止条件，根节点为空，直接返回。
// 进而选择递归框架，我们首先要递归根节点的左右子树，变成链表，然后对根节点进行操作，因而是后序遍历
// 明确根节点做啥，就是把左边变为空，右边连左边，在连原来的右边

class Solution {
public:
    void flatten(TreeNode *root) {
        flattenTree(root);
    }
    TreeNode* flattenTree(TreeNode *root){
        if(!root){
            return nullptr;
        }
        TreeNode *left = flattenTree(root->left);
        TreeNode *right = flattenTree(root->right);

        root->left = nullptr;
        root->right = left;
        TreeNode* rightconnected = root;
        while(rightconnected->right){
            rightconnected = rightconnected->right;
        }
        rightconnected->right = right;
        return root;
    }
};

