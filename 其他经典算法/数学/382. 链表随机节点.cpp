// 给你一个单链表，随机选择链表的一个节点，并返回相应的节点值。每个节点 被选中的概率一样 。
// 实现 Solution 类：
// Solution(ListNode head) 使用整数数组初始化对象。
// int getRandom() 从链表中随机选择一个节点并返回该节点的值。链表中所有节点被选中的概率相等。

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

// 思路:构造时先把链表存入一个vector容器里面,然后随机取索引
class Solution {
private:
    vector<int> nums;
public:
    Solution(ListNode* head) {
        while(head){
            nums.push_back(head->val);
            head= head->next;
        }
    }
    
    int getRandom() {
        int sz = nums.size();
        return nums[rand()% sz];//随机生成0-sz-1之间的数
    }

};
