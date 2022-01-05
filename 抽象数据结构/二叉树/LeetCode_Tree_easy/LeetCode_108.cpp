// 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
// 高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

//递归建树，根结点先是数组的终点，然后递归建立左树右树

#include <iostream>
#include <algorithm>
#include<vector>
#include<utility>
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
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return construct_BST(nums,0,nums.size()-1);

    }
    TreeNode* construct_BST(vector<int>& nums,int left,int right){
        if(left>right)
            return nullptr;
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        if(left==right){    
            return root;
        }
        root->left = construct_BST(nums,left,mid-1);
        root->right = construct_BST(nums,mid+1,right);
        return root;
    }
};