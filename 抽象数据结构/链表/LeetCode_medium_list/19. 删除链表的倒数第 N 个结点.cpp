/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-22 20:41:49
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-22 21:14:01
 */

// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
// 进阶：你能尝试使用一趟扫描实现吗？

// 输入：head = [1,2,3,4,5], n = 2
// 输出：[1,2,3,5]

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next&&n==1)
            return nullptr;
        ListNode* node = head;
        int length = 0;
        while(node){
            ++length;
            node = node->next;
        }
        int num = length-n-1;
        ListNode* start = head;
        if(num<0){
            return head->next;
        }
        else{
            while(num){
                start = start->next;
                --num;
            }
            start->next = start->next->next;
            return head;
        }
    }
};

// 递归，定义一个i为-1，当递归到最后面时把i置0，然后递增i，找到要删除的节点即可
// 函数定义，删除导数第n个节点，并返回头节点
class Solution {
private:
    int i=-1;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            i=0;// 终止条件
            return nullptr;
        }
        head->next = removeNthFromEnd(head->next,n);// 递归函数的定义
        // 后续遍历
        if(i>=0){// 每个节点要干啥
            ++i;
            if(i==n)// 找到要删除的
                return head->next;
        }
        return head;
    }
};

//快慢指针