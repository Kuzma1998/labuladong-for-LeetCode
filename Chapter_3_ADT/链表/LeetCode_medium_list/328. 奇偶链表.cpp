/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-13 19:50:24
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-13 19:51:25
 */
// 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
// 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
// 示例 1:
// 输入: 1->2->3->4->5->NULL
// 输出: 1->3->5->2->4->NULL


// 链表内部改变
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = even;// 后面要将head与偶节点相连
        while(even&&even->next){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};


// 分离链表一样的解法
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode* res_odd =odd;
        ListNode* res_even = even;
        int i=1;
        while(head){
            if((i%2)==1){
                odd->next = new ListNode(head->val);
                odd = odd->next;
            }else{
                even->next = new ListNode(head->val);
                even = even->next;
            }
            i++;
            head = head->next;
        }
        even->next = nullptr;
        odd->next = res_even->next;
        return res_odd->next;
    }
};

