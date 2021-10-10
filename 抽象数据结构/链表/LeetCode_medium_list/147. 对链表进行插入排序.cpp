/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-15 21:15:30
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-22 20:40:26
 */


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
       if(!head||!head->next){
           return head;
       }

       ListNode* dummy = new ListNode(0);
       dummy->next = head;
       ListNode* sorted = head;
       ListNode* node = head->next;

       while(node){
           // node一直在sorted之前
            if(node->val>=sorted->val){//node的值大于等于sorted
               sorted = sorted->next;
            }
            else{//寻找要插入的位置
                ListNode* start = dummy;
                while(start->next->val<=node->val){ // start的值小于等于node,移动
                    start = start->next;
                }
                // insert
                sorted->next = node->next;
                node->next = start->next;
                start->next = node;
           }
            node = sorted->next;
       }
       return dummy->next;
    }
};

