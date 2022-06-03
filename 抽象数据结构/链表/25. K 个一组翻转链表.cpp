/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-08 11:23:56
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-08 15:54:08
 */
// 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
// k 是一个正整数，它的值小于或等于链表的长度
// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。


// 递归  定义 reverseKGroup(ListNode* head, int k)返回以head为头节点，k个节点反转一回的链表的头节点
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      
        if(head==nullptr)
            return nullptr;
        ListNode *a,*b;
        a =head;
        b =head;
        for(int i=1;i<=k;i++){
              // base case 当剩下的链表不足k个直接返回
            if(b==nullptr)
                return head;
            b = b->next;
        }
        // 反转区间[a,b)的元素
        ListNode* new_head = reverseBetween(a,b);
        //反转之后a节点就是反转之后那部分的最后一个节点，根据递归的定义链接到以b为头节点，k个一反转之后链表的头节点;
        a->next = reverseKGroup(b,k);   
        return new_head;
    }
    ListNode* reverseBetween(ListNode* p,ListNode* q){
        ListNode* cur = p;
        ListNode* next = p;
        ListNode* pre = nullptr;
        while(cur!=q){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};


// 迭代，头插法，每次把要反转的节点放到前面

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0); // 设置哨兵节点
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* next;
        // 链表长度
        int length = 0;
        while(head!=nullptr){
            ++length;
            head = head->next;
        }
        // 第一个for循环确定有几个k,第二个for循环每个反转k-1次
        for(int i=0;i<length/k;i++){
            for(int j=0;j<k-1;j++){
                // 头插法，依次把要反转的放到前面
                next = cur->next;
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
            }
            pre = cur;
            cur = pre->next;
        }
        return dummy->next;
    }

};