/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-08 19:34:42
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-09 21:54:37
 */
// 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 
// 输入：head = [1,2,6,3,4,5,6], val = 6
// 输出：[1,2,3,4,5]
 
// 迭代  垃圾代码
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = head;
        ListNode* pre = dummy;
        while(cur){
            // 删除头节点
            if(cur->val==val&&pre->next==cur){
                pre->next = cur->next;
                cur = cur->next;
                // 非头节点
            }else if(cur->val==val&&pre->next!=cur){
                pre->next = cur->next;
                pre = pre->next;
                cur = pre->next;
            // 不相等移动
            }else{
                pre = cur;
                cur=cur->next;
                
            }
        }
        return dummy->next;
    }
};
// 迭代2,明明只要一个节点即可
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while(cur->next){
            if(cur->next->val==val){
                cur->next = cur->next->next;
            }else{
                cur=cur->next;  
            }
        }
        return dummy->next;
    }
};



// 递归

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 递归函数定义，给定head为节点的链表，删除链表中的val的节点，并返回新的头节点
        // base case
        if(!head)
            return nullptr;
        // 每个节点要做的事情，先确定head的指向，因此是后续遍历
        head->next = removeElements(head->next,val);
        // 判断head->val 和 val
        if(head->val==val){
            return head->next;
        }else{
            return head;
        }
    }
};