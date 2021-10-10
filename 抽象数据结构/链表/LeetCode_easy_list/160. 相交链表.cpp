/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-08 16:31:09
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-08 16:32:12
 */
// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。

// 思路：先求长度，哪个长，头节点往前移动多出来的长度，然后逐个移动ab进行比较。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a_start = headA;
        ListNode* b_start = headB;
        int la = 0;
        int lb =0;
        while(a_start){
            la++;
            a_start = a_start->next;
        }
        while(b_start){
            lb++;
            b_start = b_start->next;
        }
        int diff = (la>lb)?la-lb:lb-la;
        if(la>lb){
            while(diff){
                headA=headA->next;
                diff--;
            }
        }else{
            while(diff){
                headB = headB->next;
                diff--;
            }
        }
        while(headB&&headA){
            if(headA==headB){
                return headB;
            }
            headB = headB->next;
            headA = headA->next;
        }
        return nullptr;
    }
};