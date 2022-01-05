/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-15 19:02:26
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-15 19:16:45
 */

// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]

// 递归 函数定义，两两反转head开头的链表，返回反转后的头节点
class Solution {
public:
    // base case
    ListNode* swapPairs(ListNode* head) { 
        if(!head||!head->next)
            return head;
        
        ListNode* new_head = head->next;// 要返回的节点
        head->next = swapPairs(head->next->next); // 原来头节点指向后一部分反转后的头节点
        new_head->next = head; // 新的头节点指向原来的头节点
        return new_head;
    }
};


// 迭代  
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int length = 0;
        ListNode* node = head;
        while(node){
            length++;
            node = node->next;
        }
        if(length==0||length==1)
            return head;
        int num = length/2;
        
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* ans = pre;
        ListNode* cur = head;
        ListNode* next;
        // 反转k次
        for(int i=0;i<num;i++){
            next = cur->next;
            cur->next = next->next;
            next->next = cur;
            pre->next = next;
            pre = cur;
            cur=cur->next;
        }
        return ans->next;
    }
};