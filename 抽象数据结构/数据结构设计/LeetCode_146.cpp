// 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
// 实现 LRUCache 类：
// LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」
// 。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

// 思路 利用哈希表和双向链表 LRUCache维护一个哈希表map和双向链表cache，
// 当get时，如果key不在哈希表了里面，那么直接返回-1;若存在，先从链表删除key对应节点，再加到链表尾部,return map[key].val;
//  当put，先检查是不是key已经在map里面，在就更新map[key]->val;删除链表key对应节点，添加新节点
// 当key不在，若队列满了，先删除链表第一个节点，删除map里面的该节点，把key，value所构造节点添加进链表;也加入map
// 未满，则直接加入链表尾部以及map


// 定义节点
struct Node{
    int val;//值
    int key;// 键
    Node* prev;// 前驱
    Node* next; // 后继
    Node(int _key,int _val){
        this->key = _key;
        this->val = _val;
    }
};

struct DoubleList{
    Node* tail=new Node(0,0);
    Node* head=new Node(0,0);
    int size;
    DoubleList(){
        tail->prev = head;
        head->next = tail;
        size = 0;
    }
    void Delete(Node* x){
        x->prev->next= x->next;
        x->next->prev = x->prev;
        size--;
    }
    void InsertTail(Node* x){
        tail->prev->next = x;
        x->prev = tail->prev;
        x->next = tail;
        tail->prev = x;
        size++;
    }
    Node* DeleteFirst(){
        if(head->next == tail)
            return nullptr;
        Node* x = head->next;
        Delete(x);
        return x;
    }
    int Size(){
        return size;
    }
};

class LRUCache {
private:
    // DoubleList cache = DoubleList(2); 若结构体需要赋初值应该这么定义
    DoubleList cache;  // 保证put是0(1)
    unordered_map<int, Node*> map; // 保证get是O(1)
    int cap;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if(!map.count(key))
            return -1;
        cache.Delete(map[key]);
        cache.InsertTail(map[key]);
        return map[key]->val;
        
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            cache.Delete(map[key]);
            map[key]->val = value;
            cache.InsertTail(map[key]);
            return;
        }
        if(cap == cache.Size()){
            Node* first = cache.DeleteFirst();
            map.erase(first->key);
            Node* x = new Node(key,value);
            cache.InsertTail(x);
            map[key] = x;
        }else{
            Node* x = new Node(key,value);
            cache.InsertTail(x);
            map[key] = x;

        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */














// struct DLinkedNode {
//     int key, value;
//     DLinkedNode* prev;
//     DLinkedNode* next;
//     DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
//     DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
// };

// class LRUCache {
// private:
//     unordered_map<int, DLinkedNode*> cache;
//     DLinkedNode* head;
//     DLinkedNode* tail;
//     int size;
//     int capacity;

// public:
//     LRUCache(int _capacity): capacity(_capacity), size(0) {
//         // 使用伪头部和伪尾部节点
//         head = new DLinkedNode();
//         tail = new DLinkedNode();
//         head->next = tail;
//         tail->prev = head;
//     }
    
//     int get(int key) {
//         if (!cache.count(key)) {
//             return -1;
//         }
//         // 如果 key 存在，先通过哈希表定位，再移到头部
//         DLinkedNode* node = cache[key];
//         moveToHead(node);
//         return node->value;
//     }
    
//     void put(int key, int value) {
//         if (!cache.count(key)) {
//             // 如果 key 不存在，创建一个新的节点
//             DLinkedNode* node = new DLinkedNode(key, value);
//             // 添加进哈希表
//             cache[key] = node;
//             // 添加至双向链表的头部
//             addToHead(node);
//             ++size;
//             if (size > capacity) {
//                 // 如果超出容量，删除双向链表的尾部节点
//                 DLinkedNode* removed = removeTail();
//                 // 删除哈希表中对应的项
//                 cache.erase(removed->key);
//                 // 防止内存泄漏
//                 delete removed;
//                 --size;
//             }
//         }
//         else {
//             // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
//             DLinkedNode* node = cache[key];
//             node->value = value;
//             moveToHead(node);
//         }
//     }

//     void addToHead(DLinkedNode* node) {
//         node->prev = head;
//         node->next = head->next;
//         head->next->prev = node;
//         head->next = node;
//     }
    
//     void removeNode(DLinkedNode* node) {
//         node->prev->next = node->next;
//         node->next->prev = node->prev;
//     }

//     void moveToHead(DLinkedNode* node) {
//         removeNode(node);
//         addToHead(node);
//     }

//     DLinkedNode* removeTail() {
//         DLinkedNode* node = tail->prev;
//         removeNode(node);
//         return node;
//     }
// };

