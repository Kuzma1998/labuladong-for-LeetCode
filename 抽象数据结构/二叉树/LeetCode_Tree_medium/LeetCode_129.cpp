// 给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
// 每条从根节点到叶节点的路径都代表一个数字：
// 例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
// 计算从根节点到叶节点生成的 所有数字之和 。
// 叶节点 是指没有子节点的节点。

//深度优先搜索,维护一个全局变量sum记录节点的和，维护一个字符串s用于转换成整数，到叶节点就把s转换成整数，未到则继续递归



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
    int sum = 0;
    string s;
public:
    int sumNumbers(TreeNode* root) {
        DFS(root);
        return sum;
    }
    void DFS(TreeNode* root){
        if(!root)
            return;
        s += to_string(root->val);
        if(!root->left&&!root->right)
            sum += stoi(s);
        DFS(root->left);
        DFS(root->right);
        s.pop_back(); 
    }
};

// 时间复杂度：O(n)其中 n 是二叉树的节点个数。对每个节点访问一次。

// 空间复杂度：O(n)，其中 n 是二叉树的节点个数。空间复杂度主要取决于递归调用的栈空间，递归栈的深度等于二叉树的高度，
// 最坏情况下，二叉树的高度等于节点个数，空间复杂度为 O(n)O(n)。


// 使用广度优先搜索，需要维护两个队列，分别存储节点和节点对应的数字。
// 初始时，将根节点和根节点的值分别加入两个队列。每次从两个队列分别取出一个节点和一个数字，进行如下操作：
// 如果当前节点是叶子节点，则将该节点对应的数字加到数字之和；
// 如果当前节点不是叶子节点，则获得当前节点的非空子节点，并根据当前节点对应的数字和子节点的值计算子节点对应的数字，
// 然后将子节点和子节点对应的数字分别加入两个队列。
// 搜索结束后，即可得到所有叶子节点对应的数字之和


class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int sum = 0;
        queue<TreeNode*> nodeQueue;
        queue<int> numQueue;
        nodeQueue.push(root);
        numQueue.push(root->val);
        while (!nodeQueue.empty()) {
            TreeNode* node = nodeQueue.front();
            int num = numQueue.front();
            nodeQueue.pop();
            numQueue.pop();
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            if (left == nullptr && right == nullptr) {
                sum += num;
            } else {
                if (left != nullptr) {
                    nodeQueue.push(left);
                    numQueue.push(num * 10 + left->val);
                }
                if (right != nullptr) {
                    nodeQueue.push(right);
                    numQueue.push(num * 10 + right->val);
                }
            }
        }
        return sum;
    }
};
