#include<iostream>
#include <queue>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a,int b){
    return a>b;
}
int main() 
{
    //对于基础类型 默认是大顶堆
    priority_queue<int> a; 
    //等同于 priority_queue<int, vector<int>, less<int> > a;
    
  
    priority_queue<int, vector<int>, greater<int>> c;  //这样就是小顶堆 // 类模板填入类型名
    // priority_queue<int, vector<int>, decltype(compare)*> c;
    priority_queue<string> b;
    
    for (int i = 0; i < 5; i++) 
    {
        a.push(i);
        c.push(i);
    }
    while (!a.empty()) 
    {
        cout << a.top() << ' ';
        a.pop();
    } 
    cout << endl;

    while (!c.empty()) 
    {
        cout << c.top() << ' ';
        c.pop();
    }
    cout << endl;

    b.push("abc");
    b.push("abcd");
    b.push("cbd");
    while (!b.empty()) 
    {
        cout << b.top() << ' ';
        b.pop();
    } 
    cout << endl;
    cout<< "******************"<< endl;

    vector<int> ljx{77,22,44,66,88,11};
    sort(ljx.begin(), ljx.end(),greater<int>());//函数模板填入一个具体的类对象或者函数名字，比如定义了一个comp函数只填入comp，不带括号
    // sort(ljx.begin(), ljx.end(),compare);// 传入一个可调用的对象，lambda，函数，函数指针，重载了（）运算符的类,不允许使用类型名
    // bool (*pf)(int a, int b) = compare;
    // sort(ljx.begin(), ljx.end(),pf);
    for(auto i:ljx)
        cout<<i<<endl;
    return 0;
}


