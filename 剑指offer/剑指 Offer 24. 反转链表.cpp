// 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

// 示例:
// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL

// 递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode* node = reverseList(head->next);//返回反转后得节点
        head->next->next = head;//反转
        head->next = NULL;//当前节点置为null，那么原来第一个就会指向null
        return node;
    }
};


// 迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head&&!head->next)
            return head;
        ListNode* cur = head;//当前节点
        ListNode* pre = NULL;//反转前的节点
        while(cur){
            ListNode* next = cur->next;//反
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
