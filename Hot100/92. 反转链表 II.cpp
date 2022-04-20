/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 1 2 3 4 5 先找到pre 1，cur 2 
// 依次把3插到2前面变为 1 3 2 4 5
// 再把4 查到2 前面 变为1 3 4 2 5
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        for(int i=0;i<left-1;++i){
            pre = cur;
            cur= cur->next;
        }
        // 头插法
        for(int i=0;i<right-left;++i){
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummy->next;
    }
};

