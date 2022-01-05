// 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
// 实现 MyStack 类：
// void push(int x) 将元素 x 压入栈顶。
// int pop() 移除并返回栈顶元素。
// int top() 返回栈顶元素。
// boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。


class MyStack {
private:
    queue<int> inq;
    queue<int> outq;
public:
    MyStack() {

    }
    
    void push(int x) {
        inq.push(x);
    }
    
    int pop() {
        int results;
        // 弹出inq只剩最后一个元素
        int size = inq.size()-1;
        while(size--){
            outq.push(inq.front());
            inq.pop();
        }
        //最后一个元素就是结果
        results = inq.front();
        inq.pop();
        // 恢复inq与outq
        inq = outq;
        while(!outq.empty()){
            outq.pop();
        }
        return results;
    }
    
    int top() {
        // 弹出所有元素，result自然就是最后一个元素
        int results;
        while(!inq.empty()){
            results = inq.front();
            outq.push(inq.front());
            inq.pop();
        }
        // 恢复inq outq
        inq = outq;
        while(!outq.empty()){
            outq.pop();
        }
        return results;
    }
    
    bool empty() {
        if(inq.empty())
            return true;
        return false;
    }
};
