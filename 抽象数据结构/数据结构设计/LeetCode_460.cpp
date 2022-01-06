#include<iostream>
#include<unordered_map>
using namespace std;

// 思路
// 维护一个哈希表存keyto(key，val);维护一个哈希表存keytofreq，维护一个哈希表存freqtokey hashmap<key，doublist>


struct Node{
    int key,val;
    Node* next; //Node* 指针，不可以用Node next
    Node* prev;
    Node(int k,int v){
        this->val =v; // key对应的值
        this->key = k;
    }
};

struct DoubleList{
    Node* head = new Node(0,0);
    Node* tail = new Node(0,0);
    int size;
    DoubleList(){
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addLast(Node* x){
        x->prev = tail->prev;
        x->next = tail;
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }
    void remove(Node* x){
        if(!x)
            return;
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size--;
    }
    Node* removeFirst(){
        if(head->next==tail)
            return nullptr;
        Node* first = head->next;
        remove(first);
        return first;
    }
    int Size(){
        return size;
    }
};

class LFUCache {
private:
    unordered_map<int,Node*> keytoVal;
    unordered_map<int,int> keytoFreq;
    unordered_map<int,DoubleList> FreqtoKey;
    int minFreq;
    int cap;
public:
    LFUCache(int capacity) {
        this->cap = capacity;
        this->minFreq = 0;// 插入一个新节点变为1或者get操作时+1
    }
    
    int get(int key) {
        // key 不存在返回-1
        if(!keytoVal.count(key))
            return -1;
        increaseFreq(key); // 存在的话，把key对应的freq加1，freqtokey也要改变
        return keytoVal[key]->val;

    }
    
    void put(int key, int value) {
        if(this->cap==0) // cap为0直接退出
            return;
            // key已经存在
        if(keytoVal.count(key)){
            keytoVal[key]->val = value; //更新value
            increaseFreq(key); // 更新keytofreq与freqtokey
            return;
        }
        // 不存在key，先判断是否满了
        if(keytoVal.size()==this->cap){
            removeMinFreqKey(); //删掉freq最少的，若存在多个则删掉最晚使用的
        }
        // 没满直接插入即可
        Node* x = new Node(key,value);
        keytoVal[key] = x;
        keytoFreq[key] = 1;
        this->minFreq =1;
        // 更新keytofreq
        if(FreqtoKey.count(1)){
           FreqtoKey[1].addLast(x);
        }else{
            DoubleList dblst;
            dblst.addLast(x);
            FreqtoKey[1] =  dblst;
        }

    }
    void increaseFreq(int key){
        Node* x = keytoVal[key]; //获取节点
        int freq = keytoFreq[key]; //获取频率
        keytoFreq[key] = freq+1;  // 频率加1
        FreqtoKey[freq].remove(x); // 原来freq对应的key队列删除x
        FreqtoKey[freq+1].addLast(x);// freq+1对应的队列加入x
        if(FreqtoKey[freq].Size()==0){
            FreqtoKey.erase(freq); // freq对象的队列删掉x之后加如果为空就删掉
            if(freq ==this->minFreq){
                this->minFreq++; // 更新minFreq
            }     
        } 
    }
    // 删除freq最小的key，若这样的key有多个，那么删除最久未使用的key
    void  removeMinFreqKey(){
        // 删除队列的第一个
        Node* x = FreqtoKey[this->minFreq].removeFirst();
        // 判断是否移除队列
        if(FreqtoKey[this->minFreq].Size()==0){
            FreqtoKey.erase(this->minFreq);
        }
        // 更新keytoval，keytofreq
        if(x){        
            keytoVal.erase(x->key);
            keytoFreq.erase(x->key);
        }
    }
};


// int main(){
//     LFUCache cache(2);
//     cache.put(1,1);
//     cache.put(2,2);
//     cout<<cache.get(1)<<endl;
//     cache.put(3,3);
//     cout<<cache.get(2)<<endl;
//     cout<<cache.get(3)<<endl;
//     cache.put(4,4);
//     cout<<cache.get(1)<<endl;
//     cout<<cache.get(3)<<endl;
//     cout<<cache.get(4)<<endl;
//     return 0;
// }