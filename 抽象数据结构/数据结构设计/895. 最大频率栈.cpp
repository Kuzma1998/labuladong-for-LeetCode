// 设计一个类似堆栈的数据结构，将元素推入堆栈，并从堆栈中弹出出现频率最高的元素。
// 实现 FreqStack 类:
// FreqStack() 构造一个空的堆栈。
// void push(int val) 将一个整数 val 压入栈顶。
// int pop() 删除并返回堆栈中出现频率最高的元素。
// 如果出现频率最高的元素不只一个，则移除并返回最接近栈顶的元素。
// 输入：
// ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
// [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
// 输出：[null,null,null,null,null,null,null,5,7,5,4]
// 解释：
// FreqStack = new FreqStack();
// freqStack.push (5);//堆栈为 [5]
// freqStack.push (7);//堆栈是 [5,7]
// freqStack.push (5);//堆栈是 [5,7,5]
// freqStack.push (7);//堆栈是 [5,7,5,7]
// freqStack.push (4);//堆栈是 [5,7,5,7,4]
// freqStack.push (5);//堆栈是 [5,7,5,7,4,5]
// freqStack.pop ();//返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,5,7,4]。
// freqStack.pop ();//返回 7 ，因为 5 和 7 出现频率最高，但7最接近顶部。堆栈变成 [5,7,5,4]。
// freqStack.pop ();//返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,4]。
// freqStack.pop ();//返回 4 ，因为 4, 5 和 7 出现频率最高，但 4 是最接近顶部的。堆栈变成 [5,7

// 
class FreqStack {
private:
    unordered_map<int,int> ValToFeq;//值对应频率
    unordered_map<int,stack<int>> FeqToVal;//频率对应值
    int max_feq = 0;
public:
    FreqStack() {

    }
    void push(int val) {
        if(!ValToFeq.count(val))
            ValToFeq[val] =1;
        else
            ValToFeq[val]++;
        max_feq = max(max_feq,ValToFeq[val]);
        FeqToVal[ValToFeq[val]].push(val);
    }
    
    // int pop() {
    //     int val = FeqToVal[max_feq].top();
    //     FeqToVal[max_feq].pop();
    //     ValToFeq[val]--;
    //     if(FeqToVal[max_feq].size()==0)
    //         --max_feq;
    //     return  val;
    // }
    int pop() {
        auto& stk = FeqToVal[max_feq];//需要改写堆栈，需要引用！！！
        int val = stk.top();
        stk.pop();
        if(stk.empty()) max_feq--;
        return val;
    }
};
