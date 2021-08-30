// 给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
// 两棵树重复是指它们具有相同的结构以及相同的结点值。
// 示例 1：

//         1
//        / \
//       2   3
//      /   / \
//     4   2   4
//        /
//       4
// 下面是两个重复的子树：

//       2
//      /
//     4
// 和
//     4

// 思路：要找到重复子树，那么我得知道以root为根的树长啥样子，方法是利用后序遍历，将其转化为字符串
// 比如
//       2
//      /   变为  4#2这个字符串,想知道是否有相同子树，则要把之前遍历过的子树的字符串都加入到一个数据结构里面存起来
//     4

// 定义一个哈希表存字符串，一个列表存根节点，当字符串从未出现在哈希表里面时，把它对应的键变为0，等再次出现时，加1；
// 当键值第一次等于1时把根节点存进去即可，因为我们只需村一次相同的节点


class Solution {
private:
    vector<TreeNode*> list;
    unordered_map<string,int> memo;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        descriptionTree(root);
        return list;
    }
    string descriptionTree(TreeNode* root){
        if(!root)
            return "#";
        string desRoot = descriptionTree(root->left)+","+
        descriptionTree(root->right)+","   +to_string(root->val);
        if(!memo.count(desRoot)){
            memo[desRoot] = 0;
        }else{
            memo[desRoot] += 1;
        }
        if(memo[desRoot]==1){
            list.push_back(root);
        }
        return desRoot;
    }


};