/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-15 21:49:52
 */

// 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
// 输入: k = 3, n = 9
// 输出: [[1,2,6], [1,3,5], [2,3,4]]

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path; // 路径
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k,n,0,1);
        return ans;
    }

    void backtrack(int k,int n,int sum,int start){
        if(path.size()==k){ // 终止条件
            if(sum==n)
                ans.push_back(path);
            return;
        }
        for(int i=start;i<=9;++i){ // 遍历选择列表
            if(sum+i<=n){
            path.push_back(i); //选择
            sum+=i;
            backtrack(k,n,sum,i+1); // 回溯
            sum-=i; // 撤销选择
            path.pop_back();
            }
        }
        return;
    }
};



// 剪枝优化
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k,n,0,1);
        return ans;
    }

    void backtrack(int k,int n,int sum,int start){
        if(sum>n)
            return; //剪枝
        if(path.size()==k){
            if(sum==n)
                ans.push_back(path);
            return;
        }
        for(int i=start;i<=9-(k-path.size())+1;++i){ // 剪枝，start最多为9-（k-path.size（））+1
            if(sum+i<=n){
                path.push_back(i);
                sum+=i;
                backtrack(k,n,sum,i+1);
                path.pop_back();
                sum-=i;
            }
        }
        return;
    }
};