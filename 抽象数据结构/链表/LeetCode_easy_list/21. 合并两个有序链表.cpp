/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-08 16:57:38
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-09 21:55:00
 */


// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* node = new ListNode(0);
        ListNode* new_node = node;
        while(l1&&l2){
            if(l1->val>l2->val){
                node->next = new ListNode(l2->val);
                node = node->next;
                l2 = l2->next;
            }else{
                node->next = new ListNode(l1->val);
                node = node->next;
                l1 = l1->next;
            }
        }
        if(l1){
            node->next = l1;
        }else{
            node->next = l2;
        }
        return new_node->next;
    }
};

// 时间复杂度：O(n + m)，其中 n 和 m 分别为两个链表的长度。因为每次循环迭代中，l1 和 l2 只有一个元素会被放进合并链表中，
//  因此 while 循环的次数不会超过两个链表的长度之和。所有其他操作的时间复杂度都是常数级别的，因此总的时间复杂度为 O(n+m)。
// 空间复杂度：O(1)O(1)。我们只需要常数的空间存放若干变量。



// 递归解法   之后填坑

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { // 函数定义，给定两个链表，返回合并后的链表的头节点
        // base case
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        // 这两个节点要干啥
        if(l1->val<l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
            
        }else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};