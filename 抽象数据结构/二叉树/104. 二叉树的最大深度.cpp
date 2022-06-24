#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//最大深度，后续遍历问题
//树的深度=高度+1
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return getHeight(root);
    }
    int getHeight(TreeNode *root)
    { //后续遍历，左右根
        int dl, dr, h;
        if (root)
        {
            dl = getHeight(root->left);
            dr = getHeight(root->right);
            h = (dl > dr) ? dl : dr;
            return h + 1;
        }
        else
        {
            return 0;
        }
    }
};


//非递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        queue<pair<int ,TreeNode*>> Q;
        Q.push({1,root});
        int depth;
        while(!Q.empty()){
            TreeNode* r = Q.front().second;
            depth = Q.front().first;
            Q.pop();
            if(r->left)
                Q.push({depth+1,r->left});
            if(r->right)
                Q.push({depth+1,r->right});
        }
        return depth;
//     }
};