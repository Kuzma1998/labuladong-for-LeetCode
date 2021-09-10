/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-10 22:03:06
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-10 22:03:06
 */
// 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
// 你应当 保留 两个分区中每个节点的初始相对位置。

// 输入：head = [1,4,3,2,5,2], x = 3
// 输出：[1,2,2,4,3,5]


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
       ListNode* small = new ListNode(0);//存小于x
       ListNode* l1 = small;
       ListNode* big = new ListNode(1);// 存大于x
       ListNode* l2 =big;

       while(head){
           if(head->val>=x){
               big->next = head;
               big = big->next;
           }else{
               small->next = head;
               small = small->next;
           }
           head = head->next;
       }
       // 画个图即可
       big->next = nullptr;
       small->next = l2->next;;
       return l1->next;
    }
};
