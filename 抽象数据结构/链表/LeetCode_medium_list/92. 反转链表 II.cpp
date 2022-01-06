/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-06 22:18:03
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-10 19:35:47
 */

// 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。


// 思路：两次循环。第一次循环找到要反转的位置，第二次循环反转,头插法，每次反转要把被反转的那个元素放到反转部分的开头，这样反转多次可以达到效果。

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* cur = head;
        ListNode* new_head = new ListNode(0); // 哨兵节点
        new_head->next = head;
        ListNode* pre = new_head;
        for(int i=1;i<left;i++){
            pre = cur;
            cur = cur->next;
        }
        // 每反转一次都让被反转的放到开头
        for(int i=1;i<=right-left;i++){
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return new_head->next;
    }

};




// 递归反转链表的某个区间[M,N]
// 函数定义：以head为节点，反转前N个节点并返回反转后的节点
class Solution {
private:
    ListNode* successor;
public:

    ListNode* reverseBetween(ListNode* head,int M,int N) {
        // base case 
        if(M==1){
            return reverseN(head,N);
        }
        // 递归,对于head->next，相当于反转head->next，区间变为M-1.N-1;
        head->next = reverseBetween(head->next,M-1,N-1);
        return head;
    }

    ListNode* reverseN(ListNode* head,int N) {
        // base case 
        if(N==1){
            successor = head->next; // 确定前驱
            return head;
        }
        ListNode* last = reverseN(head->next,N-1);
        // 节点要干的是请，反转和链接前驱
        head->next->next = head;// 反转链表
        head->next =successor;// 此时头结点链接到successor,递归返回时会将初始头节点链接到前驱
        return last;
    }
};

