/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-23 18:30:50
 */
// 给定一个经过编码的字符串，返回它解码后的字符串。
// 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
// 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
// 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
// 示例 1：
// 输入：s = "3[a]2[bc]"
// 输出："aaabcbc"
// 示例 2：
// 输入：s = "3[a2[c]]"
// 输出："accaccacc"
// 示例 3：
// 输入：s = "abc3[cd]xyz"
// 输出："abccdcdcdxyz"

// 数字栈 字符串栈

class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        stack<string> str;
        stack<int> nums;
        int num = 0;
        for(int i=0;i<s.size();++i){
            if(s[i]>='0'&&s[i]<='9'){
                num = 10*num + s[i]-'0'; //数字
            }
            else if(s[i]=='['){ //遇到左括号  加入数字，把当前字符串加入到栈以便累加
                nums.push(num); 
                str.push(ans);
                num=0;  //清空
                ans="";
            }
            else if(s[i]==']'){  //若遇到右括号 开始累加多次
                int times = nums.top();
                nums.pop();
                while(times--){
                    str.top() += ans;
                }
                ans = str.top();
                str.pop();
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};