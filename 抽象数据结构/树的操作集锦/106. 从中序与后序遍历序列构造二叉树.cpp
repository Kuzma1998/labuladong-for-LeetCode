// 根据一棵树的中序遍历与后序遍历构造二叉树。
// 注意:
// 你可以假设树中没有重复的元素。
// 例如，给出
// 中序遍历 inorder = [9,3,15,20,7]
// 后序遍历 postorder = [9,15,7,20,3]
// 返回如下的二叉树：

//     3
//    / \
//   9  20
//     /  \
//    15   7

// 递归，注意与105的区别

class Solution {
private:
    unordered_map<int,int> index; // 为了很快从中序数组里找到根节点的索引
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<=inorder.size()-1;i++){
            index[inorder[i]]  = i;
        }
        return BT(inorder,postorder,0,inorder.size()-1,0,inorder.size()-1);

    }
    TreeNode* BT(vector<int>& inorder, vector<int>& postorder,
    int inStart,int inEnd,int pStart,int pEnd){
        // 递归终止条件
        if(pStart>pEnd) 
            return nullptr;
            //  建立根节点
        TreeNode* root = new TreeNode(postorder[pEnd]);
        // 在中序数组找根节点并求出左子树长度
        int in_root = index[postorder[pEnd]];
        int left_length = in_root-inStart;
        // 递归建立左右子树
        root->left = BT(inorder,postorder,inStart,in_root-1,pStart,pStart+left_length -1);
        root->right = BT(inorder,postorder,in_root+1,inEnd,pStart+left_length,pEnd-1);
        return root;
    }
};
