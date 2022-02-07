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
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void insert_sort(vector<int>& arr){
    int N = arr.size();
    for(int i=1;i<N;++i){
        int temp = arr[i];
        int j=i;
        for(;temp>arr[j-1]&&j>0;--j)
            arr[j] = arr[j-1];
        arr[j] = temp;
    }
}

int main()
{
    vector<int> a = {6, 4, 3, 8, 1, 5, 9, 23};
    // bubble_sort(a);
    insert_sort(a);
    for (int i = 0; i < 8; i++)
    {
        cout << a[i] << endl;
    }
}