/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-13 21:58:54
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-13 21:59:59
 */
// 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
// 你可以假设除了数字 0 之外，这两个数字都不会以零开头。

// 输入：l1 = [7,2,4,3], l2 = [5,6,4]
// 输出：[7,8,0,7]

//堆栈
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2,s3;
        //堆栈存l1
        while(l1){
            s1.push(l1->val);
            l1 =l1->next;
        }
        //堆栈存l2
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode *head =nullptr,*tail = nullptr;
        int carry = 0;
        while(!s1.empty()||!s2.empty()||carry){
            int n1 = (s1.empty())?0:s1.top();
            int n2 = (s2.empty())?0:s2.top();
            if(!s1.empty())
                s1.pop();
            if(!s2.empty())
                s2.pop();
            int sum = n1+n2+carry;
            s3.push(sum%10);
            carry = sum/10;
        }
        while(!s3.empty()){
            if(!head){
                head = tail = new ListNode(s3.top());
            }else{
                tail->next = new ListNode(s3.top());
                tail = tail->next;
            }
            s3.pop();
        }
        return head;
    }
};


// 反转三次链表
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode *head=nullptr,*tail = nullptr;
        int carry=0;
        while(l1||l2){
            int n1 = l1?l1->val:0;
            int n2 = l2?l2->val:0;
            int sum = n1+n2+carry;
            if(!head){
                head = tail = new ListNode(sum%10);
            }else{
                tail->next = new ListNode(sum%10);
                tail = tail->next;
            }
            carry = sum/10;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(carry)
            tail->next = new ListNode(carry);
        return reverseList(head);
    }
    ListNode* reverseList(ListNode* head){
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        while(l1||l2){  // l1 l2 入栈
            if(l1){
                s1.push(l1->val);
                l1 = l1->next;
            }
            if(l2){
                s2.push(l2->val);
                l2 = l2->next;
            }
        }
        int flag = 0; //进位
        stack<int> ans;  //保存结果的栈
        while(!s1.empty()&&!s2.empty()){      
            ans.push((s1.top()+s2.top()+flag)%10);
            flag = (s1.top()+s2.top()+flag)/10;
            s1.pop();
            s2.pop();
        }
        while(!s1.empty()){
            ans.push((s1.top()+flag)%10);
            flag = (s1.top()+flag)/10;
            s1.pop();
        }
        while(!s2.empty()){
            ans.push((s2.top()+flag)%10);
            flag = (s2.top()+flag)/10;
            s2.pop();
        }
        if(flag) ans.push(flag);  //最后如果进位为1  要加入栈
        ListNode* ret =  new ListNode(0);
        ListNode* node = ret;
        while(!ans.empty()){
            node->next = new ListNode(ans.top());
            node = node->next;
            ans.pop();
        }
        return ret->next;
    }
};