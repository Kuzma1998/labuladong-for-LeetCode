/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-27 21:49:13
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-27 21:58:10
 */


#include<iostream>
using namespace std;

int main(){
    int a[2][3] = {1,2,3,4,5,6};
    // cout<<a<<endl;
    // cout<<(a[0])<<endl;
    cout<<&(a[0])<<endl;
    cout<<&(a[0][1])<<endl;
    cout<<&(a[1])<<endl;
    cout<<&(a[2])<<endl;
    return 0;
}