/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-09-06 10:34:05
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2022-09-06 21:40:41
 */

// 判断图是否有环

// dfs
class Solution {
    using vii = vector<vector<int>>;
    vector<bool> curPath;
    vector<bool> visited;
    bool flag = true;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vii graph = buildGraph(prerequisites, numCourses);
        curPath = vector<bool>(graph.size(),false);
        visited = vector<bool>(graph.size(),false);
        for(int i = 0 ; i < numCourses; ++i){
            if(!visited[i])
                traverGraph(graph,i);
            if(flag==false) return false;

        }
        return true;
    }

    vii buildGraph(vector<vector<int>>& prerequisites, int numCourses){
        vii graph(numCourses);
        for(auto prerequisite : prerequisites){
            int from = prerequisite[1];
            int to = prerequisite[0];
            graph[from].push_back(to);
            // graph[to].push_back(from);
        }
        return graph;
    }

    void traverGraph(vii& graph, int node){
        // 此次遍历已经访问过此节点 说明有环
        if(curPath[node]){
            flag = false;
            return;
        }
        // 如果已经成环或者之前访问过此节点 返回
        if(flag==false||visited[node]) return;
    
        curPath[node] = true;
        visited[node] = true;

        for(auto neighbour : graph[node]){
            traverGraph(graph,neighbour);
        }
        curPath[node] = false;
    }
    
};


// bfs

class Solution {
    using vvi = vector<vector<int>>;
   vector<int> indegree; // 入度表
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        indegree.resize(numCourses);
        vvi graph = buildGraph(prerequisites, numCourses);
        queue<int> q;
        for(int i = 0; i < numCourses; ++i){
            if(indegree[i]==0){
                q.push(i);// 入度为0的加入队列
            }
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ++count;//每遍历一个节点+1
            for(int neighbour : graph[node]){
                indegree[neighbour]--; //入度-1
                if(indegree[neighbour]==0){
                    q.push(neighbour); //入度为0加入队列
                }
            }
        }
        return count == numCourses;
    }

    vvi buildGraph(vector<vector<int>>& prerequisites, int numCourses){
        vvi graph(numCourses);
        for(auto prerequisite : prerequisites){
            int from = prerequisite[1];
            int to = prerequisite[0];
            graph[from].push_back(to);
            indegree[to]++;
            // graph[to].push_back(from);
        }
        return graph;
    }

    
};