/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-27 15:58:35
 */
// 给定一个二叉树，找出其最小深度。
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
// 说明：叶子节点是指没有子节点的节点。
// 示例 1：
// 输入：root = [3,9,20,null,null,15,7]
// 输出：2


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
    int minDepth(TreeNode* root) {
        int depth;
        if(!root)
            return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1}); // 加入每一层的深度
        while(!q.empty()){
            TreeNode* cur = q.front().first;
            depth = q.front().second;
            q.pop();
            if(cur->left){
                q.push({cur->left,depth+1}); 
            }
            if(cur->right){
                q.push({cur->right,depth+1});
            }
            if(!cur->left&&!cur->right) //若该层到达终点，退出
                break;
        }
        return depth; // 返回该层的深度
    }
};