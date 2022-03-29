/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
Node* minv;
Node* maxv;
Node* pre;
Node* cur;
public:
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return root;
        minv = root;
        maxv = root;
        inorder(root);
        maxv->right = minv;
        minv->left = maxv;
        return minv;
    }
    void inorder(Node* root){
        if(!root)
            return;
        if(root->val<minv->val)
            minv = root;
        if(root->val>maxv->val)
            maxv = root;
        inorder(root->left);
        if(!pre) //pre为最左边的节点，赋初值
            pre = root;
        else{ //pre一直为root的前一个，由于是中序 因此是从大到小
            pre->right = root;
            root->left =pre;
            pre =root;
        }
        inorder(root->right);
    }
};