// 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

// 叶子节点 是指没有子节点的节点。


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
    vector<vector<int>> paths;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<int> path;
       DFS(root,targetSum,path);
       return paths;
    }
    void DFS(TreeNode* root, int targetSum,vector<int> path){
            if(!root)
                return;
            path.push_back(root->val);
            if(targetSum-root->val==0&&root->left==nullptr&&root->right==nullptr)
                paths.push_back(path);
            DFS(root->left,targetSum-root->val,path);
            DFS(root->right,targetSum-root->val,path);
            
        }
};

// 时间复杂度：O(N^2)
// 其中 N是树的节点数。在最坏情况下，树的上半部分为链状，下半部分为完全二叉树，并且从根节点到每一个叶子节点的路径都符合题目要求。
// 此时，
// 空间复杂度：O(N)O，其中 N 是树的节点数。空间复杂度主要取决于栈空间的开销，栈中的元素个数不会超过树的节点数。



class Solution {
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return ans;
    }
    void dfs(TreeNode* root, int targetSum){
        if(!root) return; //节点为空 返回
        if(!root->right&&!root->left){ //叶子节点  判断
            if(targetSum==root->val){
                path.push_back(root->val);
                ans.push_back(path); //撤销
                path.pop_back();
            }
            return;
        }
        // 回溯  先push在pop
        path.push_back(root->val);
        dfs(root->left,targetSum-root->val);
        dfs(root->right,targetSum-root->val);
        path.pop_back();
    }
};