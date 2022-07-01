// 给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。
// 通过修剪二叉搜索树，使得所有节点的值在[low, high]中。修剪树 不应该 改变保留在树中的元素的相对结构 
// (即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在 唯一的答案 。
// 所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return deleteNode(root,low,high);
    }
    TreeNode* deleteNode(TreeNode* root, int low ,int high){
        if(!root)  // 递归终点
            return nullptr;
        if(root->val>=low&&root->val<=high){  //在区间里面 继续递归
            root->left = deleteNode(root->left,low,high);
            root->right = deleteNode(root->right,low,high);
        }else if(root->val<low){  //根节点的值小于low 返回右边被删除的节点
            return deleteNode(root->right,low,high);
        }else if(root->val>high){  //根节点的值大于high  返回左边被删除的节点
            return deleteNode(root->left,low,high);
        }
        return root;
    }
};