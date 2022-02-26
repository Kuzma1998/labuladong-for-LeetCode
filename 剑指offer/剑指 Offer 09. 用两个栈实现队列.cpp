// 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分
// 别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )


class CQueue {
private:
    stack<int> instk;// 入栈
    stack<int> outstk;// 出栈
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        instk.push(value);
    }
    
    int deleteHead() { //每次弹出元素先把入栈里的弹到出栈，返回出栈的第一个，再把出栈的元素移动到入栈
        if(instk.empty())
            return -1;
        while(!instk.empty()){
            outstk.push(instk.top());
            instk.pop();
        }
        int ans = outstk.top();
        outstk.pop();
        while(!outstk.empty()){
            instk.push(outstk.top());
            outstk.pop();
        }
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

// 优化 若出栈有元素则弹出即可，否则把入栈的元素弹入出栈即可
//  public int deleteHead() {
//         if(!stack2.isEmpty()){
//             return stack2.pop();
//         }else{
//             while(!stack1.isEmpty()){
//                 stack2.push(stack1.pop());
//             }
//             return stack2.isEmpty() ? -1 : stack2.pop();
//         }
//     }
// }