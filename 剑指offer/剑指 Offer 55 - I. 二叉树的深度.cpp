// 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
// 例如：
// 给定二叉树 [3,9,20,null,null,15,7]，
//   3
//    / \
//   9  20
//     /  \
//    15   7
// 返回它的最大深度 3 。

// 思路：递归或者BFS
// dfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return DFS(root);
    }
    int DFS(TreeNode* root){
        if(!root)
            return 0;
        return 1+max(DFS(root->left),DFS(root->right));
        
    }
};


// bfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans =0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* node =q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ++ans;
        }
        return ans;
    }
};