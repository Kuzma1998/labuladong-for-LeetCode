// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
// 参考以下这颗二叉搜索树：
//      5
//     / \
//    2   6
//   / \
//  1   3
// 示例 1：
// 输入: [1,6,3,2,5]
// 输出: false
// 示例 2：
// 输入: [1,3,2,6,5]
// 输出: true


class Solution {
private:
    unordered_map<int,int> index;
public:
    bool verifyPostorder(vector<int>& postorder) {
        vector<int> inorder(postorder.begin(),postorder.end());
        sort(inorder.begin(),inorder.end());
        for(int i=0;i<inorder.size();++i){
            index[inorder[i]] = i;
        }
        return ;
    }
    bool dg(vector<int>& postorder,int post_root_index ,vector<int>& inorder,int in_left,int in_right){
      int root = postorder[post_root_index];
        int root_in = index[root];
        int left = in_right-root-1;
        int right= root-in_left;
        for(int i=post_root_index-1,i>=post_root_index-right;r;--i){
            if(postorder[i]<root)
                return false;
        }
        for(int i=post_root_index-right-1;i>=post_root_index-right-left;--i){
            if(post_root_index[i]>index)
                return false;
        }
        return false;
    }
};

// 思路  bst后续遍历 根节点在最后面，且分块，前一块小于根，后一块大于根

class Solution {
private:
    unordered_map<int,int> index;
public:
    bool verifyPostorder(vector<int>& postorder) {
        return dg(postorder,0,postorder.size()-1);
    }
    bool dg(vector<int>& postorder,int l,int r){
        if(l>=r)
            return true;
        int cut = l;
        // 小于根节点
        while(postorder[cut]<postorder[r]){// 前一块
            ++cut;
        }
        int temp = cut;
        while(postorder[temp]>postorder[r]){//后一块
            ++temp;
        }
        return temp==r && dg(postorder,l,cut-1)&& dg(postorder,cut,r-1);
    }
};