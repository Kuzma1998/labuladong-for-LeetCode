class Solution {
public:
    bool isNumber(string s) {
       deleteSpace(s);
       bool isDot = false,ise_or_E = false,isNum = false;
       for(int i=0;i<s.size();++i){
            if(isdigit(s[i]))
                isNum =  true;//遇到数值，变为true
            else if(s[i]=='.'){
                if(isDot||ise_or_E) return false;//点不能有两个且点之前不能有E
                isDot =  true;
            }
            else if(s[i]=='e'||s[i]=='E'){//e之前得有数值且不能有第二个E
                if(!isNum||ise_or_E) return false;
                ise_or_E = true;
                isNum = false;//E之后也要有数
            }
            else if(s[i]=='-'||s[i]=='+'){
                if(i!=0&&s[i-1]!='e'&&s[i-1]!='E')//加减号只能在首位或者e之前
                    return false;
            }
            else 
                return false; 
       }
       return isNum;
    }
    void deleteSpace(string& s){
        while(s.size()!=0&&s[0]==' '){
           if(s[0]==' ')
                s.erase(s.begin());//删除某个迭代器对应的字符
       }
        while(s.size()!=0&&s[s.size()-1]==' '){
            if(s[s.size()-1]==' ')
                s.erase(s.end()-1);
        }
        return;
    }
};