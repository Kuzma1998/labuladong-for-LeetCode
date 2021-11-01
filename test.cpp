#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // 删除多余空格
        deleteSpace(s);
        cout<<s<<endl;
        // 反转整个字符串
        reverseString(s,0,s.size()-1);
        cout<<s<<endl;
        // 反转单词
        for(int i=0;i<s.size();){
            int j=i;
            while(j<s.size()&&s[j]!=' ')
                ++j;
            reverseString(s,i,j-1);
            i =j+1;
        }
        return s;

    }
    void deleteSpace(string& s){
        for(int i=0;i<s.size()-1;){
            if(s[i]==' '&&s[i]==s[i+1])
                s.erase(s.begin()+i);
            else{
                ++i;
            }
        }
        if(s[0]==' ')
            s.erase(s.begin());
        if(s[s.size()-1]==' ')
            s.erase(s.begin()+s.size()-1);
    }
    void reverseString(string& s,int start,int end){
        for(;start<end;++start,--end){
            char temp = s[end];
            s[end] = s[start];
            s[start] = temp;
        }
    }

};

int main(){
    Solution solver;
    string str = "a good   example";
    string new_s = solver.reverseWords(str);
    cout<<new_s<<endl;
    return 0;
}
