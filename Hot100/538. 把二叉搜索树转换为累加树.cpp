// 给出二叉 搜索 树的根节点，该树的节点值各不相同，
// 请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
// 提醒一下，二叉搜索树满足下列约束条件：
// 节点的左子树仅包含键 小于 节点键的节点。
// 节点的右子树仅包含键 大于 节点键的节点。
// 左右子树也必须是二叉搜索树。
// 中序遍历（右根左） 利用一个全局变量 不断改变次变量的值，作为上一个遍历到的节点的值

class Solution {
private:
    int val=0;
public:
    TreeNode* convertBST(TreeNode* root) {
        dg(root);
        return root;
    }
    void dg(TreeNode* root){
        if(!root)
            return;
        dg(root->right);
        root->val += val;
        val = root->val;
        dg(root->left);
    }
};