
// 在数组中的两个数字，如果前面一个数字大于后面的数字，
// 则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
// 示例 1:
// 输入: [7,5,6,4]
// 输出: 5


// 归并排序


class Solution {
private:
    int counts = 0;
public:
    int reversePairs(vector<int>& nums) {
        int N = nums.size();
        if(N==0)
            return 0;
        vector<int> temp(N,0);
        Msort(nums,temp,0,N-1);
        return counts;
    }
    void Msort(vector<int>& nums,vector<int>& temp,int left,int right){
        if(left<right){
            int mid = left+(right-left)/2;
            Msort(nums,temp,left,mid);
            Msort(nums,temp,mid+1,right);
            Merge(nums,temp,left,mid+1,right);
        }
    }
    void Merge(vector<int>& A,vector<int>& temp,int L, int R, int Rend){
        int Tmp = L;
        int Lend = R-1;
        int numsize = Rend-L+1;
        while(L<=Lend&&R<=Rend){
            if(A[L]<=A[R]){
                temp[Tmp++] = A[L++];
            }
            else{
                // 当左边大于右边的时候 统计个数
                temp[Tmp++] = A[R++];
                counts += (Lend-L+1);     
            }
        }
        while(L<=Lend){
            temp[Tmp++] = A[L++];
        }
        while(R<=Rend){
            temp[Tmp++] = A[R++];
        }
        for (int i = 0; i < numsize; i++, Rend--){
            A[Rend] = temp[Rend];
        } 
    }
};