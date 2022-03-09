// 在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。


// 思路：二分法，大小为i得数应该就在索引i的位置，若不是则往左边寻找
class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int left = 0;
       int right = nums.size()-1;
       int sz = nums.size();
       while(left<=right){
            int mid = left+(right-left)/2;
            if(mid==nums[mid]){
               left = mid+1;
            }
            else
                right= mid-1;

       }
       return left;
    }

};