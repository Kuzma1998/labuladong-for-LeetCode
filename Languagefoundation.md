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