// 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
// 实现 MyQueue 类：
// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false

// 思路：用两个堆栈来模拟队列，一个出一个入
class MyQueue {
private:
    stack<int> input;
    stack<int> output;
public:
    MyQueue() {
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        // 当出栈为空，把入栈里的元素加进去
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
        }
        }
        // 否则一直返回即可。
        int out = output.top();
        output.pop();
        return out;
    }
    
    int peek() {
        int out = this->pop();
        output.push(out);
        return out;
    }
    
    bool empty() {
        return input.empty()&&output.empty();
    }
};
