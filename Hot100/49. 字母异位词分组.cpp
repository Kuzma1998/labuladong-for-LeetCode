/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-17 18:49:56
 */
// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
// 字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
// 示例 1:
// 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
// 哈希表+排序  含有相同字母的字符排序一样。作为key，而value则为排序前的string
// 然后遍历map的迭代器即可

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> map;
        for(auto str:strs){
            string temp = str;
            sort(temp.begin(),temp.end(),[](char& a,char& b){return a<b;});
            map[temp].push_back(str);
        }
        for(auto it=map.begin();it!=map.end();++it){
            ans.push_back((*it).second);
        }
        return ans;
    }
};