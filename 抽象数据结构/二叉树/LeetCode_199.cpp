
// 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
//题目意思就是找二叉树每一层的最右边那个结点
// 思路： 利用 BFS 进行层次遍历，记录下每层的最后一个元素。
// 时间复杂度： O(N)，每个节点都入队出队了 1 次。
// 空间复杂度： O(N)，使用了额外的队列空间。

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
    vector<int> RightSight{};
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return RightSight;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int l = q.size();
            TreeNode* r;
            for(int i=0;i<=l-1;++i){
                r = q.front();
                q.pop();
                if(r->left)
                    q.push(r->left);
                if(r->right)    
                    q.push(r->right);
            }
            RightSight.push_back(r->val);
        }
        return RightSight;
    }
};

// 我们按照 「根结点 -> 右子树 -> 左子树」 的顺序访问，就可以保证每层都是最先访问最右边的节点的。
//定义一个深度，保证每种深度的递归只会有一次添加


class Solution {
private:
    vector<int> RightSight{};
public:
    vector<int> rightSideView(TreeNode* root) {
        DFS(root,0);
        return RightSight;
    }
    void DFS(TreeNode* root, int depth){
        if(root==nullptr)
            return;
        if(RightSight.size()==depth){ //每种深度的结点只存一个;
            RightSight.push_back(root->val);
        }
        depth++;
        DFS(root->right,depth);
        DFS(root->left,depth);
    }
};