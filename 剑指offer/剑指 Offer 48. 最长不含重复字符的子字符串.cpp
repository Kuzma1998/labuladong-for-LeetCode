// 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。


// hash 双指针
class Solution {
private:
    unordered_set<char> map;
public:
    int lengthOfLongestSubstring(string s) {
        if(0==s.size())
            return 0;
        int l =0;//右指针
        int ans = 1;
        for(int i=0;i<s.size();++i){
            while(l<s.size()&&!map.count(s[l])){
                map.insert(s[l]);
                ++l;//右指针移动
            }
            ans = max(ans,l-i);
            if(l==s.size())
                break;
            map.erase(s[i]);//左值针移动到右指针的位置
        }
        return ans;
    }
};