// 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，
// 同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr){
            return "#";
        }
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    TreeNode* mydeserialize(istringstream &ss ){
        // istringstream对象可以绑定一行字符串，然后以空格为分隔符把该行分隔开来。
        string tmp;
        ss>>tmp;// 读取一个就少一个了
        if(tmp=="#"){
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(tmp));
        node->left = mydeserialize(ss);
        node->right = mydeserialize(ss);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return mydeserialize(ss);
    }
};



class Codec {
private:
    string data;
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        data = preorder(root);
        return data;
    }
    string preorder(TreeNode* root){
        if(!root){
            return "#";
        }
        return to_string(root->val)+","+preorder(root->left)+","+preorder(root->right);
    }
    // Decodes your encoded data to tree.
   
    queue<string> split(string str){
        //去除逗号为什么要这么写
        queue<string> ans;
        if (str.empty()) return ans;
        int size = str.size();
        int pre = 0;
        for (int i = 0; i <= size; ++i) {
            if (i == size || str[i] == ',') {
                ans.emplace(str.substr(pre, i-pre));
                pre = i+1;
            }
        }
        return ans;
    }

    TreeNode* buildTree(queue<string>& q){
        // 传入引用，立马变为指针常量，指针指向不能变，指向的指可以变
        if(q.empty())
            return nullptr;
        string temp = q.front();
        q.pop();
        if(temp=="#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(temp));
        root->left = buildTree(q);
        root->right = buildTree(q);
        return root;
    }
    TreeNode* deserialize(string data) {
        queue<string> q = split(data);
        return buildTree(q);
    }
};



// 层序遍历

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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* r = q.front();
            q.pop();
            if(r){
                data += to_string(r->val)+",";
            }else{
                data += "#,";
                continue;// 若没有这个跳出，则会死循环
            }
            q.push(r->left);
            q.push(r->right);
        }
        data.pop_back();
        return data;
    }

    vector<string> deleteSep(string& data){
        vector<string> q;
        int size = data.size();
        if(!data.size())
            return q;
        int pre = 0;
        for(int i=0;i<=size;i++){
            if(data[i]==','||i==size){
                q.push_back(data.substr(pre,1));
                pre = i+1;
            }
        }
        return q;
    }

    TreeNode* buildTree(vector<string>& que){
        if (que.empty())   return nullptr;
        string node = que[0];
        TreeNode* root = new TreeNode(stoi(node));
        queue<TreeNode*> q;
        q.push(root);

       for(int i =1; i < que.size(); ) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr)    continue;

            string s_left = que[i++];
            if (s_left == "#")
                node->left = nullptr;
            else
                node->left = new TreeNode(stoi(s_left));
            q.push(node->left);

            string s_right = que[i++];
            if (s_right == "#")
                node->right = nullptr;
            else
                node->right = new TreeNode(stoi(s_right));
            q.push(node->right);
        }
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v = deleteSep(data);
        return buildTree(v);
    }


};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));