// 给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。
// 例如，
// 给定二叉搜索树:

//         4
//        / \
//       2   7
//      / \
//     1   3
// 找2
// 你应该返回如下子树:

//       2     
//      / \   
//     1   3

// 思路，递归返回，找到了返回根节点即可
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return NULL;;
        if(root->val==val){
            return root;
        }
        return (root->val>val)? searchBST(root->left,val):searchBST(root->right,val);
    }
};