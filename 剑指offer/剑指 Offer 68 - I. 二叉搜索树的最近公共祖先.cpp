/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-15 15:06:33
 */

// 迭代
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(p->val>root->val&&q->val>root->val)
                root = root->right;
            else if(p->val<root->val&&q->val<root->val)
                root = root->left;
            else 
                break;
        }
        return root;
    }
};