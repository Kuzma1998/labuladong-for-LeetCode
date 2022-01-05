// 给定一个二叉树，确定它是否是一个完全二叉树。
//思路，层序遍历，对一个结点，先把他的左右儿子加进去，再判断，若有右无左，false。若无右，则后面所有的结点不可以有左右儿子。


class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* r = q.front();
            q.pop();
            if(r->right&&!r->left){
                return false;
            }
            if(r->left){
                q.push(r->left);
            }
            if(r->right){
                q.push(r->right);
            }
            if(!r->right){
                for(int i=0;i<=q.size()-1&&!q.empty();i++){
                    TreeNode* other = q.front();
                    q.pop();
                    if(other->left||other->right){
                        return false;
                    }
                }
            }
            
        }
        return true;
    }

};
