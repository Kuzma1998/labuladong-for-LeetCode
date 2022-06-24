// 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
// 对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大一个节点也可以是它自己的祖先

//思路 利用二=二叉搜索树的性质来解题，分情况进行讨论，递归

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include<string>
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
    TreeNode* Ancestor;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Ancestor = findAncestor(root,p,q);
        return Ancestor;
    }
    TreeNode* findAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {   
        if(root==nullptr)
            return nullptr;
        if((p->val<root->val&&q->val>root->val)||(q->val<root->val&&p->val>root->val)) //情况1，返回根节点
            return root;
        if((p->val<q->val&&p==root)||(q->val<p->val&&q==root)){ //情况2，返回根节点
            return root;
        }
        if((p->val>q->val&&p==root)||(q->val>p->val&&q==root)){//情况3，返回根节点
            return root;
        }
        if((p->val<root->val)&&(q->val<root->val)){  //递归
            return findAncestor(root->left,p,q);
        }
        return findAncestor(root->right,p,q); //递归
    }
};
