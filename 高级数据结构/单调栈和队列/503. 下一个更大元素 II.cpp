// 给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的 下一个更大元素 。
// 数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，
// 这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1 。
// 输入: nums = [1,2,1]
// 输出: [2,-1,2]
// 解释: 第一个 1 的下一个更大的数是 2；
// 数字 2 找不到下一个更大的数； 
// 第二个 1 的下一个最大的数需要循环搜索，结果也是 2


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        stk.push(0);
        auto p = new vector<int>;
        for(int i=0;i<nums.size();++i){
            p->push_back(nums[i]);
        }
        for(int i=0;i<nums.size();++i){
            p->push_back(nums[i]);
        }
        vector<int> results(p->size(),-1);
        for(int i=1;i<p->size();++i){
            if(p->at(i)<=p->at(stk.top()))
                stk.push(i);
            else{
                while(!stk.empty()&&p->at(i)>p->at(stk.top())){
                    results[stk.top()] = p->at(i);
                    stk.pop();
                }
                stk.push(i);
            }
        }
        results.resize(p->size()/2);
        delete p;
        return results;
    }
};