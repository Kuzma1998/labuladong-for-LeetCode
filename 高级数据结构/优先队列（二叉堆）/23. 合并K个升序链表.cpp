// 给你一个链表数组，每个链表都已经按升序排列。
// 请你将所有链表合并到一个升序链表中，返回合并后的链表。
// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
// 输出：[1,1,2,3,4,4,5,6]
// 解释：链表数组如下：
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 将它们合并到一个有序链表中得到。
// 1->1->2->3->4->4->5->6

// 思路:优先队列
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
class Solution {
public:
    struct comp{
        bool operator()(ListNode* a,ListNode* b){
            return a->val>b->val;
        }
    };
    // 重载了（）的类
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp> q;//传入这个类,最小堆
        ListNode* head = new ListNode(0);
        ListNode* tail=head;
        if(lists.size()==0)
            return head->next;
        for(auto i:lists){
            if(i)
                q.push(i);
        }

        while(!q.empty()){
            ListNode* temp = q.top(); //链表头部一定是元素最小的
            q.pop();
            tail->next = temp;
            tail = tail->next;
            if(temp->next)
                q.push(temp->next); //若这个链表不为空，在插入
        }
        return head->next;
    }
};


