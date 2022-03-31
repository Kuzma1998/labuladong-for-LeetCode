<!--
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-07-28 20:35:27
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-07-29 09:16:10
-->

# C++语言基础
## 1 动态数组 vector
初始化方法

```C++
int n=7,m=8;
// 初始化一个int型的空数组nums
vector<int> nums;

vector<int> nums{1,3,5};

vector<int> nums(n,2)//初始化一个大小为n的数组nums，其值全部为2

vector<vector<int>> dp;//二维数组dp

//初始化一个大小为m*n的bool数组，值全部为true
vector<vector<bool>> dp(m,vector<bool>(n,true));
```

##用到的成员函数
```C++
bool empty();

size_type size();//返回数组元素个数

reference back();//数组最后一个元素的引用

//数组尾部插入一个元素val
//const value_type& val 常量指针，
//指针指向的值不可以修改，指针指向可以修改，const修饰指针
void push_back(const value_type& val);

void pop_back();//删除数组尾部元素
```

Example
```C++
int n=10;
//创建一个数组大小为10，值都为0数组
vector<int> nums(n);
cout<<nums.empty();// false
cout<<nums.size();//10
//取值或者修改
int a = nums[4];
nums[0] = 11;

nums.push_back(20);
cout<<nums.szie();//11

int b=nums.back();
cout<<b;//20

nums.pop_back();//删除最后一个元素，无返回值
cout<<nums.szie();//10

swap(nums[0],nums[1]);//交换
```

由于数组的特性，索引访问元素十分高效，尾部增删也很方便。中间和头部删改元素很麻烦

## 2 字符串 string
初始化方法
```C++
string s;//空字符串s
string s = "abc"//初始化s为abc
```
成员函数
```C++
size_t size();//返回长度
bool empty(); //判断字符串是否为空
void push_back(char c);//尾部加入字符c
void pop_back();//尾部删除字符
//从索引pos开始截取长度为len的字符串
string substr(size_t pos,size_t len);
```

Example
```C++
string s;
s = "abcd"

cout<<s[2];//c

s.push_back('e');

cout<<s;//abcde

cout<<s.substr(2,3)//cde

s += "xyz";

cout<<s;//abcdexyz
```
string与vector类似,C++中两个字符串相等可以直接用==号判别，如if(s1$==$s2)

## 3 哈希表 unoedered_map
初始化方法:
```C++
//初始化一个key为int，value为int的哈希表
unordered_map<int,int> mapping;
//初始化一个key为string，value为int数组的哈希表
unordered_map<string vector<int>> mapping;
```
哈希表的value可以是任意类型，但一般仅用int或者string作为key

成员函数
```C++
size_type size();//键值对个数
bool empty();//

size_type count(const key_type& key);
//返回哈希表中key出现的次数
//哈希表不会出现重复的key，返回值是0或者1
//可判断key是否存在

size_type erase(const key_type& key);
//清除键值对
```

Example
```C++
vector<int> nums{1,1,3,4,5,3,6};
//计数器
unordered_map<int,int>  counter;
for(int num:nums){
    counter[num]++;//先创建key的值为0再加1
}

for(auto& it:counter){
    int key = it.first;
    int value = it.second;
    cout<<key<<": "<<val<< endl;
}
```

若用[]访问key,若key不存在,则会自动创建key,对应的值为默认值。


## 4 哈希集合 unordered_set

初始化方法:
```C++
unordered_set<int> visited;

unordered_set<string> visited;
```

成员函数
```C++
size_type size();//返回键值对个数

bool empty();

size_type count(const key_type& key);
// 类似哈希表，key存在返回1，否则为0

pair<iterator,bool> insert(const key_type& key);
//向集合插入一个元素key
```


## 5 队列 queue
初始化方法:
```C++
queue<int> q;//初始化一个存储int的队列

queue<string> q;//
```
成员函数:
```C++
bool empty();

size_type size();//返回队列中元素的个数

void push(const value_type& value);//将元素加入队尾

value_type& front();//返回头元素的值

void pop();//删除头元素

int e = a.front();//
q.pop();//返回类型为空
```

## 6 堆栈 stack

初始化方法:
```C++
stack<int> stk;

stack<string> stk;
```

