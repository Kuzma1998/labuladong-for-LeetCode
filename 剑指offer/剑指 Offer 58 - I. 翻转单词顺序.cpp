// 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，
// 标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

// 示例 1：
// 输入: "the sky is blue"
// 输出: "blue is sky the"

class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())
            return s;
        deleteSpace(s);
        if(s.empty())
            return s;
        reverseString(s,0,s.size()-1);
        //反转单词
        for(int i=0;i<s.size();){
            int left =i,right =i;
            while(right<s.size()&&s[right]!=' '){
                ++right;
            }
            reverseString(s,left,right-1);
            i = right+1;
        }
        return s;
    }
    // 删除空格 
    void deleteSpace(string& s){
        int sz = s.size();
        for(int i=0;i<sz-1;){
            if(s[i]==' '&&s[i]==s[i+1])
                s.erase(s.begin()+i);
            else
                ++i;
        }
        if(s[0]==' ')
            s.erase(s.begin());
        if(s.empty())// 注意判断是否为空
            return ;
        if(s[s.size()-1]==' ')
            s.erase(s.end()-1);
    }
    void reverseString(string& s,int start,int e){
        for(int i=start;i<e;++i,--e){
            char temp = s[i];
            s[i] = s[e];
            s[e] = temp;
        }
    }
};

// 从后往前双指针
class Solution {
public:
    string reverseWords(string s) {
        string res;
        int n = s.size();
        if(n == 0) return res;
        int right = n - 1;
        while(right >= 0){
            //从后往前寻找第一字符
            while(right >= 0 && s[right] == ' ') right--;
            if(right < 0) break;

            //从后往前寻找第一个空格
            int left = right;
            while( left >= 0 && s[left] != ' ' ) left--;

            //添加单词到结果
            res += s.substr(left + 1, right - left);
            res += ' ';

            //继续往前分割单词
            right = left;
        }
        //去除最后一个字符空格
        if (!res.empty()) res.pop_back();
        return res;
    }
};