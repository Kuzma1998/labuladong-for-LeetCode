// 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
// 输入：head = [1,3,2]
// 输出：[2,3,1]

// 栈
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        stack<int> stk;
        while(head){
            stk.push(head->val);
            head = head->next;
        }
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};


// 递归
class Solution {
private:
    vector<int> ans;
public:
    vector<int> reversePrint(ListNode* head) {
       dg(head);
       return ans;
    }

    void dg(ListNode* head){
        if(head==NULL)
            return;
        dg(head->next);
        ans.push_back(head->val);
    }
};