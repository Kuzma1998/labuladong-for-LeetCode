// 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。

//思路 中序遍历把节点存入数组即可


class Solution {
private:
    vector<int> nums;
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return nums[k-1];
    }
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
};
