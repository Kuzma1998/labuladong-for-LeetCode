// 给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：
// 二叉树的根是数组 nums 中的最大元素。
// 左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
// 右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
// 返回有给定数组 nums 构建的 最大二叉树 。
 
// 递归  递归函数定义，对于给定数组以及区间，建立题目需求的最大二叉树。
// 递归终止条件 传入数组区间为空
// 递归框架，肯定要先把根节点建出来，再建左右子树。先序遍历
// 最关键的，根节点干啥？找到区间最大元素建立根节点，因此先要找到最大的数以及索引，递归的建立左右子树。






class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildBST(nums,0,nums.size()-1);
    }
    TreeNode* buildBST(vector<int>& nums,int start,int end){
        if(start>end)
            return nullptr;
        // 找到区间内的最大数以及索引
        int max_index = -1;
        int max = -1;
        for(int i=start;i<=end;i++){
            if(nums[i]>max){
                max_index = i;
                max = nums[i];
            }
        }
        TreeNode* root = new TreeNode(max);
        root->left = buildBST(nums,start,max_index-1);
        root->right = buildBST(nums,max_index+1,end);
        return root;
    }
};
