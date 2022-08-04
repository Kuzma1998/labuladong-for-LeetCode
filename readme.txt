This is a LeetCode Notes for labuladong.
It is create by my PC these days.


map容器的迭代器解引用是pair
set迭代器解引用就是key

从0开始取字符串i个和i+1到最后一位
s.substr(0,i)+s.substr(i+1)

数字转字符串  to_String(i)  反过来  stoi(s);

字符大小写转换  toupper(c) tolower(c)  或者+-32

输入字符串  getline(cin,str);

is_sorted(v.begin(),v.end());//默认升序检查

is_sorted(v.begin(),v.end(),greater<int>());//降序检查


s.insert(i+1, "abc");  // i后面插入一个字符串 相当于i+1前面插入一个
                
s.erase(s.begin()+i+1); //删除i位置的点
string.erase(pos,n);  删除从pos开始的n个字符    
string.erase(0,1);   删除第一个字符
string.erase(first,last)    //删除从first到last中间的字符（first和last都是string类型的迭代器）

string p(n,'.'); // n个点

vec.insert(iter,elem); //iter迭代器之前插入元素elem