/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-15 15:19:03
 */
// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
// 满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)//递归中止条件
            return root;
        if(root->val==p->val||root->val==q->val) //递归中止条件
            return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left&&right)//若一个根的左子树和右子树都等于p，q之间的一个，则返回root
            return root;
        return left?left:right;
    }
};


private HashMap<TreeNode, TreeNode> map; 
// map中key是树中的子节点，而value则是树中的父节点，用于快速从子节点找到父节点
    private Queue<TreeNode> queue;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
//        使用层次遍历，也就是广度优先遍历的思路进行结点与父节点的之间的连接
        map = new HashMap();
        queue = new LinkedList<>();

        if (root == null){
            return null;
        }

        queue.add(root);
        while (!queue.isEmpty()){
            TreeNode tmp = queue.remove();
            if (tmp.left != null){
                queue.add(tmp.left);
                map.put(tmp.left, tmp);
            }
            if (tmp.right != null){
                queue.add(tmp.right);
                map.put(tmp.right, tmp);
            }
        }

        TreeNode head1 = p;
        TreeNode head2 = q;

        while (head1 != head2){
            head1 = map.keySet().contains(head1) ? map.get(head1) : q;
             //根节点不在map里面，有一个向上找到了根结点，则变为另一个
            head2 = map.keySet().contains(head2) ? map.get(head2) : p;
        }

        return head1;
    }
}
