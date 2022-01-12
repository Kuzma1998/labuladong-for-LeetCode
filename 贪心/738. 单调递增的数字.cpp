// 给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。
// // （当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）
// 输入: N = 332
// 输出: 299

// 贪心，先转换字符串，然后从后往前遍历，因为只有后往前才能利用每次改变的结果实现贪心

class Solution {
public:
    string num2str(int i){
        stringstream ss;
        ss<<i;
        return string(ss.str());
    }
public:
    int monotoneIncreasingDigits(int n) {
        string str = num2str(n);
        int flag = -1;
        for(int i=str.size()-1;i>0;--i){
            if(str[i-1]>str[i]){
                str[i-1]--;
                flag = i;
            }
        }
        for(int i=flag;i<str.size();++i){
            str[i] = '9';
        }
        return stoi(str);
    }
};