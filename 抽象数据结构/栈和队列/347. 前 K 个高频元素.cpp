/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-07 09:07:35
 */
// 思路：利用map存频率，利用优先队列进行排序

class Solution {
public:
    vector<int> topKFrequent(vector<int> nums, int k) {
        unordered_map<int,int> map;
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(auto i:nums){
            if(map.count(i))
                map[i]++;
            else
                map[i] =1;
        }
        for(auto v:map){
            pair<int,int> p(v.second,v.first);
            pq.push(p);
        }
        for(int i=0;i<k;++i){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};