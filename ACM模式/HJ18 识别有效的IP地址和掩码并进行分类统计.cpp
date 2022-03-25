/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-25 11:02:32
 */
// 描述
// 请解析IP地址和对应的掩码，进行分类识别。要求按照A/B/C/D/E类地址归类，不合法的地址和掩码单独归类。
// 所有的IP地址划分为 A,B,C,D,E五类
// A类地址从1.0.0.0到126.255.255.255;
// B类地址从128.0.0.0到191.255.255.255;
// C类地址从192.0.0.0到223.255.255.255;
// D类地址从224.0.0.0到239.255.255.255；
// E类地址从240.0.0.0到255.255.255.255
// 私网IP范围是：
// 从10.0.0.0到10.255.255.255
// 从172.16.0.0到172.31.255.255
// 从192.168.0.0到192.168.255.255
// 子网掩码为二进制下前面是连续的1，然后全是0。（例如：255.255.255.32就是一个非法的掩码）
// （注意二进制下全是1或者全是0均为非法子网掩码）
// 注意：
// 1. 类似于【0.*.*.*】和【127.*.*.*】的IP地址不属于上述输入的任意一类，也不属于不合法ip地址，计数时请忽略
// 2. 私有IP地址和A,B,C,D,E类地址是不冲突的

#include<bits/stdc++.h>
using namespace std;

pair<string,string> Split(string& s){
    int i=0;
    for(;i<s.size();++i){
        if(s[i]=='~'){
            break;
        }
    }
    return {s.substr(0,i),s.substr(i+1)};
}

vector<int> ToTransform(string& net){
    vector<int> IP;
    int last = 0;
    for(int i=0;i<net.size();++i){
        if(net[i]=='.'){
            string temp = net.substr(last,i-last);
            if(temp=="")
                break;
            int num = stoi(temp);
            if(num<0||num>255)
                break;
            IP.push_back(stoi(net.substr(last,i-last)));
            last =i+1;
        }
        if(i==net.size()-1){
            string temp = net.substr(last);
            if(temp=="")
                break;
            int num = stoi(temp);
            if(num<0||num>255)
                break;
            IP.push_back(stoi(net.substr(last)));
        }
    }
    return IP;
}

bool isValid(vector<int>& Mask){
    if(Mask[0]==0&&Mask[1]==0&&Mask[2]==0&&Mask[3]==0)
        return false;
    if(Mask[0]==255&&Mask[1]==255&&Mask[2]==255&&Mask[3]==255)
        return false;
    if(Mask[0]==255){
        if(Mask[1]==255){
            if(Mask[2]==255){
                if(Mask[3]==128||Mask[3]==192||Mask[3]==224||Mask[3]==240||
           Mask[3]==248||Mask[3]==252||Mask[3]==254||Mask[3]==0)
                return true;
                else
                    return false;
            }
            else{
                if(Mask[2]==128||Mask[2]==192||Mask[2]==224||Mask[2]==240||
           Mask[2]==248||Mask[2]==252||Mask[2]==254||Mask[2]==0){
                    if(Mask[3]==0)
                        return true;
                    else return false;
                }
            }
        }
        else{
            if(Mask[1]==128||Mask[1]==192||Mask[1]==224||Mask[1]==240||
           Mask[1]==248||Mask[1]==252||Mask[1]==254||Mask[1]==0){
                if(Mask[2]==0&&Mask[3]==0)
                    return true;
                else return false;
            }
        }
    }
    else{
        if(Mask[0]==128||Mask[0]==192||Mask[0]==224||Mask[0]==240||
           Mask[0]==248||Mask[0]==252||Mask[0]==254||Mask[0]==0){
            if(Mask[1]==0&&Mask[2]==0&&Mask[3]==0)
                return true;
            else return false;
        }
    }
    return false;
}

void Judge(string& s,vector<int>& ans){
    pair<string, string> p = Split(s);
//     string net = p.first, mask = p.second;
    vector<int> IP = ToTransform(p.first);
    vector<int> Mask = ToTransform(p.second);
    if(IP.size()<4||Mask.size()<4){
        ans[5]++;
        return;
    }
    if(IP[0]==0||IP[0]==127)
        return;
    if(!isValid(Mask)){
        ans[5]++;
    }else{
        if(IP[0]>=1&&IP[0]<=126){
            ans[0]++;
            if(IP[0]==10)
                ans[6]++;
        }
        if(IP[0]>=128&&IP[0]<=191){
            ans[1]++;
            if(IP[0]==172&&IP[1]>=16&&IP[1]<=31)
                ans[6]++;
        }
        if(IP[0]>=192&&IP[0]<=223){
            ans[2]++;
            if(IP[0]==192&&IP[1]==168)
                ans[6]++;
        }
        if(IP[0]>=224&&IP[0]<=239){
            ans[3]++;
        }
        if(IP[0]>=240&&IP[0]<=255){
            ans[4]++;
        }  
    } 
}


int main(){
    string str;
    vector<int> ans(7,0);
    while(cin>>str){
        Judge(str,ans);
    }
    for(auto num:ans)
            cout<<num<<" ";
        cout<<endl;
    return 0;
}