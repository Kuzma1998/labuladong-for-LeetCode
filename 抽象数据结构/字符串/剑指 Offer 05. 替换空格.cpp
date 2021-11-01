// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
// 示例 1：
// 输入：s = "We are happy."
// 输出："We%20are%20happy."

// 方法1 o(n)空间复杂度
class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for(auto c:s){
            if(c!=' '){
                ans += c;
            }else{
                ans+="%20";
            }
        }
        return ans;
    }
};



// 方法2 o(1)空间复杂度
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        int old_size = s.size();
        for(auto c:s){
            if(c==' ')
                ++count;
        }
        int add_nums = 2*count;
        while(add_nums){
            s+=" ";
            --add_nums;
        }
        int new_length = s.size();
        for(int i=new_length-1,j=old_size-1;j<i;){
            if(s[j]!=' '){
                s[i--] = s[j--];
            }
            else{
                s[i--]='0';
                s[i--] = '2';
                s[i--] = '%';
                --j;
            }
        }   
        return s;
    }
};
