// 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
// 注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，
// 其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 

// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
// 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// 输出：[1,2,2,3,5,6]
// 解释：需要合并 [1,2,3] 和 [2,5,6] 。
// 合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。



// 思路1：
// 把nums2插入到nums1后面，用sort函数，或者写一个快排归并堆排序


// 思路2：
// 双指针法，重新创建一个数组然后把小的排进去，然后把nums1的值于其替换。

// 思路3：逆序双指针，从后往前从大到小排序。
// 观察可知，nums1的后半部分是空的，可以直接覆盖而不会影响结果。因此可以指针设置为从后向前遍历，每次取两者之中的较大者放进 nums1的最后面。
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int all = m+n-1;
        int l1 = m-1;
        int l2 =n-1;
        int number;
        while(l1>=0||l2>=0){
            if(l1==-1)
                number = nums2[l2--];
            else if(l2==-1)
                number = nums1[l1--];
            else if(nums1[l1]<nums2[l2])
                number = nums2[l2--];
            else 
                number = nums1[l1--];
            nums1[all--] = number;
        }
    }
};