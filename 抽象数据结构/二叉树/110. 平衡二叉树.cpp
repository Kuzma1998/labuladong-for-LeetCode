// 给定一个二叉树，判断它是否是高度平衡的二叉树。
// 本题中，一棵高度平衡二叉树定义为：
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1

//思路 遍历每个结点，求其左右子树高度差

 





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
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;   
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()&&flag==true){
            TreeNode* r = q.front();
            q.pop();
            int left = getHeight(r->left);
            int right = getHeight(r->right);
            if(abs(left-right)>1)
                flag = false;
            if(r->left)
                q.push(r->left);
            if(r->right)
                q.push(r->right);
            }
        return flag;
        }
    int getHeight(TreeNode* root){
        if(!root)
            return 0;
        int hl = getHeight(root->left);
        int hr = getHeight(root->right);
        int h = (hl>hr)? hl:hr;
        return 1+h;
    }
};


class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return max(height(root->left), height(root->right)) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else {
            return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
};





// 自底向上递归的做法类似于后序遍历，对于当前遍历到的节点，
// 先递归地判断其左右子树是否平衡，再判断以当前节点为根的子树是否平衡。
// 如果一棵子树是平衡的，则返回其高度（高度一定是非负整数），否则返回 -1。如果存在一棵子树不平衡，则整个二叉树一定不平衡。
// 时间复杂度：O(n)，其中 nn 是二叉树中的节点个数。使用自底向上的递归，每个节点的计算高度和判断是否平衡都只需要处理一次，
// 最坏情况下需要遍历二叉树中的所有节点，因此时间复杂度是 O(n)。
// 空间复杂度：O(n)，其中 nn 是二叉树中的节点个数。空间复杂度主要取决于递归调用的层数，递归调用的层数不会超过n。

class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/balanced-binary-tree/solution/ping-heng-er-cha-shu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
