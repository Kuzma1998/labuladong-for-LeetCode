/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-13 15:48:42
 */
// 请定义一个队列并实现函数 max_value 得到队列里的最大值，
// 要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
// 若队列为空，pop_front 和 max_value 需要返回 -1

// 思路：单调队列
class MaxQueue {
private:
    queue<int> data_q;
    deque<int> max_q;// 存最大值，单调递减
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(data_q.empty()||max_q.empty())
            return -1;
        return max_q.front();
    }
    void push_back(int value) {
        data_q.push(value);
        while(!max_q.empty()&&value>max_q.back())
            max_q.pop_back();
        max_q.push_back(value);
    }
    
    int pop_front() {
        if(data_q.empty()||max_q.empty())
            return -1;
        int res = data_q.front();
        if(data_q.front()==max_q.front()){
            max_q.pop_front();
        }
        data_q.pop();
        return res;
            
            
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */