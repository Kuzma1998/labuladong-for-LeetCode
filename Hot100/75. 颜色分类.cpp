// 写排序而已

//堆排序

class Solution {
public:
    void sortColors(vector<int>& nums) {
       int N = nums.size();
       for(int i=N/2-1;i>=0;--i){
           precDown(nums,i,N);
       }
       for(int i=N-1;i>=0;--i){
           swap(nums[0],nums[i]);
           precDown(nums,0,i);
       }
    }

    void precDown(vector<int>& nums,int i,int N){
        int parent,child;
        int temp = nums[i];
        // 寻找到nums[i]应该在的位置
        for(parent=i;parent*2+1<N;parent=child){
            child = parent*2+1;
            if(child!=N-1&&nums[child]<nums[child+1])
                ++child;
            if(temp>=nums[child])
                break;
            else
                nums[parent] = nums[child];
        }
        nums[parent] = temp;
    }
};