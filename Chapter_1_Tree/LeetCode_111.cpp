#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

///最小树深度，还是后序遍历问题
// 给定一个二叉树，找出其最小深度。
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
// 说明：叶子节点是指没有子节点的节点。
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        queue<pair<int ,TreeNode*>> Q;
        Q.push({1,root});
        int depth;
        while(!Q.empty()){
            TreeNode* r = Q.front().second;
            depth = Q.front().first;
            Q.pop();
            if(r->left){
                Q.push({depth+1,r->left});
            }
            if(r->right){
                Q.push({depth+1,r->right});
            }
            if((!r->left)&&(!r->right)){
                break;
            }
        }
        return depth;
    }

};