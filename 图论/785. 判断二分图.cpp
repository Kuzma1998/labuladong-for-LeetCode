/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-08-31 11:23:50
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2022-08-31 11:28:49
 */
class Solution {
    bool flag = true;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<bool> used(size,false);
        vector<int> colors(size,0);
        for(int i = 0; i < size; ++i){
            if(!used[i]){
                // 
                colors[i] = 2; //没遍历过的节点都染成2
                traverGraph(graph,1,i,used,colors); //邻居节点要染成1
                if(flag==false) return false; 
            }
        }
        return true;
    }
    void traverGraph(vector<vector<int>>& graph,int color,int node,vector<bool>& used,vector<int> colors){
        if(!flag) return;
        used[node] = true; // 已经遍历
        for(int neighboor : graph[node]){
            if(!used[neighboor]){
                if(color==1){  // 遍历邻居，
                    colors[neighboor] = 1; //染成1
                    traverGraph(graph,2,neighboor,used,colors); //下一个要染成2
                }else{
                    colors[neighboor] = color; 
                    traverGraph(graph,1,neighboor,used,colors);
                }
            }else{
                if(colors[neighboor]==colors[node]){ //如果某个节点已经访问过，直接比较颜色是否一样
                    flag = false;
                    return;
                }

            }
        }
    }
};