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
vector<string> vec;
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node){
                ans += "#,";
                continue;
            }else {
                ans+= to_string(node->val)+",";
            }
            q.push(node->left);
            q.push(node->right);
        }
        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return nullptr;
        str2char(data);
        return BT();
    }
    void str2char(string& data){
        int pre = 0;
        for(int i=0;i<=data.size();++i){
            if(data[i]==','||i==data.size()){
                vec.push_back(data.substr(pre,i-pre));
                pre =i+1;
            }
        }
    }
    TreeNode* BT(){
        if(vec.size()==0)
            return nullptr;
        TreeNode* root = new TreeNode(stoi(vec[0]));
        queue<TreeNode*> q;
        q.push(root);
        for(int i=1;i<vec.size();){
            TreeNode* node = q.front();
            q.pop();
            // if(!node)
            //     continue;
            if(vec[i]=="#"){
               node->left = nullptr;
               ++i;
            }else 
                node->left = new TreeNode(stoi(vec[i++]));
            if(i>=vec.size()) break;
            if(vec[i]=="#"){
                node->right = nullptr;
                ++i;
            }
            else{
                node->right = new TreeNode(stoi(vec[i++]));
            }
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right); 
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));