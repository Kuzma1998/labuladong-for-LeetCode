// 输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
// 输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> sorted(people.begin(),people.end());
        // 根据身高排序,高在前，若高一样 则位置在前的在前面
        sort(sorted.begin(),sorted.end(),[](vector<int> a,vector<int> b){
            if(a[0]==b[0])
                return a[1]<b[1];
            return a[0]>b[0];
        });
        // 然后一个一个插入到新的队列，第二个坐标就是这个人所在的迭代器的位置
        vector<vector<int>> ans;
        for(auto person:sorted){
            ans.insert(ans.begin()+person[1],person);
        }
        return ans;
    }
};