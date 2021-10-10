/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-22 21:50:31
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-22 21:51:51
 */
// 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //Base case
        if(!head||!head->next)
            return head;
        // 定义变量
        ListNode* node = head;// 求长度
        ListNode* prev;//新的尾节点
        ListNode* pre;// 旧尾部节点

        int length = 0;
        while(node){
            ++length;
            pre = node;
            node = node->next;
        }

        int rotate_times = length-(k%length);
        if(rotate_times==length)
            return head;// 不需要反转
        else{
            ListNode* start = head;// 旋转后的新的头节点
            while(rotate_times){
                prev = start;//旋转后新节点的前一个
                start =start->next;
                --rotate_times;
            }
            prev->next = nullptr;// 新的尾节点
            pre->next = head;// 旧尾节点指向原来的头节点
            return start;// 返回新的头节点
        }  
    }
};