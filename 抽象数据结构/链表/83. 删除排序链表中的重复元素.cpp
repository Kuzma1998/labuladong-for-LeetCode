/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-08 19:29:16
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-28 12:33:02
 */
// 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。
// 返回同样按升序排列的结果链表。
// 输入：head = [1,1,2]
// 输出：[1,2]

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // base case
        // if(!head)
        //     return nullptr;
        if(!head&&!head->next)
            return head;

        ListNode* cur = head;
        ListNode* next;
        while(cur&&cur->next){
            next = cur->next;
            // 注意next要写在&&的左边！！！
            while(next&&cur->val==next->val){
                next = next->next;    
            }
            cur->next = next;
            cur = next;
        }
        return head;
    }
};

 