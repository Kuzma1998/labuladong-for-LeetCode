/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-06 20:39:30
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-08 10:51:13
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
// 函数定义，以head为头节点，反转链表，并且返回反转后的链表的头节点、

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

// 递归反转链表前N个节点
// 函数定义：以head为节点，反转前N个节点并返回反转后的节点
class Solution {
private:
    ListNode* successor;
public:
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

