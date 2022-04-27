// 偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
// 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，
// 聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
// 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。


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

// dfs+map
class Solution {
unordered_map<TreeNode*,int> mp;
public:
    int rob(TreeNode* root) {
        return dg(root);
    }
    int dg(TreeNode* root){
        if(!root)
            return 0;
        if(!root->left&&!root->right)
            return root->val;
        if(mp.find(root)!=mp.end())
            return mp[root];
        int left = 0,right = 0;
        if(root->left){
            left = dg(root->left->left)+dg(root->left->right);
        }
        if(root->right){
            right = dg(root->right->left)+dg(root->right->right);
        }
        mp[root] = max(root->val+right+left,dg(root->left)+dg(root->right));
        return  mp[root];
    }
};