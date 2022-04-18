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
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)
            return nullptr; 
        set<ListNode*> s;
        ListNode* node = head;
        while(head!=nullptr){
            s.insert(head);
            if(s.find(head->next)!=s.end()){
                return head->next;
            }
            head = head->next;
        }
        return nullptr;

    }
};