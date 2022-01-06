/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-06 19:05:33
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-06 19:33:55
 */

// 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

// 思路，判断回文字符串，直接双指针即可，但是单链表不能使用双指针，因此要先将链表逆序输出再进行比较，
// 链表的后序遍历可以逆序输出链表，只需要输出的时候与表头对应元素进行比较即可

class Solution {
private:
    ListNode* left;
public:
    bool isPalindrome(ListNode* head) {
        left = head;
        return postorder(head);
    }
    // 链表后续遍历会倒序打印链表，因此进行比较
    bool postorder(ListNode* right){
        if(right==nullptr)
            return true;
        bool res = postorder(right->next);
        res = res&&(left->val==right->val);
        left = left->next;
        return res;
    }
};
 


// 方法二  仅仅反转一半的链表
class Solution {

public:
    bool isPalindrome(ListNode* head) {
       ListNode* slow = fastSlow(head);
       slow = intravel(slow);
       return ishuiwen(slow,head);
    }
    // 快慢指针先确定链表中间
    ListNode* fastSlow(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        // 链表长度为奇数还要slow移动一次
        if(fast!=nullptr)
            slow = slow->next;
        return slow;
    }
    // 反转链表
    ListNode* intravel(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur!=nullptr){
            ListNode* Next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = Next;
        }
        return pre;
    }
    // 判断是否回文
    bool ishuiwen(ListNode* p,ListNode* q){
        bool flag  = true;
        while(p){
            if(p->val==q->val){
                p = p->next;
                q = q->next;
            }else{
                flag = false;
                break;
            }
        }
        return flag;
    }
};