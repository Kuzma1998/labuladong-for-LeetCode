// 给你二叉树的根结点 root ，请你将它展开为一个单链表：
// 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
// 展开后的单链表应该与二叉树 先序遍历 顺序相同。

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
// 前序 遍历
class Solution {
vector<TreeNode*> ans;
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        preOrder(root);
        root = ans[0];
        for(int i=1;i<ans.size();++i){
            root->right = ans[i];
            root->left = nullptr;
            root = root->right;
        }
    }
    void preOrder(TreeNode* root){
        if(!root)
            return;
        ans.push_back(root);
        preOrder(root->left);
        preOrder(root->right);
        return;
    }
};

// 后续
class Solution {
    TreeNode *prev = nullptr;
    void helper(TreeNode *root){
        if(root == nullptr) return;
        helper(root->right);
        helper(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
};


// In-place 
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root != nullptr) {
            if (root->left != nullptr) {
                auto most_right = root->left; // 如果左子树不为空, 那么就先找到左子树的最右节点
                while (most_right->right != nullptr) most_right = most_right->right; // 找最右节点
                most_right->right = root->right; // 然后将跟的右孩子放到最右节点的右子树上
                root->right = root->left; // 这时候跟的右孩子可以释放, 因此我令左孩子放到右孩子上
                root->left = nullptr; // 将左孩子置为空
            }
            root = root->right; // 继续下一个节点
        }
        return;
    }
};
