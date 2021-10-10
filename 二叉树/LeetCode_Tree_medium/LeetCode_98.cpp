// 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
// 假设一个二叉搜索树具有如下特征：
// 节点的左子树只包含小于当前节点的数。
// 节点的右子树只包含大于当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。

//思路，中序遍历，二叉搜索树得中序遍历是有序得
#include <iostream>
#include <algorithm>
#include<vector>
#include<utility>
#include<stack>
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

class Solution {
private:
    long long pre = LONG_MIN; //最小值
public:
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
    bool inorder(TreeNode* root){
        if(!root)   
            return true;
        bool l = inorder(root->left);
        if(root->val<=pre){
            return false;
        }
        pre = root->val;
        bool r = inorder(root->right);
        return l&&r;
    }
};