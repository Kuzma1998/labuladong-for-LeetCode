/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-09-08 09:57:59
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2022-09-08 09:58:06
 */
class Solution {
    struct UnionFind{
        int size;
        vector<int> parents;
        UnionFind(int n) : size(n) {
            parents.resize(n);
            for(int i = 0; i < n ; ++i){
                parents[i] = i;
            }
        }

        void unions(int p,int q){
            int rootP = find(p), rootQ =find(q);
            if(rootP == rootQ){
                return ;
            }
            parents[rootP] = rootQ;
            size--;
            return;
        }

        int find(int x){
            if(x != parents[x]){
                parents[x] = find(parents[x]);
            }
            return parents[x];
        }

        bool connect(int p, int q){
            return find(p) == find(q);
        }
    };
public:
    bool equationsPossible(vector<string>& equations) {
        // 并查集
        UnionFind uf(26);
        // 联通相等的字母
        for(auto equation: equations){
            if(equation[1]=='='){
                uf.unions(equation[0]-'a',equation[3]-'a');
            }
        }
        // 判断不相等的字母，如果联通了返回false
        for(auto equation : equations){
             if(equation[1]=='!'){
                if(uf.connect(equation[0]-'a',equation[3]-'a'))
                    return false;
            }
        }
        return true;
    }
};