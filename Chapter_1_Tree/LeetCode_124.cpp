/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-07-29 10:00:23
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-08-04 08:50:03
 */

//最大路径和
#include<iostream>
#include<algorithm>
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
    int MaxSum= -10000;
    
public:
    int postorder(TreeNode* root){
            if(root==nullptr)
                return 0;
            int left = max(postorder(root->left),0);//左子结点 增益
            int right = max(postorder(root->right),0);//右子结点增益
            MaxSum = max(MaxSum,left+right+root->val);//后续遍历更新Maxsum
            return root->val+max(left,right);//返回此结点的增益
        }
    int maxPathSum(TreeNode* root) {
        postorder(root);
        return MaxSum;
    
    }
};


// 每个结点定义一个增益，gain = 根结点的值+max(左子结点增益,右子结点增益)
// 叶节点的增益就是本身
// 维护一个私有属性最大路径，最大路径用后续遍历进行更新 path= max(path+当前根结点的值+左增益+右增益)