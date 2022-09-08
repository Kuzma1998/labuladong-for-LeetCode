/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-08-31 14:58:36
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2022-08-31 14:58:43
 */
class Solution {
    using vvi = vector<vector<int>>;
    bool flag = true;
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vvi graph = buildGraph(dislikes,n);
        vector<bool> visited(n+1,false);
        vector<int> colors(n+1,0);
        for(int i = 1; i <= n; ++i){
            if(!visited[i]){
                colors[i] = 2;
                traverGraph(graph,colors,visited,1,i);
                if(!flag) return false;
            }
        }
        return true;
    }
    // 判断二分图
    void traverGraph(vvi& graph,vector<int>& colors,vector<bool>& visited,int color,int node){
        if(!flag) return;
        if(node==graph.size()) return;
        visited[node] = true;
        for(auto neighbour : graph[node]){
            if(!visited[neighbour]){
                if(color==1){
                    colors[neighbour] = color;
                    traverGraph(graph,colors,visited,2,neighbour);
                }else{
                    colors[neighbour] = color;
                    traverGraph(graph,colors,visited,1,neighbour);
                }
            }else{
                if(colors[neighbour]==colors[node]){
                    flag = false;
                    return;
                }
            }
        }
    }

    // 建立图
    vvi buildGraph(vector<vector<int>>& dislikes,int n){
        vvi graph(n+1);
        for(auto edge:dislikes){
            int first = edge[0];
            int second = edge[1];
            int from = min(first,second),to = max(first,second); 
            graph[from].push_back(to);
            graph[to].push_back(from);

        }
        return graph;
    }
};