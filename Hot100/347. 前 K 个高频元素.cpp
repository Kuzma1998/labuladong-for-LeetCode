// 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,pair<int,int>> mp;
        for(auto num:nums){
            mp[num].first = num;
            mp[num].second++;
        }
        vector<pair<int,int>> hash;
        vector<int> ans;
        for(auto elem:mp){
            hash.push_back(elem.second);
        }
        sort(hash.begin(),hash.end(),[](pair<int,int> a,pair<int,int>b){return a.second>b.second;});
        for(int i=0;i<k;++i){
            ans.push_back(hash[i].first);
        }
        return ans;
    }
};