/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-11 17:39:24
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-11 17:55:04
 */

// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
// 进阶：
// 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？ // 要学会手写快排，堆排序，和归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        sort(nums.begin(), nums.end());
        ListNode* node = new ListNode(0);
        ListNode* new_node = node;
        for(auto a:nums){
            node->next = new ListNode(a);
            node = node->next;
        }
        return new_node->next;
    }
};

// 快排
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        fast_Sort(nums,0,nums.size()-1);
        ListNode* new_node = new ListNode(0);
        ListNode* node = new_node;
        for(auto a:nums){
            new_node->next = new ListNode(a);
            new_node = new_node->next;
        }
        return node->next;
    }
    int getPivot(vector<int> nums,int left,int right) {
        int center = (left+right)/2;
        // 确保左边的小于中间的小于右边的
        if(nums[center]>nums[right]){
            swap(nums[center],nums[right]);
        }
        if(nums[left]>nums[right]){
            swap(nums[left],nums[right]);
        }
        if(nums[left]>nums[center]){
            swap(nums[left],nums[center]);
        }
        // 把主元换到right-1
        swap(nums[center],nums[right-1])
        return nums[right-1];
    }

    void fast_Sort(vector<int>& nums,int left,int right){
        int pivot = getPivot(nums,left,right);
        int i = left;
        int j = right-1;
        for(;;){
            while(num[++i]<pivot)
            {}
            while(num[--j]>pivot)
            {}
            if(i<j){
                swap(num[i],num[j]);
            }else{
                break;} //
        }
        swap(num[i],nums[right-1]);// 主元放到合适的位置,这个位置之前的比主元小，之后的比主元大
        fast_Sort(nums,left,i-1);
        fast_Sort(nums,i+1,right);
    }
};