/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-15 21:15:30
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-15 21:15:31
 */


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* sorted = head;//已排好序的最后一个位置
        ListNode* node = head->next;

        while(node){
            if(sorted->val<=node->val){
                sorted = sorted->next;//最后一个位置的值比当前还小，sorted往后移，node变为sorted后一个
            }else{
                ListNode* prev = dummy;
                while(prev->next->val<=node->val){ // 找到插入位置
                    prev =prev->next;
                }
                sorted->next = node->next;//排好序的后面等于node的后面
                node->next = prev->next;// 插入node
                prev->next = node; 
            }
            node = sorted->next;
        }
        return dummy->next;
    }
};

