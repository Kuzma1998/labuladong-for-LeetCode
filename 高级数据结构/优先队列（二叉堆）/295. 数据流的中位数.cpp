// 中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
// 例如，
// [2,3,4] 的中位数是 3
// [2,3] 的中位数是 (2 + 3) / 2 = 2.5
// 设计一个支持以下两种操作的数据结构：
// void addNum(int num) - 从数据流中添加一个整数到数据结构中。
// double findMedian() - 返回目前所有元素的中位数。
// 示例：
// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3) 
// findMedian() -> 2

class MedianFinder {
private:
    priority_queue<int,vector<int>,less<int>> large; //最大堆
    priority_queue<int,vector<int>,greater<int>> small; //最小堆
public:
    MedianFinder() {

    }
    void addNum(int num) {
        if(small.size()>=large.size()){
            small.push(num);
            large.push(small.top());
            small.pop();
        }else{
            large.push(num);
            small.push(large.top());
            large.pop();
        }
    }
    double findMedian() {
        if(small.size()>large.size())
            return small.top();
        else if(small.size()<large.size())
            return large.top();
        else
            return (small.top()+large.top())/2.0;
    }

};