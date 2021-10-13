/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-13 08:59:06
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-13 13:22:41
 */
// 给定一个包含 [0，n) 中不重复整数的黑名单 blacklist ，写一个函数从 [0, n) 中返回一个不在 blacklist 中的随机整数。
// 对它进行优化使其尽量少调用系统方法 Math.random() 。
// 提示:
// 1 <= n <= 1000000000
// 0 <= blacklist.length < min(100000, N)
// [0, n) 不包含 n ，详细参见 interval notation 。


// 思路：利用哈希表把blacklist的数映射到争取的地方，先求出查找的范围，size=n-blacklist.size，只在此范围搜寻，若blacklist有大于此范围的则直接
// 被跳过了，然后利用把blacklist的元素添加至哈希表，在把哈希表的元素的值修改至正确的地方。


class Solution {
private:
    unordered_map<int,int> map;
    int size;
public:
    Solution(int n, vector<int>& blacklist) {
        // 正常元素的个数
        size=n-blacklist.size();
        // 标记黑名单的人
        for(auto elem : blacklist){
                map[elem]=666;
        }

        int last=n-1;
        for(auto elem:blacklist){
            // 若黑名单的数大于等于size，直接不管，因为我们搜寻的范围不在此
            if(elem>=size)
                continue;
            // 对于0到size-1的黑名单的数，映射到正确的地方
            while(map.count(last)){
                --last;
            }
            map[elem] =last;
            --last;
        }
        
    }
    
    int pick() {
        int ans =rand()%size;
        if(map[ans])
            return map[ans];
        return ans;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */