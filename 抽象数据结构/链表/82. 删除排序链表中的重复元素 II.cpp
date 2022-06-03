/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-15 17:06:10
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-15 21:18:08
 */
// 存在一个按升序排列的链表，给你这个链表的头节点 head ，
// 请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现的数字。
// 返回同样按升序排列的结果链表。

// 输入：head = [1,2,3,3,4,4,5]
// 输出：[1,2,5]
// 维护三个节点pre cur next

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // base case
        if(!head)
            return nullptr;
        if(head&&!head->next)
            return head;
        // 定义一些节点
        ListNode* cur =head;
        ListNode* pre = new ListNode(0);
        pre->next = cur;
        ListNode* dummy = pre;
        ListNode* next = head->next;

        while(cur&&next){
            if(cur->val!=next->val){// 当前后不等，直接移动三个指针
                pre = pre->next;
                cur = cur->next;
                next = next->next;
            }else{
                while(next&&cur->val==next->val){ // 相等，直接移动next，直到不相等
                    next = next->next;
                }
                //删除节点
                pre->next = next;
                cur = next;
                if(next)
                    next = next->next;
                else    
                    next = nullptr;
            }
        }
        return dummy->next;
    }
};