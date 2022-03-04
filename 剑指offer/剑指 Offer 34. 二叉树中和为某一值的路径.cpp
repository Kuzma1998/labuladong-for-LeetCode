// 你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
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

// 回溯 记得传引用  然后有个退回操作
class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> path;
        preorder(root,target,path);
        return ans;
    }
    void preorder(TreeNode* root, int& target,vector<int>& path){
        if(!root)
            return;
        path.push_back(root->val);
        target -= root->val;
        if(target==0&&!root->left&&!root->right){
            ans.push_back(path);
        }
        preorder(root->left,target,path);
        preorder(root->right,target,path);
        target += root->val;
        path.pop_back();
        return;
    }
};

//  dfs  没有退回操作，传的是拷贝
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