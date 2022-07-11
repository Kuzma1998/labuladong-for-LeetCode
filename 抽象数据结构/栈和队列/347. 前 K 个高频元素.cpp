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




class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> memo; //数据+频率
        for(int num:nums){
            memo[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> q; // 小顶堆
        for(auto iter=memo.begin();iter!=memo.end();++iter){
            auto p = *iter;
            if(q.size()<k){
                q.push(p); //堆小于k，都放进去
            }else{
                if(p.second>q.top().second){
                    q.pop(); //若堆满了，则比较当前频率是否大与堆里面最小的
                    q.push(p);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
    struct compare{ // 小顶堆
        bool operator()(pair<int, int> a, pair<int, int> b){   
            return a.second>b.second;
        }
    };
};