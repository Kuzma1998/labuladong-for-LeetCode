// 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
// 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
//深度优先搜索//先序

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


class Solution {
private:
    bool flag=true;
public:
    bool preorder(TreeNode* p, TreeNode* q){        
        if(p&&!q){
            flag = false;
            return flag ;
        }
        if(!p&&q){

            flag = false;
            return flag ;
        }
        if(!q&&!p){
            return true;
        }
        if((p->val)!=(q->val)){
            flag = false;
            return flag ;
        }
        preorder(p->left,q->left);
        if(flag == false){
            return flag;
        }
        preorder(p->right,q->right);
        return flag;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        flag = preorder(p,q);
        return flag;
    }    
};