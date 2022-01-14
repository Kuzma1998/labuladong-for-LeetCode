// 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
// 如果可以，返回 true ；否则返回 false 。
// magazine 中的每个字符只能在 ransomNote 中使用一次。

// 输入：ransomNote = "a", magazine = "b"
// 输出：false

// 思路:数组代替哈希表，遍历两个字符串即可
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> res(26,0);
        for(auto i :ransomNote){
            res[i-'a'] += 1;
        }
        for(auto i:magazine){
            res[i-'a'] -= 1;
        }
        for(auto i :res){
            if(i>0)
                return false;
        }
        return true;
    }
};