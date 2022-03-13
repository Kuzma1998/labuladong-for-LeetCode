// 给定一棵二叉搜索树，请找出其中第 k 大的节点的值。
// 示例 1:
// 输入: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// 输出: 4
// 遍历右根左从大到小    遍历完右边的时候 检查times是否为0，为0退出 ，否则递减times，若递减后为0 直接退出找到答案
class Solution {
private:
    int ans = 0;
    int times;
public:
    int kthLargest(TreeNode* root, int k) {
        times = k;
        preorder(root);
        return ans;
    }
    void preorder(TreeNode* root){
        if(!root||times<=0)
            return;
        preorder(root->right);
        if(--times==0){
            ans = root->val;
            return;
        }  
        preorder(root->left);
    }
};