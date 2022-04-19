/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 双指针即可  走过相同的路径一定会相遇  如果没有交点 那么flag会大于2
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        int flag = 0;
        while(l1!=l2&&flag<=2){
            l1 = l1->next;
            l2 = l2->next;
            if(l1==nullptr){
                l1 = headB;
                ++flag;
            }
            if(l2==nullptr){
                l2 = headA;
                ++flag;
            }
        }
        return flag>2?nullptr:l2;
    }
};