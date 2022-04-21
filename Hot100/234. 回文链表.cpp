class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string str = "";
        ListNode* node = head;
        while(node){
            str += to_string(node->val);
            node = node->next;
        }
        for(int i=0,j=str.size()-1;i<=j;++i,--j){
            if(str[i]!=str[j])
                return false;
        }
        return true;
    }
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)
            return true;
        // 切分链表为前一部分和后一部分
        ListNode* firstEnd = cutOff(head);
        ListNode* second = firstEnd->next;
        // 反转链表
        second = reverseList(second);
        // 判断是否回文
        ListNode* temp1 = head;
        ListNode* temp2 = second;
        bool flag = true;
        while(temp2){
            if(temp1->val!=temp2->val){
                flag = false;
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        //回复原来的链表
        firstEnd->next = reverseList(second);
        return flag;
    }

    ListNode* cutOff(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next&&fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){
        if(!head||!head->next){
            return head;
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};