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

// bst 的性质 左小根小于右
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        if((p->val>root->val&&q->val<root->val)||(p->val<root->val&&q->val>root->val))
            return root;
        if(root->val==q->val||root->val==p->val)
            return root;
        if(q->val>root->val&&p->val>root->val)
            return lowestCommonAncestor(root->right,p,q);
        return lowestCommonAncestor(root->left,p,q);
    }
};