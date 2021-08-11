// 给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
// 每条从根节点到叶节点的路径都代表一个数字：
// 例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
// 计算从根节点到叶节点生成的 所有数字之和 。
// 叶节点 是指没有子节点的节点。

//深度优先搜索,维护一个全局变量sum记录节点的和，维护一个字符串s用于转换成整数，到叶节点就把s转换成整数，未到则继续递归



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
private:
    int sum = 0;
    string s;
public:
    int sumNumbers(TreeNode* root) {
        DFS(root);
        return sum;
    }
    void DFS(TreeNode* root){
        if(!root)
            return;
        s += to_string(root->val);
        if(!root->left&&!root->right)
            sum += stoi(s);
        DFS(root->left);
        DFS(root->right);
        s.pop_back(); 
    }
};