// 请实现两个函数，分别用来序列化和反序列化二叉树。
// 你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 
// 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
// 提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 
// 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    string data;
    vector<string> vec;
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node){
                data += to_string(node->val)+",";
            }else{
                data += "#,";
                continue;
            }
            q.push(node->left);
            q.push(node->right);
        }
        data.pop_back();// 删除逗号
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;
        deleteSep();
        return buildTree();
    }
    TreeNode* buildTree(){
        if(vec.size()==0)
            return NULL;
        TreeNode* root = new TreeNode(stoi(vec[0]));
        queue<TreeNode*> q;
        q.push(root);
        for(int i=1;i<vec.size();){
            TreeNode* node = q.front();
            q.pop();
            if(!node)
                continue;
            string left = vec[i++];
            if(left=="#")
                node->left =NULL;
            else
                node->left = new TreeNode(stoi(left));
            q.push(node->left);
            string right = vec[i++];
            if(right=="#")
                node->right =NULL;
            else
                node->right = new TreeNode(stoi(right));
            q.push(node->right);
        }
        return root;

    }
    void deleteSep(){
        int pre = 0;
        for(int i=0;i<=data.size();i++){// 只有这样才能保留负数或者多位数
            if(data[i]==','||i==data.size()){
                vec.push_back(data.substr(pre,i-pre));// 起始位置取len个
                pre = i+1;
            }
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));