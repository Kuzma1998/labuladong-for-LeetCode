// 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，
// 同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。

// 输入：S = "ababcbacadefegdehijhklij"
// 输出：[9,7,8]
// 解释：
// 划分结果为 "ababcbaca", "defegde", "hijhklij"。
// 每个字母最多出现在一个片段中。
// 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

// 思路：
// 贪心，先遍历一次求出每个字符串的最后索引
// 然后定义一个长度=0，一个索引=0
// 遍历字符串，每次都更新长度，当长度小于当前的左边时，长度-索引压入数组，更新长度

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 哈希表更新某个字母最后出现的位置
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();++i){
            if(!mp.count(s[i]))
                mp[s[i]] = i;
            else{
                mp[s[i]] = i;
            }
        }
        vector<int> ans;
        int l = mp[s[0]];//定义长度
        int last;//定义索引
        for(int i=0;i<s.size();++i){
            // 贪心  当i大于长度时，把长度压入数组，说明后面的这一段字符串后面再也不会出现了
            if(i>l){
                if(ans.size()==0)
                    ans.push_back(l+1);
                else{
                    ans.push_back(l+1-last);
                }
                last = i;//更新last
            }
            l = max(l,mp[s[i]]);//更新l
        }
        ans.push_back(l+1-last);
        return ans;
    }
};