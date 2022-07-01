// 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
// 一般来说，删除节点可分为两个步骤：
// 首先找到需要删除的节点；
// 如果找到了，删除它。
// 说明： 要求算法时间复杂度为 O(h)，h 为树的高度。


//思路，找到该节点，用右子树最小或者左子树最大来代替该节点，再删除该节点的子树的重复节点即可


class Solution {
public:
    int findRightMin(TreeNode* root){
        root = root->right;
        while(root->left)
            root =root->left;
        return root->val;
    }
    int findLeftMax(TreeNode* root){
        root = root->left;
        while(root->right)
            root =root->right;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        if(key>root->val){
            root->right = deleteNode(root->right,key);
        }
        else if(key<root->val){
            root->left = deleteNode(root->left,key);
        }
        else{
            if(!root->left&&!root->right)
                root = nullptr;
            else if(root->right){
                root->val = findRightMin(root);
                root->right = deleteNode(root->right,root->val);
            }
            else{
                root->val = findLeftMax(root);
                root->left = deleteNode(root->left,root->val);
            }
        }
        return root;
    }   
};


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        return Delete(root,key);
    }

    TreeNode* Delete(TreeNode* root,int key){
        if(!root)
            return root;
        // root->val > key的值  删除右边
        if(root->val>key){
            root->left = Delete(root->left,key);
        // root->val < key的值  删除左边
        }else if(root->val<key)
            root->right = Delete(root->right,key);
        // root->val = key  删除此节点
        else if(root->val==key){
            if(!root->right&&!root->left){  // 被删除的节点  无左右子树
                return nullptr;
            }else if(!root->right&&root->left){  //  被删除的节点 只有左子树
                return root->left;  
            }else if(!root->left&&root->left){  //  被删除的节点 只有右子树
                return root->right;
            }else{
                TreeNode* cur = root->right;  //把左子树插入右子树的最左边
                TreeNode* pre;
                while(cur){
                    pre = cur;
                    cur = cur->left;
                }
                pre->left = root->left;
            }
            return root->right;
        }
        return root;
    }
};