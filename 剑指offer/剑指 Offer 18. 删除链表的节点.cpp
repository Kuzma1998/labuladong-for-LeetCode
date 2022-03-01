// 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
// 返回删除后的链表的头节点。
// 注意：此题对比原题有改动
// 示例
// 输入: head = [4,5,1,9], val = 5
// 输出: [4,1,9]
// 解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head||!head->next)
            return head;
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* ans = pre;
        while(head){
            if(head->val!=val){
                pre = pre->next;
                pre->next = head->next;
                head = head->next;
            }
            else{
                pre->next = head->next;
                break;
            }
        }
        return ans->next;
    }
};