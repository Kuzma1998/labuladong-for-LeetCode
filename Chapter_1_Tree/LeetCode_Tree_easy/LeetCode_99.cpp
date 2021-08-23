//中序遍历是一个二叉搜索树是一个递增序列，若两个元素位置不对存在两种情况
//找到二叉搜索树中序遍历得到值序列+

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
    void inorder(TreeNode* root,vector<int>& nums){//引用,相当于指针常量,指向不可以便
        if(root==nullptr)
            return;
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }

    pair<int,int> FindTwoNum(vector<int>& nums){
        int x=-1;
        int y=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]){
                y = nums[i+1];
                if(x==-1){
                    x = nums[i];
                }else{
                    break;
                }
            }
        }
        return {x,y};
    }
    
    void recoverTwoNum(TreeNode* root,int count,int x,int y){
        if(root==nullptr)
            return;
        if(root->val==x||root->val==y){
            root->val=(root->val==x)?y:x;
            if(--count==0)
                return;
        }
        recoverTwoNum(root->left,count,x,y);
        recoverTwoNum(root->right,count,x,y);
    }

    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root,nums);
        pair<int,int> TwoNum = FindTwoNum(nums);
        recoverTwoNum(root,2,TwoNum.first,TwoNum.second);
    }
};
