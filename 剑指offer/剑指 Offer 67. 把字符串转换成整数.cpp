/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-14 21:20:05
 */
// 写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。
// 首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
// 当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，
// 作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
// 该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
// 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
// 在任何情况下，若函数不能进行有效的转换时，请返回 0。
// 说明：
// 假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。
// 如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

class Solution {
public:
    int strToInt(string str) {
        if(str.size()==0)
            return 0;
        string s= "";
        deleteSpace(str);//删除前面空格
        if(str.size()==0)
            return 0;
        if(str[0]>'9'||str[0]<'0'){ //如果第一个不是数字或者正负号 返回
            if(str[0]!='+'&&str[0]!='-')
                return 0;
        }
        string s1="";
        bool flag = false;
        bool isnum = false;
        for(auto c:str){//获得需要的部分
            if(c>='0'&&c<='9'){//一旦出现数字就要把数字符置为true
                s1 += c;
                isnum = true;
            }else if(!flag&&!isnum&&(c=='+'||c=='-')){//只能有一个正负号且要出现在数字前面
                s1 += c;
                flag = true;
            }else if((c=='+'||c=='-')&&isnum){//出现数字再出现正负号就不行了
                break;
            }else if((c=='+'||c=='-')&&flag){//只能有一个正负
                break;
            }else
                break;
        }
        return str2num(s1);
    }
    int str2num(string str){
        stringstream ss(str);
        int num;
        ss>>num;
        if(num>INT_MAX)
            return INT_MAX;
        if(num<INT_MIN)
            return INT_MIN;
        return num;
    }
    void deleteSpace(string& str){
        while(str.size()!=0&&str[0]==' ')
            str.erase(str.begin());
    }
};