/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-13 15:32:02
 */
// 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
// 示例:
// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
// 输出: [3,3,5,5,6,7] 
// 解释: 
//   滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

// 思路：优先队列 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> q;
        if(nums.size()==0)
            return ans;
        for(int i=0;i<k;++i){
            q.push({nums[i],i});
        }
        ans.push_back(q.top().first);
        for(int i=k;i<nums.size();++i){
            q.push({nums[i],i});
            while(!q.empty()&&q.top().second<i-k+1) //当最大元素已经不在窗口内，需要pop
                q.pop();
            ans.push_back(q.top().first);
        }
        return ans;
    }
};

// 单调队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size()==0)
            return ans;
        deque<int> dq;
        for(int i=0;i<k;++i){
            while(!dq.empty()&&nums[i]>dq.back())// 维持单调队列
                dq.pop_back();
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());
        for(int i=k;i<nums.size();++i){
            if(dq.front()==nums[i-k])
                dq.pop_front();// 维持滑动窗口
            while(!dq.empty()&&nums[i]>dq.back())
                dq.pop_back();
            dq.push_back(nums[i]);
            ans.push_back(dq.front());
        }
        return ans;
    }
};