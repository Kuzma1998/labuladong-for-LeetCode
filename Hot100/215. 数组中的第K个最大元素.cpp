// 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。



// 堆排序
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 建堆
        for(int i=k/2-1;i>=0;--i){
            percDown(nums,i,k);
        }
        for(int i=k;i<nums.size();++i){
            if(nums[i]>nums[0]){
                nums[0] = nums[i];
                percDown(nums,0,k);
            }
        }
        return nums[0];
    }
    
    // 最小堆
    void percDown(vector<int>& nums,int i,int N){
        int parent,child;
        int temp = nums[i];
        for(parent=i;parent*2+1<N;parent=child){
            child = parent*2+1;
            if(child!=N-1&&nums[child]>nums[child+1])
                child += 1;
            if(temp<=nums[child])
                break;
            else
                nums[parent] = nums[child];
        }
        swap(nums[parent],temp);
    }
};


// 快排

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quick_Sort(nums,0,nums.size()-1);
        return nums[k-1];
    }
    void quick_Sort(vector<int>& nums,int l,int r){
        if(l<r){
            int pivot =nums[l];
            int i = l+1;
            int j =r;
            while(i<=j){
                while(i<=j&&nums[j]<pivot) --j;
                while(i<=j&&nums[i]>=pivot) ++i;
                if(i<=j) swap(nums[i],nums[j]);
                else break;
            }
            swap(nums[l],nums[j]);
            quick_Sort(nums,l,j-1);
            quick_Sort(nums,j+1,r);
        }
    }
};