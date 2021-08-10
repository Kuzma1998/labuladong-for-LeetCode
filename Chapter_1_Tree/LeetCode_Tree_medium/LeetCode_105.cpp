/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-07-29 14:45:31
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-08-07 22:41:41
 */

#include <iostream>
#include <algorithm>
#include<vector>
#include<unordered_map>
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
    TreeNode *BT(vector<int> preorder,int preStart,int preEnd,vector<int> inorder,int inStart,int inEnd)
    {
        if(preStart>preEnd||inStart>inEnd)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inroot;
        for(inroot =inStart;inorder[inroot]!=root->val;inroot++){
        }
        int numLeft = inroot-inStart;
        root->left = BT(preorder,preStart+1,preStart+numLeft,inorder,inStart,inroot-1);
        root->right = BT(preorder,preStart+1+numLeft,preEnd,inorder,inroot+1,inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        int preStart = 0;
        int inStart = 0;
        int preEnd = preorder.size() - 1;
        int inEnd = preEnd;
        TreeNode* root = BT(preorder,preStart,preEnd,inorder,inStart,inEnd);
        return root;
    } 
};


//前序遍历确定根结点，然后在中序遍历找到这个根结点，左边为左子树，右边为右子树
//然后递归建树、
//在中序遍历中对根节点进行定位时，一种简单的方法是直接扫描整个中序遍历的结果并找出根节点，但
//这样做的时间复杂度较高。我们可以考虑使用哈希表来帮助我们快速地定位根节点。对于哈希映射中的每个键值对，键表示一个元素（节点的值），值表示其在中序遍历中的出现位置。在构造二叉树的过程之前，我们可以对中序遍历的列表进行一遍扫描，就可以构造出这个哈希映射。在此后构造二叉树的过程中，我们就只需要 O(1)O(1) 的时间对根节点进行定位了。

// class Solution {
// private:
//     unordered_map<int, int> index;

// public:
//     TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
//         if (preorder_left > preorder_right) {
//             return nullptr;
//         }
        
//         // 前序遍历中的第一个节点就是根节点
//         int preorder_root = preorder_left;
//         // 在中序遍历中定位根节点
//         int inorder_root = index[preorder[preorder_root]];
        
//         // 先把根节点建立出来
//         TreeNode* root = new TreeNode(preorder[preorder_root]);
//         // 得到左子树中的节点数目
//         int size_left_subtree = inorder_root - inorder_left;
//         // 递归地构造左子树，并连接到根节点
//         // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
//         root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
//         // 递归地构造右子树，并连接到根节点
//         // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
//         root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
//         return root;
//     }

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int n = preorder.size();
//         // 构造哈希映射，帮助我们快速定位根节点
//         for (int i = 0; i < n; ++i) {
//             index[inorder[i]] = i;
//         }
//         return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
//     }
// };


int main(){
    int nums[8] = {7,6,5,4,3,2,1,0};
    unordered_map<int, int> index;
    for(int i = 0; i <=7;i++){
         index[nums[i]] = i;
    }
    int r = index[5];//元素五得下标
    cout<<r<<endl;
    
    
}