

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sz = heights.size();
        vector<int> L(sz,0);
        vector<int> R(sz,0);
        L[0] = -1;
        for(int i=1;i<sz;++i){
            // 往左找到第一个小于它的
            int t = i-1;
            while(t>=0&&heights[t]>=heights[i]){
                t = L[t];// --t;
            }
            L[i] = t;
        }
        R[sz-1] = sz;
        // 逆序，才可以用到DP数组
        for(int i=sz-2;i>=0;--i){
            int t = i+1;
            while(t<sz&&heights[t]>=heights[i])
                t = R[t];// ++t;
            R[i] = t;
        }
        int sum = 0;
        for(int i=0;i<sz;++i){
            sum = max(sum,(R[i]-L[i]-1)*heights[i]);
        }
        return sum;
    }
};

// 单调栈 栈顶最大
// 当当前高度小于栈顶对应的高度时，那么形状会是一个凸出的，即可计算面积
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sum = 0;
        heights.insert(heights.begin(),0);
        heights.insert(heights.end(),0);//首尾加入0
        int sz = heights.size();
        stack<int> stk;
        stk.push(0);
        for(int i=1;i<sz;++i){
            while(heights[i]<heights[stk.top()]){
                int md = stk.top();
                stk.pop();
                int left = stk.top();
                int w = i-left-1;
                int h = heights[md];
                sum = max(sum,w*h);
            }
            stk.push(i);
        }
        return sum;
    }
};