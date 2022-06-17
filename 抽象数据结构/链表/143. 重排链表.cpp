/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-27 14:38:26
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-27 14:55:23
 */

// 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
//  L0 → L1 → … → Ln-1 → Ln 
// 请将其重新排列后变为：
// L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
// 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

// 思路：将链表节点存入vector 然后一次按照题目要求进行节点交换

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head||!head->next){
            return ;
        }
        vector<ListNode*> v;
        ListNode* node =head;
        while(node){
            v.push_back(node);
            node = node->next;
        }
        ListNode *new_node = head;
        // new_node->next = head;
        for(int start=1,end = v.size()-1;start<=end;++start,--end){
            if(start<end){  //重排
            new_node->next = v[end];
            new_node = new_node->next;
            new_node->next = v[start];
            new_node = new_node->next;
            }else{   //指向最后一个节点
                new_node->next = v[start];
                new_node= new_node->next;
                break;
            }
        }
        new_node->next = nullptr;  //最后一个节点指向null
        return;
    }
};

class Solution {
public:
        void reorderList(ListNode* head) {
            if (!head) return;
            vector<ListNode*> vec;
            ListNode* cur = head;

            while (cur) {
                vec.push_back(cur);
                cur = cur->next;
            }

            int left = 0;
            int right = vec.size() - 1;
            while (left < right) {
                vec[left]->next = vec[right];
                vec[right--]->next = vec[++left];
            }
            vec[left]->next = nullptr;
        }
};

// 时间复杂度：O(N)，其中 N 是链表中的节点数。
// 空间复杂度：O(N)，其中 N 是链表中的节点数。主要为线性表的开销。




// 方法2  

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};
