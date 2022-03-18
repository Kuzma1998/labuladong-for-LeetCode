/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-18 19:37:40
 */
// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
// 注意：
// 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
// 如果 s 中存在这样的子串，我们保证它是唯一的答案。
// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"

思路：滑动窗口 窗口要包含t，当没包含t的时候一直递增right，然后增加left，看看减少之后的窗口是否还包含t，更新结果

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())
            return "";
        int r =0, l =0;// 左右指针
        unordered_map<char,int> count,need;
        for(auto c:t)
            count[c]++;
        int cou_len = 0;  //  滑动窗口计数器的长度
        int len = INT_MAX; // 字串长度
        int start = 0; // 子串起始位置
        while(r<s.size()){
            char c = s[r];
            r++;
            if(count.count(c)){//count 里面出现的字符才计数
                need[c]++;
                if(need[c]==count[c]) // 相同长度字符出现直接把长度加1
                    ++cou_len;
            }
        
            while(cou_len==count.size()){ //当滑动窗口维持的包括t
                if(r-l<len){
                    start = l;  
                    len = r-l;//记录长度和起始位置
                }
                char rev = s[l];
                ++l;
                if(count.count(rev)){  //移动l 当移动了t里面的元素
                    need[rev]--;
                    if(count[rev]>need[rev]) 
                        --cou_len;
                }
            }
        }
        return len==INT_MAX? "":s.substr(start,len);
    }
};