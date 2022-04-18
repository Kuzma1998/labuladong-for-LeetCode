// 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
// 实现 LRUCache 类：
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；
// 如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，
// 则应该 逐出 最久未使用的关键字。
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。


// 哈希表和双向链表

class LRUCache {
struct DoubleListNode{
    int key,val;
    DoubleListNode* pre;
    DoubleListNode* next;
    DoubleListNode():key(0),val(0),pre(nullptr),next(nullptr){}
    DoubleListNode(int k,int v):key(k),val(v),pre(nullptr),next(nullptr){}
};

struct DoubleList{
    DoubleListNode* head = new DoubleListNode();
    DoubleListNode* tail = new DoubleListNode();
    int size = 0;
    DoubleList(){
        tail->pre = head;
        head->next = tail;
    }
    void Delete(DoubleListNode* x){
        if(size==0)
            return;
        x->pre->next =x->next;
        x->next->pre = x->pre;
        --size;
    }
    void InsertTail(DoubleListNode* x){
        x->pre = tail->pre;
        tail->pre->next = x;
        x->next = tail;
        tail->pre = x;
        ++size;
    }
    void DeleteFirst(){
        if(head->next==tail)
            return;
        Delete(head->next);
    }
    int Size(){
        return size;
    }

};
unordered_map<int,DoubleListNode*> mp;
int cap = 0;
DoubleList cache;
public:
    LRUCache(int capacity):cap(capacity) {
    }
    int get(int key) {
        // 若key不在哈希表
        if(mp.find(key)==mp.end())
            return -1;
        // 若key在哈希表
        // 删除key对应的节点，再添加到队列尾部 返回值
        auto node = mp[key];
        cache.Delete(node);
        cache.InsertTail(node);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        // 若是修改key，则修改哈希表的值，删除节点，加入尾部
        if(mp.find(key)!=mp.end()){
            mp[key]->val = value;
            auto node = mp[key];
            cache.Delete(node);
            cache.InsertTail(node);
        }else{
        // 若不是修改key
        //     若队列没有满，则最直接加入到链表尾部，加入哈希
        //     若队列满了，则删除节点  加入尾部
            if(cache.Size()<cap){
                auto node = new DoubleListNode(key,value);
                mp[key] = node;
                cache.InsertTail(node);
            }else if(cache.Size()==cap){
                auto del = cache.head->next;
                cache.DeleteFirst();
                mp.erase(del->key);
                auto node = new DoubleListNode(key,value);
                mp[key] = node;
                cache.InsertTail(node);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */