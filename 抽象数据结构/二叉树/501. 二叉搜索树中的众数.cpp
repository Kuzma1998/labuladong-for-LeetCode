// 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
// 如果树中有不止一个众数，可以按 任意顺序 返回。

// 中序遍历  一次遍历即可

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        // 中序遍历  
        int count = 0;  //当前的最大次数
        int maxCount = 0; //全局最大
        TreeNode* pre = nullptr; //上一节点
        TreeNode* cur = root; // 当前节点
        stack<TreeNode*> s;
        vector<int> ans;
        while(!s.empty()||cur){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            if(!s.empty()){
                cur= s.top();
                s.pop();
                if(pre==nullptr)  //第一次遍历到最左边
                    count = 1;
                else if(pre->val==cur->val)
                    count++;
                else count =1;
                if(count==maxCount) //count和全局次数一样
                    ans.push_back(cur->val);
                if(count>maxCount){ //count 大于全局
                    maxCount = count;
                    ans.clear();
                    ans.push_back(cur->val);
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return ans;
    }
};