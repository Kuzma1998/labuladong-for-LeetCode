// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] =
//  [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

// 示例 1：
// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2：
// 输入：intervals = [[1,4],[4,5]]
// 输出：[[1,5]]
// 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。




class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        if(sz==1)
            return intervals;
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];});
        

        vector<vector<int>> ans;
        int minV = intervals[0][0];
        int maxV = intervals[0][1];
        for(int i=1;i<sz;i++){
            // 如果右端的数小于下一个的左端了，插入结果 ，更新最大最小
            if(maxV<intervals[i][0]){
                ans.push_back({minV,maxV});
                maxV = intervals[i][1];
                minV = intervals[i][0];
            }
            如果右端的大于下一个的左端且小于右端
            else if(maxV<intervals[i][1]){
                maxV = intervals[i][1];
            }
            if(i==sz-1)
                    ans.push_back({minV,maxV});
        }
        return ans;
    }
};



// vector<vector<int>> merge(vector<vector<int>>& intervals) {
//     sort(intervals.begin(), intervals.end());
//     vector<vector<int>> ans;
//     for (int i = 0; i < intervals.size();) {
//         int t = intervals[i][1];
//         int j = i + 1;
            //双指针  当维护的右边大于等于下一个的左边时，一直更新
//         while (j < intervals.size() && intervals[j][0] <= t) {
//             t = max(t, intervals[j][1]);
//             j++;
//         }
//         ans.push_back({ intervals[i][0], t });
//         i = j;
//     }
//     return ans;
// }
