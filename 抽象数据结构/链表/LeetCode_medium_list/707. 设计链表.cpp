// 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 
// 是当前节点的值，next 是指向下一个节点的指针/引用。
// 如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
// 在链表类中实现这些功能：
// get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
// addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
// addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
// addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，
// 则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
// deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

// MyLinkedList linkedList = new MyLinkedList();
// linkedList.addAtHead(1);
// linkedList.addAtTail(3);
// linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
// linkedList.get(1);            //返回2
// linkedList.deleteAtIndex(1);  //现在链表是1-> 3
// linkedList.get(1);            //返回3


class MyLinkedList {
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(nullptr){   
    }
};
ListNode* dummy = new ListNode(0);
int sz = 0;
public:
    MyLinkedList() {
    }
    int get(int index) {
        if(index<0||index>=sz){
            return -1;
        }
        ListNode* cur = dummy->next;
        while(index){
            cur =  cur->next;
            index--;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = dummy->next;
        dummy->next = node;
        ++sz;
        // printLinkedList();
    }
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        ListNode* cur = dummy->next;
        ListNode* pre = dummy;
        while(cur){
           pre = cur;
           cur = cur->next;
        }
        pre->next = node;
        ++sz;
        // printLinkedList();
    }
    
    void addAtIndex(int index, int val) {
        if(index<=0){
            addAtHead(val);
        }
        else if(index==sz){
            addAtTail(val);
        }else if(index>sz){
            return;
        }else{
            ++sz;
            ListNode* cur = dummy->next;
            ListNode* pre = dummy;
            while(index--){
                pre = cur;
                cur = cur->next;
            }
            ListNode* node = new ListNode(val);
            pre->next = node;
            node->next = cur;
            // printLinkedList();
        }


    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>=sz){
            return;
        }else{
            --sz;
            ListNode* cur = dummy->next;
            ListNode* pre = dummy;
            while(index--){
                pre = cur;
                cur = cur->next;
            }
            pre->next = cur->next;
        }
        // printLinkedList();
    }
    void printLinkedList() {
        ListNode* cur = dummy;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }   
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */