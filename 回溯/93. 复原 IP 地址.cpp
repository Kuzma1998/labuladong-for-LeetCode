

class Solution {
private:
    vector<string> results; 
public:
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0);
        return results;
    }

    void backtrack(string s,int index,int times){
        if(times==3){ // 最多插入三次
            if(index<s.size()&&isValidNumber(s.substr(index))) // 最后一部分是否合法
                results.push_back(s);
            return;
        }
        for(int i=index;i<s.size();++i){
            string str = s.substr(index,i-index+1); //位置i合法
            if(isValidNumber(str)){
                s.insert(i+1, ".");  // i后面插入一个点 相当于i+1前面插入一个
                backtrack(s, i+2, times+1);
                s.erase(s.begin()+i+1); //删除i位置的点
            } 
        }
    }

    bool isValidNumber(string s){
        int length = s.size();
        if(s[0]=='0'&&length>1)  // 不含前导0
            return false;
        int num = 0;
        for(int i=0;i<length;++i){
            if(s[i]<'0'||s[i]>'9'){
                return false;
            }else{
                num =  num*10+s[i]-'0';
            }
            if(num>255) return false;
        }
        return true;
    }
};