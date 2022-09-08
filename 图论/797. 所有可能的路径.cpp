/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-08-31 09:42:01
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2022-08-31 09:42:13
 */
// 给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）
//  graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。

// 示例 1：
// 输入：graph = [[1,2],[3],[3],[]]
// 输出：[[0,1,3],[0,2,3]]
// 解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3


class Solution {
    vector<vector<int>> results;
    vector<int> path;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph,0);
        return results;
    }
    void dfs(vector<vector<int>>& graph,int i){
        path.push_back(i);
        if(i==graph.size()-1){  
            // 到达终点
            results.push_back(path);
            path.pop_back();
            return;
        }
        for(auto edge:graph[i]){
            dfs(graph,edge);
        }
        // 图遍历弹出放到外面
        path.pop_back();
    }
};