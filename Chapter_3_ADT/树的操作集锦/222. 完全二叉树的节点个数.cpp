// 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
// 完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
// 并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。


// 思路，完全二叉树分解成满二叉树与完全二叉树即可
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        TreeNode* l = root;
        TreeNode* r = root;
        int hl=0;int hr=0;
        while(l){
            l = l->left;
            hl++;
        }
        while(r){
            r = r->right;
            hr++;
        }
        // 若是满二叉树，则套公式
        if(hl==hr)
            return (int)pow(2,hr)-1;
        // 完全二叉树则普通递归
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};