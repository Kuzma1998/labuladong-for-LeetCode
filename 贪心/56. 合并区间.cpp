// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
// 请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

// 思路：贪心，按照左区间排序，动态更新右区间

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 排序```````````
        sort(intervals.begin(),intervals.end(),
        [](const vector<int> a,const vector<int> b){
            if(a[0]==b[0])
                return a[1]<b[1];
            return a[0]<b[0];});
        
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();++i){
            if(end>=intervals[i][0]){
                end = max(intervals[i][1],end);//更新end
            }else{
                ans.push_back(vector<int>{start,end}); //加入数组
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back(vector<int>{start,end});
        return ans;
    }
};


// 代码随想录
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> result;
//         if (intervals.size() == 0) return result;
//         // 排序的参数使用了lamda表达式
//         sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});

//         result.push_back(intervals[0]);
//         for (int i = 1; i < intervals.size(); i++) {
//             if (result.back()[1] >= intervals[i][0]) { // 合并区间
//                 result.back()[1] = max(result.back()[1], intervals[i][1]);
//             } else {
//                 result.push_back(intervals[i]);
//             }
//         }
//         return result;
//     }
// };