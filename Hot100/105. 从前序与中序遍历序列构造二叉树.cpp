/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    TreeNode* BT(vector<int>& preorder,int preStart,int preEnd,
                vector<int>& inorder, int inStart,int inEnd){
        if(preStart>preEnd||inStart>inEnd)
            return nullptr;
        // 构造根节点
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        // 根节点在中序里面的位置，由此确立左子树和右子树的长度
        int RootIndex = inStart;
        for(;RootIndex <=RootIndex ;RootIndex++){
            if(inorder[RootIndex ]==rootVal)
                break;
        }
        int left = RootIndex-inStart;
        // 递归建树
        root->left = BT(preorder,preStart+1,preStart+left,inorder,inStart,inStart+left);
        root->right = BT(preorder,preStart+1+left,preEnd,inorder,RootIndex+1,inEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return BT(preorder,0,preorder.size()-1,inorder,0,preorder.size()-1);
    }
};