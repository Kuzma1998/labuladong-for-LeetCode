/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-09-27 15:46:33
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-09-27 16:31:11
 */

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

// 思路 两两合并，合并k-1次
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {} 构造函数
 *     ListNode(int x) : val(x), next(nullptr) {} 构造函数
 *     ListNode(int x, ListNode *next) : val(x), next(next) {} 构造函数
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0){
            return nullptr;
        }else if(k==1){
            return lists[0];
        }else{
            ListNode* new_List = lists[0];
            for(int i=1;i<k;++i){
                new_List = mergeTList(new_List,lists[i]);
            }
            return new_List;
        }
    }

//     ListNode* mergeTwoLists(ListNode *a, ListNode *b) {  迭代
//     if ((!a) || (!b)) return a ? a : b;
//     ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
//     while (aPtr && bPtr) {
//         if (aPtr->val < bPtr->val) {
//             tail->next = aPtr; aPtr = aPtr->next;
//         } else {
//             tail->next = bPtr; bPtr = bPtr->next;
//         }
//         tail = tail->next;
//     }
//     tail->next = (aPtr ? aPtr : bPtr);
//     return head.next;
// }


    ListNode* mergeTList(ListNode* l1, ListNode*l2){  //递归
        if(!l1) 
            return l2;
        if(!l2)
            return l1;
        if(l1->val<=l2->val){
            l1->next = mergeTList(l1->next,l2);
            return l1;
        }else{
            l2->next = mergeTList(l1,l2->next);
            return l2;
        }
    }
};


// 解法2  分治，优化合并方法，两两合并，直至变为1个
class Solution {
public:
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr; aPtr = aPtr->next;
            } else {
                tail->next = bPtr; bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    ListNode* merge(vector <ListNode*> &lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};


// 思路三 优先队列
// 这个方法和前两种方法的思路有所不同，我们需要维护当前每个链表没有被合并的元素的最前面一个，
// k 个链表就最多有 k个满足这样条件的元素，每次在这些元素里面选取 val 属性最小的元素合并到答案中。
// 在选取最小元素的时候，我们可以用优先队列来优化这个过程。

class Solution {
public:
    struct comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    priority_queue<ListNode*, vector<ListNode*>, comp> q;// 传入三个参数，数据类型，容器和自定义的比较函数(自定义结构体重载()运算符)

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push(node);
        }
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while (!q.empty()) {
            ListNode* node = q.top();
            q.pop();
            tail->next = node; 
            tail = tail->next;
            if (node->next) q.push(node->next);
        }
        return head->next;
    }
};