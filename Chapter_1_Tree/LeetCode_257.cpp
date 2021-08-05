// 给定一个二叉树，返回所有从根节点到叶子节点的路径。
// 说明: 叶子节点是指没有子节点的节点。

//思路 维护一个私有属性paths ,定义一个局部string 一开始为根结点的值，往下建立字符串，
// 若到叶节点，加入paths，否则string += -> 下一个节点的值继续往下更新


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
    vector<string> paths;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        construct(root,path);
        return paths;
       
    }
    void construct(TreeNode* root, string path){
        if(root!=nullptr){
            path += to_string(root->val);
            if(root->left==nullptr&&root->right==nullptr){
                paths.push_back(path);
            }
            else{
                path += "->";
                construct(root->left,path);
                construct(root->right,path);
                };
        }   
    }
};