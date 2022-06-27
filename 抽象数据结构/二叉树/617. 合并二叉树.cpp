// 给你两棵二叉树： root1 和 root2 。
// 想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。
// 你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；
// 否则，不为 null 的节点将直接作为新二叉树的节点。
// 返回合并后的二叉树。
// 注意: 合并过程必须从两个树的根节点开始。

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return dg(root1,root2);
    }
    TreeNode* dg(TreeNode* root1,TreeNode* root2){
        // 返回条件
        if(!root1)
            return root2;
        if(!root2) 
            return root1;
        TreeNode* root = new TreeNode(root1->val+root2->val); //两个节点都存在，新建节点
        root->left = dg(root1->left,root2->left); // 递归建立左子树
        root->right = dg(root1->right,root2->right); //递归建立右子树
        return root;
    }
};