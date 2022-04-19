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

//归并排序对链表进行排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head,nullptr);
    }
    ListNode* mergeSort(ListNode* head,ListNode* tail){
        //base case
        if(head==nullptr)
            return head;
        if(head->next==tail){
            head->next = nullptr;
            return head;
        }

        // 寻找中点
        ListNode* fast = head,*slow = head;
        while(fast!=tail){
            slow = slow->next;
            fast = fast->next;
            if(fast!=tail){
                fast = fast->next;
            }
        }
        // 递归排序
        ListNode* mid = slow;
        ListNode* list1 = mergeSort(head,mid);
        ListNode* list2 = mergeSort(mid,tail);
        ListNode* sorted = merge(list1,list2);
        return sorted;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        ListNode* temp1 = l1,*temp2 = l2;
        while(temp1&&temp2){
            if(temp1->val<temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            }else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if(!temp1){
            temp->next =temp2;
        }
        if(!temp2){
            temp->next =temp1;
        }
        return dummy->next;
    }
};