成员函数:
```C++
bool empty();

size_type size();//返回堆栈中元素个数 

void push(const value_type& val);//栈顶加入元素

value_type& top();//返回栈顶元素

void pop();
```

## 7 优先队列 priority_queue
```C++
//升序队列
priority_queue <int,vector<int>,greater<int> > q;
//降序队列
priority_queue <int,vector<int>,less<int> >q;

//greater和less是std实现的两个仿函数（就是使一个类的使用看上去像一个函数。其实现就是类中实现一个operator()，这个类就有了类似函数的行为，就是一个仿函数类了）
#include<iostream>
#include <queue>
using namespace std;
int main() 
{
    //对于基础类型 默认是大顶堆
    priority_queue<int> a; 
    //等同于 priority_queue<int, vector<int>, less<int> > a;

    priority_queue<int, vector<int>, greater<int>>c;  
    //这样就是小顶堆
    priority_queue<string> b; //大顶堆

// pari的比较，先比较第一个元素，第一个相等比较第二个
    priority_queue<pair<int, int> > a;
    pair<int, int> b(1, 2);
    pair<int, int> c(1, 3);
    pair<int, int> d(2, 5);
    a.push(d);
    a.push(c);
    a.push(b);
    while (!a.empty()) 
    {
        cout << a.top().first << ' ' << a.top().second << '\n';
        a.pop();
    }
    // 对于自定义的类型 lambda表达式即可

```

## 建树
```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    string data;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* r = q.front();
            q.pop();
            if(r){
                data += to_string(r->val)+",";
            }else{
                data += "#,";
                continue;// 若没有这个跳出，则会死循环
            }
            q.push(r->left);
            q.push(r->right);
        }
        data.pop_back();
        return data;
    }

    vector<string> deleteSep(string& data){
        vector<string> q;
        int size = data.size();
        if(!data.size())
            return q;
        int pre = 1;
        for(int i=0;i<=size;i++){
            if(data[i]==','||i==size){
                q.push_back(data.substr(pre,i-pre));
                pre = i+1;
            }
        }
        return q;
    }

    TreeNode* buildTree(vector<string>& que){
        if (que.empty())   return nullptr;
        string node = que[0];
        TreeNode* root = new TreeNode(stoi(node));
        queue<TreeNode*> q;
        q.push(root);
       for(int i =1; i < que.size(); ) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr)    continue;
            string s_left = que[i++];
            if (s_left == "#")
                node->left = nullptr;
            else
                node->left = new TreeNode(stoi(s_left));
            q.push(node->left);

            string s_right = que[i++];
            if (s_right == "#")
                node->right = nullptr;
            else
                node->right = new TreeNode(stoi(s_right));
            q.push(node->right);
        }
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v = deleteSep(data);
        return buildTree(v);
    }


};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
```

## 链表
```C++
// 输入一个单向链表和一个节点的值，从单向链表中删除等于该值的节点，删除后如果链表中无节点则返回空指针。

// 链表的值不能重复。

// 构造过程，例如输入一行数据为:
// 6 2 1 2 3 2 5 1 4 5 7 2 2
// 则第一个参数6表示输入总共6个节点，第二个参数2表示头节点值为2，剩下的2个一组表示第2个节点值后面插入第1个节点值，为以下表示:
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node():val(0),next(nullptr){
        
    }
    Node(int v): val(v),next(nullptr){
    }
};

int main()
{
    int n = 0;
    int hv = 0;
   cin>>n>>hv;
        Node *head = new Node(hv);
        int pre = 0, cur = 0;
        --n;
        while (n--)
        {
            cin >> cur >> pre;
            Node *node = head;
            while (node->val != pre)
            {
                node = node->next;
            }
            Node *next = node->next;
            node->next = new Node(cur);
            node->next->next = next;
        }
        int del = 0;
        cin >> del;
        if (head->val == del)
        {
            head = head->next;
            while (head)
            {
                cout << head->val << " ";
                head = head->next;
            }
        }
        else
        {
            while (head)
            {
                if (head->val != del)
                {
                    cout << head->val << " ";
                }
                head = head->next;
            }
        }
    cout << endl;
    return 0;
}
```

## 小数点后n位
```C++
cout<<setioflags(ios::fixed)<<setprecision(n);
```