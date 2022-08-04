// 给定一个二叉树，我们在树的节点上安装摄像头。
// 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
// 计算监控树的所有节点所需的最小摄像头数量。

// 贪心：叶子节点不能放摄像头，设计三种状态，2表示被摄像头覆盖，1表示安了摄像头，0表示没有被摄像头覆盖

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int result = 0;
public:
    int minCameraCover(TreeNode* root) {
        // 根节点左右两边都被覆盖，那么他自己要安装摄像头了
        if(postOrder(root)==0){
            result++;
        }
        return result;
    }

    // 后续遍历 要先看看左右孩子的情况 才能判断根节点是否需要安装
    int postOrder(TreeNode* root){
        if(!root){
            return 2;
        }
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        // 左右孩子都被摄像头覆盖了 此时该节点要是无覆盖的状态，因为要使得叶子节点不放摄像头
        if(left==2&&right==2){
            return 0;
        }else if(left==0||right==0){ // 左右孩子有一个没被覆盖，要在此节点安装摄像头
            ++result;
            return 1;
        }else if(left==1||right==1){ // 左右孩子有一个摄像头，不需要安装摄像头，被覆盖了
            return 2; 
        }
        return 0;
    }
};