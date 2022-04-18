class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head||!head->next)
            return false;
        set<ListNode*> s;
        while(head){
            s.insert(head);
            if(s.find(head->next)!=s.end())
                return  true;
            head = head->next;
        }
        return false;
    }
};