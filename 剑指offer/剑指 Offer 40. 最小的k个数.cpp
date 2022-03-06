




// 最大堆仅仅需要维护k个,只要遇到小于对顶的元素直接弹出堆顶元素再插入即可,而最小堆则要维护全部元素

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k,0);
        if(k==0)
            return {};
        priority_queue<int,vector<int>,less<int>> q;// 大顶堆
        //找到最大的元素
        for(int i=0;i<k;++i){
            q.push(arr[i]);
        }
        for(int i=k;i<arr.size();++i){
            if(q.top()>arr[i]){
                q.pop();
                q.push(arr[i]);
            }
        }
        for(int i=0;i<k;++i){
            vec[i] = q.top();
            q.pop();
        }
        return vec;

    }
};

// 自己建堆
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k==0)
            return {};
        // 找到最大的元素
        for(int i=(k-1)/2;i>=0;--i){
            precDown(arr,i,k);
        }

        for(int i=k;i<arr.size();++i){
            if(arr[i]<arr[0]){
                swap(arr[0],arr[i]);
                precDown(arr,0,k);
            }
        }
        vector<int> ans;
        for(int i=0;i<k;++i){
            ans.push_back(arr[i]);
        }
        return ans;
    }
    // i是需要改变的节点，
    void precDown(vector<int> &A, int i, int N)
    {
        // 下沉调整节点位置
        int parent, child;
        int temp = A[i];
        for (parent = i; parent * 2 + 1 < N; parent = child)
        {
            child = parent * 2 + 1;
            // 找出左右节点的较大值
            if (child != N - 1 && A[child] < A[child + 1])
                ++child;
            if (temp >= A[child])
                break; //左右孩子都小于父亲，直接退出
            else
                A[parent] = A[child]; //否则赋值给父亲较大的值
        }
        A[parent] = temp; // temp应该在的位置
    }
};