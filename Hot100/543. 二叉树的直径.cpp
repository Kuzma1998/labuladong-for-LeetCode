// 给定一棵二叉树，你需要计算它的直径长度。
// 一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

class Solution {
int ans = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans;
    }
    int depth(TreeNode* root){
        if(!root)
            return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        ans = max(ans,left+right);// 更新结果
        return 1+max(left,right);
    }
};