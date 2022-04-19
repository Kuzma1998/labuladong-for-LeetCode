// 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
// 实现 MinStack 类:
// MinStack() 初始化堆栈对象。
// void push(int val) 将元素val推入堆栈。
// void pop() 删除堆栈顶部的元素。
// int top() 获取堆栈顶部的元素。
// int getMin() 获取堆栈中的最小元素。

class MinStack {
private:
    stack<int> data;
    stack<int> minNum;//辅助栈，用来维护最小值 是单调的
public:
    MinStack() {
    }
    
    void push(int val) {
        data.push(val);
        // 如果栈为空 或者值小等于栈顶最小直，压栈
        if(minNum.empty()||val<=minNum.top()){
            minNum.push(val);
        }
    }
    
    void pop() {
        if(data.top()==minNum.top()){
            minNum.pop();
        }
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return minNum.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */