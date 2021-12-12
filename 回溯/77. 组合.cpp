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