/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-06 20:39:30
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-06 20:41:57
 */

// 迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode*  cur = head;
        // if(!head||!head->next){
        //     return head;
        // }
        while(cur){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

// 递归

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // base case 
        if(head==nullptr||head->next==nullptr)
            return head;
        // last为最后一个节点，反转后的第一个节点
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        // 后序遍历，这是每个节点要做的事情，即改变指向
        head->next = nullptr;// 最后一个节点的next设为null
        return last;
    }
};