/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-16 18:49:08
 */
// 给你一个无重复元素的整数数组candidates和一个目标整数target找出candidates中可以使数字和为目标数target的所有不同组合，
// 并以列表形式返回。你可以按 任意顺序 返回这些组合。
// candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
// 对于给定的输入，保证和为 target 的不同组合数少于 150 个
// 输入：candidates = [2,3,6,7], target = 7
// 输出：[[2,2,3],[7]]
// 解释：
// 2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
// 7 也是一个候选， 7 = 7 。
// 仅有这两种组合。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/combination-sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
// https://programmercarl.com/0039.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C.html#%E5%9B%9E%E6%BA%AF%E4%B8%89%E9%83%A8%E6%9B%B2
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates,target,0,0);
        return ans;
    }
    // 
    void backtrack(vector<int>& candidates, int target,int sum,int start){
        if(sum==target){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<candidates.size();++i){
            if(sum+candidates[i]<=target){
                sum += candidates[i];
                path.push_back(candidates[i]);
                backtrack(candidates,target,sum,i); 
                // 注意填的i,假设是在2这一层，i=0,进去还可以取到2，一旦取了3，就不可以往回走了,不然就重复了.
                // i表示重复取当前的数
                sum-=candidates[i];
                path.pop_back();
            }
        }
        return;
    }
};


// 剪枝
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        // 如果 sum + candidates[i] > target 就终止遍历
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();

        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end()); // 需要排序
        backtracking(candidates, target, 0, 0);
        return result;
    }
};