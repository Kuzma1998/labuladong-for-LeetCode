/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-11 16:15:49
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-11 16:41:31
 */


// 暴力解法
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode(0);
        ListNode* ret = answer;
        int res = 0;
        while(l1&&l2){
            int a = l1->val+l2->val;
            a = a +res;
            if(a>9){
                a =a-10;
                res = 1;
                answer->next = new ListNode(a);
                answer= answer->next;
            }else{
                answer->next=new ListNode(a);
                answer= answer->next;
                res = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int a =res+l1->val;
            if(a>9){
                a =a-10;
                res = 1;
                answer->next = new ListNode(a);
                answer= answer->next;
            }else{
                answer->next = new ListNode(a);
                answer= answer->next;
                res = 0;
            }
            l1 =l1->next;
        }
        while(l2){
            int a =res+l2->val;
            if(a>9){
                a =a-10;
                res = 1;
                answer->next = new ListNode(a);
                answer= answer->next;
            }else{
                answer->next = new ListNode(a);
                answer= answer->next;
                res = 0;
            }
            l2 =l2->next;
        }
        if(res){
            answer->next = new ListNode(res);
        }
        return ret->next;
    }
};


// 官方答案 比我简单很多

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;// head不变，一直移动tail
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;//总和
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);// 节点存的值
                tail = tail->next;
            }
            carry = sum / 10;//余数
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) { //最后余数大于0还得新建一个节点存起来
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
