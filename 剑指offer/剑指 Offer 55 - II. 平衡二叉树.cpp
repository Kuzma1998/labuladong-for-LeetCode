// 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
// 示例 1:
// 给定二叉树 [3,9,20,null,null,15,7]
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回 true 。
// 示例 2:
// 给定二叉树 [1,2,2,3,3,null,null,4,4]

//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
// 返回 false 。

// 思路:先序加判断  或者后序加剪枝
// 先序加判断
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        return abs(DFS(root->left)-DFS(root->right))<=1
                &&isBalanced(root->left)
                &&isBalanced(root->right);
    }
    int DFS(TreeNode* root){
       if(!root)
            return 0;
        return 1+max(DFS(root->left),DFS(root->right));
    }
};

// 后序加剪枝
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        return DFS(root)==-1?false:true;
    }
    int DFS(TreeNode* root){
        if(!root)
            return 0;
        int left = DFS(root->left);// 出现-1代表不平衡,直接返回-1
        if(left==-1)
            return -1;
        int right = DFS(root->right);
        if(right==-1)
            return -1;
        return abs(right-left)>1?-1:1+max(left,right);
    }
};