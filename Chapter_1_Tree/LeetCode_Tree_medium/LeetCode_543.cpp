// 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

//思路 后续遍历 维护一个全局变量gain= max(gain,当前结点的左子结点gain+右子结点gain+1)
//左gain为左子树深度，右gain为右子树深度，递归函数返回值则是左右最大的深度+1即改结点的深度
    //       1
    //      / \
    //     2   3
    //    / \     
    //   4   5 

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
private:
    int d=0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int height = getGain(root);//树高
        return d-1;//最后返回d-1
    }
    int getGain(TreeNode* root){
        if(root==nullptr)
            return 0;
        int left = getGain(root->left);
        int right = getGain(root->right);
        d= max(d,left+right+1);
        return max(left,right)+1;
    }
}
// 时间复杂度：O(N)，其中 N 为二叉树的节点数，即遍历一棵二叉树的时间复杂度，每个结点只被访问一次。

// 空间复杂度：O(Height))，其中 HeightHeight 为二叉树的高度。由于递归函数在递归过程中需要为每一层递归函数分配栈空间，
// 所以这里需要额外的空间且该空间取决于递归的深度，而递归的深度显然为二叉树的高度，并且每次递归调用的函数里又只用了常数个变量，
// 所以所需空间复杂度为 O(Height)。


//暴力法，求每个结点的增益 n2

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* r = q.front();
            q.pop();
            d = max(d,getGain(r->left)+getGain(r->right));
            if(r->left)
                q.push(r->left);
            if(r->right)
                q.push(r->right);
        }
        return d;
    }
    int getGain(TreeNode* root){
        if(root==nullptr)
            return 0;
        int left = getGain(root->left);
        int right = getGain(root->right);
        int gain = (left>right)?left:right;
        return gain+1;
    }
};