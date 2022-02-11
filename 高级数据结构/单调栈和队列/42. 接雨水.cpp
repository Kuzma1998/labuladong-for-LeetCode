// 暴力法
// 第一个和最后一个柱子不会接水，中间的柱子能解的水的大小为其左边最大减去右边最大
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        for(int i=0;i<height.size();++i){
            if(i==0||i==height.size()-1) continue;
            int Rheight = height[i];
            int Leight = height[i];
            for(int j = i+1;j<height.size();++j){
                if(height[j]>Rheight)
                    Rheight = height[j];
            }
            for(int j=i-1;j>=0;--j){
                if(height[j]>Leight)
                    Leight = height[j];
            }
            if(min(Leight,Rheight)-height[i]>0)
                sum += min(Leight,Rheight)-height[i];
        }
        return sum;
    }
};

// dp  记录每个柱子左边和右边最大即可
class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        vector<int> L(sz,0);
        vector<int> R(sz,0);
        int Lmax = height[0];
        int Rmax = height[sz-1];
        for(int i=0;i<sz;++i){
            Lmax = max(height[i],Lmax);
            L[i] = Lmax;
        }
        for(int i = sz-1;i>=0;--i){
            Rmax = max(height[i],Rmax);
            R[i] = Rmax;
        }
        int sum = 0;
        for(int i=0;i<sz;++i){
            if(i==0||i==sz-1)
                continue;
            if(min(L[i],R[i])-height[i]>0)
                sum += min(L[i],R[i])-height[i];
        }   
        return sum;
    }
};

// 单调栈 why栈顶的元素对象height最小，因为要从下往上计算凹槽
// 当栈中至少存在两个元素且新元素大于栈顶索引的元素时，产生凹槽，则计算雨水面积
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int left = stk.top();
                int currWidth = i - left - 1;
                int currHeight = min(height[left], height[i]) - height[top];
                ans += currWidth * currHeight;
            }
            stk.push(i);
        }
        return ans;
    }
};
