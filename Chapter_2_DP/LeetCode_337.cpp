// 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。
// 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
// 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
// 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
// 示例 1:
// 输入: [3,2,3,null,3,null,1]

//      3
//     / \
//    2   3
//     \   \ 
//      3   1

// 输出: 7 
// 解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
// 示例 2:

// 输入: [3,4,5,1,3,null,1]

//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1

// 输出: 9
// 解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.


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


// 思路  递归，若抢根，则可以抢根左左+根左右+根右左+根右右。 不抢根，则可以抢根左+根右。 看二者谁大
class Solution {
private:
    unordered_map<TreeNode*,int> memo;
public:
    int rob(TreeNode* root) {
        return dp(root);
    }
    int dp(TreeNode* root){
        if(!root)
            return 0;
        if(memo.count(root))
            return memo[root];

        int rob_r = root->val + 
        (root->left==nullptr? 0:dp(root->left->left)+dp(root->left->right)) + 
        (root->right==nullptr? 0:dp(root->right->left)+dp(root->right->right));
        int not_rob_r = dp(root->left) + dp(root->right);
        
        if (rob_r>not_rob_r)
            memo[root] = rob_r;
        else
            memo[root] = not_rob_r;
        return memo[root];
    }
};