// 给定一个已按照 非递减顺序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。
// 函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，
// 所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。
// 你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

// 输入：numbers = [2,7,11,15], target = 9
// 输出：[1,2]
// 解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。




// 思路1 哈希表  自己写的垃圾，其实只需遍历一次数组即可

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    // 存入表
        unordered_map<int,int> map;
        for(int i=0;i<numbers.size();++i){
            if(map[numbers[i]]){
                continue;
            }
            map[numbers[i]] = i+1;
        }
    // 找索引
        for(auto number:numbers){
            int i = target-number;
            if(map.count(i)){
                if( i==number)
                    return {map[number],map[number]+1};
                return{map[number],map[i]};
            }
        }
        return {};
    }
};


// 简化版 哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map <int,int> mp;
        int n=numbers.size();
        for(int i=0;i<n;i++){
            auto it=mp.find(target-numbers[i]);
            if(it!=mp.end()){
                return {it->second+1,i+1};
            }
            mp[numbers[i]]=i;
        }
        return {};
    }
};


// 思路2 双指针