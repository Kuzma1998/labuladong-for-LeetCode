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
    struct compare{
        bool operator()(ListNode* a,ListNode*b){
             return a->val>b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return nullptr;

        compare c;
        priority_queue<ListNode*,vector<ListNode*>,compare> q(c);// 构造小顶堆

        for(auto list:lists){
            if(list)
                q.push(list);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        while(!q.empty()){
            ListNode* node = q.top();
            dummy->next = new ListNode(node->val);
            dummy = dummy->next;
            q.pop();
            node = node->next;
            if(node)
                q.push(node);
        }
        return ans->next;

    }
};


// 时间复杂度：考虑优先队列中的元素不超过 kk 个，那么插入和删除的时间代价为 
// O(\log k)O(logk)，这里最多有 knkn 个点，对于每个点都被插入删除各一次，
// 故总的时间代价即渐进时间复杂度为 O(kn \times \log k)O(kn×logk)。
// 空间复杂度：这里用了优先队列，优先队列中的元素不超过 kk 个，故渐进空间复杂度为 O(k)O(k)。

// 对于顺序插入 第i次插入为O(i*n),插入k次，因此就是O(k2n)的时间复杂度
// 空间复杂度为o（1）

