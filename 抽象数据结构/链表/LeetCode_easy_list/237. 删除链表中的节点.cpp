/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-08 17:28:12
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-08 17:29:14
 */

// 请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点。传入函数的唯一参数为 要被删除的节点 。
// 传入的只是要被删除的节点，借尸还魂，把node的值变成下一个的值，然后把下一个删掉即可。

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};