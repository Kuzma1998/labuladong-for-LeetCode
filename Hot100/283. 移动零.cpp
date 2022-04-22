


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        // 非0的移动到前面
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=0){
                nums[index++] = nums[i];
            }
        }
        //后面的置为0
        for(int i=index;i<nums.size();++i){
            nums[i] = 0;
        }
    }     
};