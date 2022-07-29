class Solution {
    vector<string> ans;
    //  起始机场   到达机场，航班次数
    unordered_map<string,map<string,int>> memo;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket:tickets){
            memo[ticket[0]][ticket[1]]++;
        }
        // 加入起始机场
        ans.push_back("JFK");
        backtrack(tickets);
        return ans;
    }

    bool backtrack(vector<vector<string>>& tickets){
        // 找到一条路径 退出
        if(ans.size()==tickets.size()+1){
            return true;
        }
        // 以上一个机场作为起始机场，遍历它所有的目的机场
        for(auto &p:memo[ans.back()]){
            // p.second代表是否已经遍历过，如果遍历过了就不遍历了防止出现死循环
            if(p.second>0){
                // 回溯
                p.second--;
                ans.push_back(p.first);
                // 找到一条路径 返回
                if(backtrack(tickets)) return true;
                // 没找到  回溯 重新找
                ans.pop_back();
                p.second++;
            }
        }
        return false;
    }
};