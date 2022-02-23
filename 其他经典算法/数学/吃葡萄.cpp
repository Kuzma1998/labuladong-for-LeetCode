
// 有三种葡萄，每种分别有\mathit a,b,ca,b,c颗。
// 有三个人，第一个人只吃第 1,2种葡萄，第二个人只吃第2,3种葡萄，第三个人只吃第1,3种葡萄。
// 适当安排三个人使得吃完所有的葡萄,并且且三个人中吃的最多的那个人吃得尽量少。


// 将一组三个葡萄数想像成三条线段，如果能构成三角形（符合两短相加大于长），
// 则三个人一人吃掉相邻两条边的一半就可以；如果不能构成三角形（即有一超长边），那么要把超长边平分给两个人吃，
// 相当于折断长边，现在有4条边肯定能构成四边形，那么有两种情况：
// 两个人吃完长边后不再吃短边，第三人吃完短边也没有超出另两个人；
// 两人吃完长边后，如果不帮第三人吃两个短边，会使第三人吃的超过2人。
// 第一种情况的输出就是长边的1/2；第二种情况则与三角形情况相同，需要所有人均分。
// 因此，综合来看只有两种情况：所有人平分，或者其中两人平分最多的那种葡萄。这两个哪个大，输出哪个

#include <iostream>
#include <cmath>
using namespace std;
void sort(long list[3])
{
    if (list[0]<list[1]) swap(list[0],list[1]);
    if (list[0]<list[2]) swap(list[0],list[2]);
    if (list[1]<list[2]) swap(list[1],list[2]);
}
  
int main()
{
    int n;
    long l[3], sum;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l[0] >> l[1] >> l[2];
        sort(l);
        sum = l[0] + l[1] + l[2];
        cout << max((sum + 2) / 3, (l[0] + 1) / 2) << endl;
    }