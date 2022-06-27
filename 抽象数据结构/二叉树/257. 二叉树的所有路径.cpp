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
vector<string> ans;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
    void dfs(TreeNode* root, string s){
        if(!root) // 空节点
            return;
        if(!root->left&&!root->right)  // 叶子节点
            ans.push_back(s+to_string(root->val));
        dfs(root->left,s+to_string(root->val)+"->"); // 递归
        dfs(root->right,s+to_string(root->val)+"->");
    }
};

// 递归  维护两个全局变量
class Solution {
private:
    int depth = 0;
    int ans = 0;
public:
    int findBottomLeftValue(TreeNode* root) {
        ans = root->val;
        dg(root,0);
        return ans;
    }
    void dg(TreeNode* root, int l){
        if(!root) return;
        if(!root->left&&!root->right){
            if(depth<l)  //当前最深小于某次遍历的l 更新结果
            {
            depth = l;
            ans = root->val;
            }
            return;
        }
        dg(root->left,l+1);  // 先要遍历左边，就会更新depth进而屏蔽掉右边的取值
        dg(root->right,l+1);
        return;
    }
};