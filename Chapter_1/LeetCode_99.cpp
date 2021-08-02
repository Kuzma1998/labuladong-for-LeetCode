//中序遍历是一个二叉搜索树是一个递增序列，若两个元素位置不对存在两种情况
//找到二叉搜索树中序遍历得到值序列的不满足条件的位置。
// 找到二叉搜索树中序遍历得到值序列的不满足条件的位置。
// 如果有两个，交换第一个与第二个的后一个
// 若只有一个，直接交换


#include <iostream>
#include <algorithm>
#include<vector>
#include<utility>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    /**
     * @name: 
     * @msg: 中序遍历
     * @param {TreeNode*} root
     * @return {*}
     */
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    /**
     * @name: 
     * @msg: 
     * @param {*}
     * @return {返回要交换的元素}
     */
    pair<int,int> findTwoSwapped(vector<int>& nums) {
        int n = nums.size();
        int x = -1, y = -1;
        for(int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] < nums[i]) {
                y = nums[i + 1];
                if (x == -1) {
                    x = nums[i];
                }
                else break;
            }
        }
        return {x, y};
    }
    
    /**
     * @name: 
     * @msg: 交换两个元素
     * @param {TreeNode*} r
     * @param {int} count
     * @param {int} x
     * @param {int} y
     * @return {*}
     */
    void recover(TreeNode* r, int count, int x, int y) {
        if (r != nullptr) {
            if (r->val == x || r->val == y) {
                r->val = r->val == x ? y : x;
                if (--count == 0) {
                    return;
                }
            }
            recover(r->left, count, x, y);
            recover(r->right, count, x, y);
        }
    }

    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        pair<int,int> swapped= findTwoSwapped(nums);
        recover(root, 2, swapped.first, swapped.second);
    }
};

