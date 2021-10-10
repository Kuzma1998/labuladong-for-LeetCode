// 给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
// 输入3
//输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]


// 这道题没做出来,之后再做一下
// 思路：明确根节点要干的事情，剩下交给递归 根节点要做的就是已经知道了左子树有几种情况，右子树有几种情况，那么一共有多少种情况就显而易见了
 


class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return buildTrees(1,n);
    }

    vector<TreeNode*> buildTrees(int start,int end){
        
        // 递归终止条件
        if(start>end)
            return {nullptr};

        vector<TreeNode*> allTrees;// 以start，end为区间建树一共有多少种

        // 分别以i作为根节点，建立左子树与右子树
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftTrees = buildTrees(start,i-1);//左子树有多少种
            vector<TreeNode*> rightTrees = buildTrees(i+1,end);//右子树有多少种树
            for(auto& l:leftTrees){
                for(auto&r:rightTrees){
                    TreeNode* root = new TreeNode(i); // 根节点要做的事情，对于每种情况都存进去
                    root->left = l;
                    root->right = r;
                    allTrees.push_back(root); 
                }
            }
        }
        return allTrees;
    }

}