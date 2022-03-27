// 给你一个会议时间安排的数组 intervals ，
// 每个会议时间都会包括开始和结束的时间 intervals[i] = [starti, endi] ，返回 所需会议室的最小数量 。
// 示例 1：
// 输入：intervals = [[0,30],[5,10],[15,20]]
// 输出：2
// 示例 2：
// 输入：intervals = [[7,10],[2,4]]
// 输出：1
// 排序  把所有的时间按顺序排列，若同一时刻 即离开又进入，则离开在前面
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int,int>> ComeOut;
        // 进入会议加1，出来减去1
        for(auto elem:intervals){
            ComeOut.push_back({elem[0],1});
            ComeOut.push_back({elem[1],-1});
        }
        sort(ComeOut.begin(),ComeOut.end(),
        [](pair<int,int> p1,pair<int,int> p2){
            if(p1.first==p2.first)
                return p1.second<p2.second;
            return p1.first<p2.first;}
            );
        int cnt = 0;
        int min_num = -1;
        for(auto elem:ComeOut){
            cnt += elem.second;
            min_num = max(cnt,min_num);
        }
        return min_num;
    }
};