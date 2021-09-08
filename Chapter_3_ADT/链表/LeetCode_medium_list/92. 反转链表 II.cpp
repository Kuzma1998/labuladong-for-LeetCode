/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-06 22:18:03
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-08 10:45:07
 */

// 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。


// 思路：两次循环。第一次循环找到要反转的位置，第二次循环反转,头插法，每次反转要把被反转的那个元素放到反转部分的开头，这样反转多次可以达到效果。

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* cur = head;
        ListNode* new_head = new ListNode(0); // 哨兵节点
        new_head->next = head;
        ListNode* pre = new_head;
        for(int i=1;i<left;i++){
            pre = cur;
            cur = cur->next;
        }
        // 每反转一次都让被反转的放到开头
        for(int i=1;i<=right-left;i++){
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return new_head->next;
    }

};