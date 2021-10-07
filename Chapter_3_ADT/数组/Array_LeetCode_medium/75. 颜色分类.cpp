// 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
// 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
// nums = [2,0,2,1,1,0]
// 输出：[0,0,1,1,2,2]


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        vector<int> copy = nums;
        for(auto num:copy){
            if(num==0){
                nums[start] = 0;
                ++start;
            }
            else if(num==2){
                nums[end] = 2;
                --end;
            }   
            else    
                continue;   
        }
        for(;start<=end;++start){
            nums[start]=1;
        }
        return;
    }
};


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        for (int i = 0; i <= p2; ++i) {
            while (i <= p2 && nums[i] == 2) {
                swap(nums[i], nums[p2]);
                --p2;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                ++p0;
            }
        }
    }
};

// s双指针

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        for(int i=0;i<=end;++i){
            while(i<=end&&nums[i]==2){
                //确保nums[i]不为2，2放到组后面
                swap(nums[i],nums[end]);
                --end;
            }
            //等于0交换到前面，然后剩下的1自然就在最中间
            if(nums[i]==0){
                swap(nums[i],nums[start]);
                ++start;
            }
        }
    }
};