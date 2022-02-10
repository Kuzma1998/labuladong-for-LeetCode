// 请根据每日 气温 列表 temperatures ，请计算在每一天需要等几天才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。
// 输入: temperatures = [73,74,75,71,69,72,76,73]
// 输出: [1,1,4,2,1,1,0,0]

// 思路：单调栈
// 对于每个新元素，若他小于等于栈顶元素，则把他加入栈，
// 否则，将栈顶元素弹出，计算相应的结果，当栈顶的元素大于当前元素或者栈为空时，则将该元素入栈

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> results(temperatures.size(),0);
        stack<int> stk;
        stk.push(0);
        for(int i=1;i<temperatures.size();++i){
            if(temperatures[i]<=temperatures[stk.top()])//当前元素小于等于栈顶元素,入栈
                stk.push(i);
            else{
                while(!stk.empty() && temperatures[i]>temperatures[stk.top()]){ //当栈不为空且当前温度大于栈顶元素的温度时
                    results[stk.top()] = i-stk.top();//计算结果
                    stk.pop();//出栈
                }
                stk.push(i);//当当前温度小于栈顶元素温度或者栈为空时入栈
            }
        }
        return results;
    }
};