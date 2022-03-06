// 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值
// 。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。



class MedianFinder {
private:
    priority_queue<int,vector<int>,less<int>> max_heap;// 最大堆
    priority_queue<int,vector<int>,greater<int>> min_heap;// 最小堆
    //最小堆的最小大于最大堆的最大
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(min_heap.size()>=max_heap.size()){
            min_heap.push(num);
            max_heap.push(min_heap.top());
            min_heap.pop();
        }else{
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    double findMedian() {
        if(min_heap.size()>max_heap.size())
            return min_heap.top();
        else if(min_heap.size()<max_heap.size())
            return max_heap.top();
        else 
            return (min_heap.top()+max_heap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */