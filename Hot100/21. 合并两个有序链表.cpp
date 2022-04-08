// 将两个升序链表合并为一个新的 升序 链表并返回。
// 新链表是通过拼接给定的两个链表的所有节点组成的。 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        while(list1&&list2){
            if(list1->val<=list2->val){
                dummy->next = new ListNode(list1->val);
                list1 = list1->next;
            }else{
                dummy->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            dummy = dummy->next;
        }
        if(list1){
            dummy->next = list1;
        }else{
            dummy->next = list2;
        }
        return ans->next;
    }
};