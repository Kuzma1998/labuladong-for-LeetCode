/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-09-07 15:18:10
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2022-09-07 15:19:27
 */

// BFS 拓扑排序  找到所有的课程顺序
class Solution {
    using vvi = vector<vector<int>>;
    vvi graph;
    vector<int> indegree;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        indegree.resize(numCourses);
        buildGraph(prerequisites);
        vector<int> ans;
        queue<int> q;
        int count = 0;
        for(int i = 0; i < numCourses; ++i){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            ans.push_back(node);
            for(auto neighbour : graph[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }

        if(count==numCourses)
            return ans;
        return {};
    }

    void buildGraph(vector<vector<int>>& prerequisites){
        for(auto prerequisite : prerequisites){
            int from = prerequisite[1];
            int to = prerequisite[0];
            graph[from].push_back(to);
            indegree[to]++;
        }
        return;
    }
};