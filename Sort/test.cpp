#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubble_sort(vector<int> &arr)
{
    int N = arr.size();
    for (int i = N - 1; i >= 0; --i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insert_sort(vector<int> &arr)
{
    int N = arr.size();
    for (int i = 1; i < N; ++i)
    {
        int temp = arr[i];
        int j = i;
        for (; temp > arr[j - 1] && j > 0; --j)
            arr[j] = arr[j - 1];
        arr[j] = temp;
    }
}

void Selection_sort(vector<int> &arr)
{
    int N = arr.size();
    for (int i = 0; i < N - 1; ++i)
    {
        int maxIndex = i;
        for (int j = i + 1; j < N; ++j)
        {
            if (arr[j] > arr[maxIndex])
                swap(arr[j], arr[maxIndex]);
        }
    }
}

// 大到小
void quick_sort1(vector<int> &a, int L, int R)
{
    if (L < R)
    {
        int privot = a[L];
        int i = L + 1;
        int j = R;
        while (i <= j)
        {
            while (i <= j && a[j] < privot)
            {
                --j;
            }
            while (i <= j && a[i] >= privot)
            {
                ++i;
            }
            if (i <= j)
                swap(a[i], a[j]);
            else
                break;
        }
        swap(a[j], a[L]);
        quick_sort1(a, L, j - 1);
        quick_sort1(a, j + 1, R);
    }
}

// 小到大
void quick_sort2(vector<int> &a, int L, int R)
{
    if (L < R)
    {
        int privot = a[L];
        int i = L + 1;
        int j = R;
        while (i <= j)
        {
            while (i <= j && a[j] > privot)
            {
                --j;
            }
            while (i <= j && a[i] <= privot)
            {
                ++i;
            }
            if (i <= j)
                swap(a[i], a[j]);
            else
                break;
        }
        swap(a[j], a[L]);
        quick_sort2(a, L, j - 1);
        quick_sort2(a, j + 1, R);
    }
}

void shell_sort(vector<int> &a)
{
    int N = a.size();
    for (int D = N / 2; D > 0; D /= 2)
    {
        for (int i = D; i < N; i++)
        { //从每个增量序列的第二个开始进行插入排序
            int temp = a[i];
            int j = i;
            for (; a[j - D] > temp && j > 0; j -= D)
            { //从小到大
                a[j] = a[j - D];
            }
            a[j] = temp;
        }
    }
}

void PrecDown(vector<int>& A, int i, int N)
{
    //向下过滤结点，调整为最大堆
    int parent, child;
    int tmp = A[i];
    for (parent = i; parent * 2 + 1 < N; parent = child)
    {
        child = parent * 2 + 1;
        // 找左右孩子中较大的
        if ((child != N - 1) && (A[child] < A[child + 1]))
            //左孩子小于右孩子,则孩子加一
            child++;
        if (A[child] <= tmp)//若孩子节点小于父节点，那么直接break不要动
            break;
        else
            A[parent] = A[child];//否则就把较大的孩子节点赋给父节点
    }
    A[parent] = tmp;//父节点变成孩子结点之后赋给较小的temp
}

void Heap_Sort(vector<int>& A, int N)
{
    for (int i = (N / 2) - 1; i >= 0; i--) //建堆
    {
        PrecDown(A, i, N);
    }
    for (int i = N - 1; i > 0; i--)
    {
        swap(A[0], A[i]);
        PrecDown(A, 0, i);//调整堆，堆的大小一次减少1，只需要调整第0个元素的位置
    }
}

// L 归并左数组的起点，R右边起点，Rend右边终点
void Merge(vector<int>& A,vector<int>& temp,int L, int R, int Rend){
    int Tmp = L;
    int Lend = R-1;
    int numsize = Rend-L+1;
    while(L<=Lend&&R<=Rend){
        if(A[L]<A[R])
            temp[Tmp++] = A[L++];
        else
            temp[Tmp++] = A[R++];
    }
    while(L<=Lend){
        temp[Tmp++] = A[L++];
    }
    while(R<=Rend){
        temp[Tmp++] = A[R++];
    }
    for (int i = 0; i < numsize; i++, Rend--)
    {
        A[Rend] = temp[Rend];
    }
}

void Msort(vector<int>& A,vector<int>& temp,int Left, int Right){
    int center;
    if(Left < Right){
        center = Left + (Right - Left)/2;
        Msort(A, temp,Left,center);
        Msort(A, temp,center+1,Right);
        Merge(A,temp,Left,center+1,Right);
    }
}

void Merge_Sort(vector<int>& A){
    int N = A.size();
    vector<int> temp (N,0);
    Msort(A, temp, 0, N-1);
}


int main()
{
    vector<int> a = {1, 3, 4, 3, 33, 3, 3, 5};
    // quick_sort1(a,0,a.size()-1);
    // shell_sort(a);
    Heap_Sort(a, a.size());
    // Merge_Sort(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }
}