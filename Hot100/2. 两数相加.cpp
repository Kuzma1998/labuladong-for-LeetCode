// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
// 请你将两个数相加，并以相同形式返回一个表示和的链表。
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[7,0,8]
// 解释：342 + 465 = 807.
// 示例 2：
// 输入：l1 = [0], l2 = [0]
// 输出：[0]
// 示例 3：
// 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// 输出：[8,9,9,9,0,0,0,1]
// 每个链表中的节点数在范围 [1, 100] 内
// 0 <= Node.val <= 9
// 题目数据保证列表表示的数字不含前导零
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* head = new ListNode(0);
        ListNode* ans = head;
        int cnt = 0;
        while(l1&&l2){
            int num = (l1->val+l2->val+cnt)%10;
            cnt = (l1->val+l2->val+cnt)/10;
            head->next = new ListNode(num);
            head = head->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int num = (l1->val+cnt)%10;
            cnt = (l1->val+cnt)/10;
            head->next = new ListNode(num);
            head = head->next;
            l1 = l1->next;
        }
        while(l2){
            int num = (l2->val+cnt)%10;
            cnt = (l2->val+cnt)/10;
            head->next = new ListNode(num);
            head = head->next;
            l2=l2->next;
        }
        if(cnt)
            head->next = new ListNode(cnt);
        
        return ans->next;
    }
};