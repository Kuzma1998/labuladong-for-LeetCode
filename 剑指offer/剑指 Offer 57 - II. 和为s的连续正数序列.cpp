// 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
// 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
// 示例 1：
// 输入：target = 9
// 输出：[[2,3,4],[4,5]]
// 示例 2：
// 输入：target = 15
// 输出：[[1,2,3,4,5],[4,5,6],[7,8]]
// 回溯
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    int num = 0;
public:
    vector<vector<int>> findContinuousSequence(int target) {
        num = target/2+1;
        backtarack(target,1);
        return ans;
    }
    void backtarack(int target,int index){
        if(target==0){
            ans.push_back(path);
            return;
        }
        for(int i=index;i<=num;++i){
            if(target-i<0)
                break;
            if(path.size()==0)
                path.push_back(i);
            else if(i!=path.back()+1)
                continue;
            else if(path.size()!=0)
                path.push_back(i);
            backtarack(target-i,i+1);
            path.pop_back();
        }
    }
};

// 双指针
