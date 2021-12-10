//层序遍历

//思路,利用队列，每次取出队列中所有的元素加入数组，并把这些取出的元素的孩子都加入队列  BFS

#include <iostream>
#include <algorithm>
#include<vector>
#include<utility>
#include <queue>
#include<stack>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> nums;
        if(!root)
            return nums;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int l = q.size();
            vector<int> num(l);
            for(int i=0;i<=l-1;++i){
                TreeNode* r= q.front();
                q.pop();
                num[i] = r->val;
                if(r->left)
                    q.push(r->left);
                if(r->right)
                    q.push(r->right); 
            }
            nums.push_back(num);
        }
        return nums;
    }
};