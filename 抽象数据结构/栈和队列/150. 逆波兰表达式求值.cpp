/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-03 20:54:57
 */
// 输入：tokens = ["2","1","+","3","*"]
// 输出：9
// 解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
// 输入：tokens = ["4","13","5","/","+"]
// 输出：6
// 解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6

// 思路：遍历字符串，遇到数字字符串先转为数字，压入堆栈；遇到运算符，堆栈弹出两个数字进行运算再压栈。


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0;i<tokens.size();++i){
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/")
                stk.push(str2num(tokens[i]));
            else{
                int nums1 = stk.top();
                stk.pop();
                int nums2 = stk.top();
                stk.pop();
                int nums3;
                if(tokens[i]=="+")
                    nums3 = nums1+nums2;
                else if(tokens[i]=="-")
                    nums3 = nums2-nums1;
                else if(tokens[i]=="*")
                    nums3 = nums2*nums1;
                else if(tokens[i]=="/")
                    nums3 = nums2/nums1;
                stk.push(nums3);
            }
        }
        return stk.top();
    }

    int  str2num(string s){   
        int num;
        stringstream ss(s);
        ss>>num;
        return num;
    }
};