/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-12 16:04:25
 */

// 根本无需used函数，因为我选取了当前只会再往后面选

class Solution {
private:
    vector<vector<int>> ans;

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<bool> used(n,false);
        trackback(1,k,n,path,used);
        return ans;
    }

    void trackback(int index,int k,int n,vector<int> path,vector<bool>& used){
        if(path.size()==k){
            ans.push_back(path);
            return;
        }
        for(int i=index;i<=n;++i){
            if(used[i-1])
                continue;
            used[i-1] = true;
            path.push_back(i);
            trackback(i+1,k,n,path,used);
            used[i-1] = false;
            path.pop_back();
        }
    }
};

// 写法2:

class Solution {
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i); // 处理节点 
            backtracking(n, k, i + 1); // 递归
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear(); // 可以不写
        path.clear();   // 可以不写
        backtracking(n, k, 1);
        return result;
    }
};


// 剪枝
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) { 
            // 优化的地方来举一个例子，n = 4，k = 4的话，那么第一层for循环的时候，
        // 从元素2开始的遍历都没有意义了。 在第二层for循环，从元素3开始的遍历都没有意义了。
            path.push_back(i); // 处理节点
            backtracking(n, k, i + 1);
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
public:

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};