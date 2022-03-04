// 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
// 示例:
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.min();   --> 返回 -3.
// minStack.pop();
// minStack.top();      --> 返回 0.
// minStack.min();   --> 返回 -2.



class MinStack {
private:
    stack<int> data_stk;
    stack<int> min_stk;//数据从栈顶到栈底递增
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if(min_stk.empty()||x<=min_stk.top()){
            min_stk.push(x);
        }
        data_stk.push(x);
    }
    
    void pop() {
        if(data_stk.top()==min_stk.top())
        {
            min_stk.pop();
            data_stk.pop();
        }else{
            data_stk.pop();
        }
    }
    
    int top() {
        return data_stk.top();
    }
    
    int min() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
