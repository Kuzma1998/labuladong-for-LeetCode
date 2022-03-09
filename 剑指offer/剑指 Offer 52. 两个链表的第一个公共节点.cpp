// 输入两个链表，找出它们的第一个公共节点。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 模拟走一趟
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* A = headA;
       ListNode* B  =headB;
       int sa=0,sb=0;
       while(A||B){
            if(A){
                A = A->next;
                ++sa;
            }
            if(B){
                ++sb;
                B = B->next;
            }
       }
       int diff = sa>sb?sa-sb:sb-sa;
       if(sa>sb){
           while(diff--){
               headA = headA->next;
           }
       }else{
           while(diff--){
               headB = headB->next;
           }
       }
        while(headA&&headB&&headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        if(headA)
            return headA;
        return NULL;

    }
};

// 双指针
// 我们使用两个指针 node1，node2 分别指向两个链表 headA，headB 的头结点，
// 然后同时分别逐结点遍历，当 node1 到达链表 headA 的末尾时，重新定位到链表 headB 的头结点；
// 当 node2 到达链表 headB 的末尾时，重新定位到链表 headA 的头结点。
// 这样，当它们相遇时，所指向的结点就是第一个公共结点。

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        
        while (node1 != node2) {
            node1 = node1 != NULL ? node1->next : headB;
            node2 = node2 != NULL ? node2->next : headA;
        }
        return node1;
    }
};

