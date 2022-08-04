/*给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。
示例 1:
输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:
输入: intervals = [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
*/

// 按照右边界排序，从左向右记录非交叉区间的个数。最后用区间总数减去非交叉区间的个数就是需要移除的区间个数了。
// 此时问题就是要求非交叉区间的最大个数。
// 右边界排序之后，局部最优：优先选右边界小的区间，所以从左向右遍历，留给下一个区间的空间大一些，
// 从而尽量避免交叉。全局最优：选取最多的非交叉区间。
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 按照右区间排序
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        // 记录非重叠有元素的区间个数
        int noOverLap = 1;
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();++i){
            // 如果前一个区间的尾部小于等于这个区间的头部，更新数量和上一个区间的位置
            // 否则跳过，因为跳过才有可能使得更多的区间非重复
            if(end<=intervals[i][0]){
                ++noOverLap;
                end = intervals[i][1];
            }
        }
        return intervals.size()-noOverLap;
    }
};
