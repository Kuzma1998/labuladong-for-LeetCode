/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-25 11:23:54
 */
// 描述
// 输入n个整数，找出其中最小的k个整数并按升序输出
// 本题有多组输入样例
// 数据范围：1 \le n \le 1000 \1≤n≤1000  ，输入的整数满足 1 \le val \le 10000 \1≤val≤10000 
// 输入描述：
// 第一行输入两个整数n和k
// 第二行输入一个整数数组
// 输出描述：
// 从小到大输出最小的k个整数，用空格分开。
// 示例1
// 输入：
// 5 2
// 1 3 5 7 2
// 复制
// 输出：
// 1 2



#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    while(cin>>n&&cin>>k){
        vector<int> v(n,0);
        for(int i=0;i<n;++i)
            cin>>v[i];
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<v.size();++i){
            q.push(v[i]);
        }
        for(int i=0;i<k;++i){
            cout<<q.top()<<" ";
            q.pop();
        }
        cout<<endl;
    }

    return 0;
}

