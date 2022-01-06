//思路，层序遍历 队列存储结点以及它在这一层的位置。

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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<pair<TreeNode*,int>> q;
        int width = 0;
        q.push({root,1});
        while(!q.empty()){
            int l = q.size();
            int left;
            int right;
            for(int i=0;i<=l-1;++i){
                if(i==0)
                    left = q.front().second;
                if(i==l-1)
                    right = q.front().second;
                TreeNode* r = q.front().first;
                int pos = q.front().second;
                q.pop();
                if(r->left){
                    q.push({r->left, 2*pos-2*left});
                }
                if(r->right){
                    q.push({r->right, 2*pos-2*left+1});
                }
            }
            width = max(width,right-left+1);
        }
        return width;
    }
};
