// 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
// B是A的子结构， 即 A中有出现和B相同的结构和节点值。
// 例如:
// 给定的树 A:
//      3
//     / \
//    4   5
//   / \
//  1   2
// 给定的树 B：
//    4 
//   /
//  1
// 返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值

// 依次存入A的节点到队列，判断队列的节点是否与B相等
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==NULL || B==NULL)
            return false;
        queue<TreeNode*> q;
        q.push(A);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            if(recur(node,B))
                return true;
        }
        return false;
    }
    bool recur(TreeNode* A, TreeNode* B){
        if(B==NULL)  return true;
        if(A==NULL||A->val !=B->val) return false;
        return recur(A->left,B->left) && recur(A->right,B->right);
    }
};

// 递归

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == NULL || A == NULL)
            return false;
        //遍历A中每个节点，A树中任一节点包含B就能返回true
        return iscontain(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    //包含：以A为根的数是否包含B（必须从A开始）
    bool iscontain(TreeNode* A, TreeNode* B){
        if(B == NULL)
            return true;
        if(A == NULL || A->val != B->val)
            return false;
        return iscontain(A->left, B->left) && iscontain(A->right, B->right);
    }
};