/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-10 21:07:49
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-10 21:08:50
 */
// 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
// 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。
// 说明：不允许修改给定的链表。

// 快慢指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* node = head;
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){// slow 与fast相遇
                while(node!=slow){ // node与slow移动相同步数一定会相遇，
                // 证明简单，slow没走完一圈一定与fast相遇
                    node=node->next;
                    slow = slow->next;
                }
                return node;
            }
        }
        return nullptr;
    }
};

// 哈希表
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> map;
        ListNode* node = head;
        while(node){
            if(!map.count(node)){
                map[node] = 1;
                node = node->next;
            }else{
                return node;
            }
        }
        return NULL;
    }
};