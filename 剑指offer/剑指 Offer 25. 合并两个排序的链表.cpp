// 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
// 示例1：
// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
                cur->next = new ListNode(l1->val);
                l1 = l1->next;
            }else{
                cur->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1)
            cur->next = l1;
        else
            cur->next = l2;
        return dummy->next;
    }
};