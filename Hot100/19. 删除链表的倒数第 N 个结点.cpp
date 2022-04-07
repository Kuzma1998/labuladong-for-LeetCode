// digui

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
class Solution {
public:
    int num=0; 
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*dummy_head=new ListNode();
        dummy_head->next=head;
        ListNode*p=head;
        num=n;
        remove_LNode(dummy_head);
        return dummy_head->next;
    }
    void remove_LNode(ListNode*head)
    {
        if(head==nullptr)
        {
            return;
        }
        remove_LNode(head->next);
        num-=1;
        if(num==-1)
        {
            head->next=head->next->next;
        }
    }
};



// bianli
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* node = head;
        while(node){
            ++sz;
            node = node->next;
        }
        if(n==sz)
            return head->next;
        int k = sz-n-1;
        node = head;
        while(k--){
            node = node->next;
        }
        ListNode* next = node->next->next;
        node->next = next;
        return head;
    }
};