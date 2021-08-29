// 给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
// 初始状态下，所有 next 指针都被设置为 NULL。

// 思路 递归：若只传入一个节点，那么不同根节点的子节点肯定不会被连起来。因此要传入两个节点
// 关键在于要知道这两个节点要干啥，首先递归终止条件是这两个节点有一个为0，就返回。要做的是把左节点连到右节点。
// 往下递归也有三种，左节点的左右孩子递归，右节点的左右孩子递归，左节点的右孩子和右节点的左孩子连接


class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr)
            return root;
        connect(root->left,root->right);
        return root;
    }
    void connect(Node* left,Node* right){
        if(!left||!right)
            return;
        left->next = right;
        connect(left->left,left->right);
        connect(right->left,right->right);
        connect(left->right,right->left);

    }
};