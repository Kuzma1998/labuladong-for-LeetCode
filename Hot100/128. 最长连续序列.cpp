// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题
// 示例 1：
// 输入：nums = [100,4,200,1,3,2]
// 输出：4
// 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
// 示例 2：

// 思路 哈希表

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // 构造有序的map
        map<int,int> s;
        for(int i=0;i<nums.size();++i){
                s[nums[i]]=i;
        }
        int len = 0;
        // 遍历map 
        for(auto it=s.begin();it!=s.end();){
            int elem = (*it).first;
            int curL =0;
            // 如果进入过 ，it就加上进去的次数
            bool flag = false;
            while(s.find(elem)!=s.end()){
                ++curL;
                ++elem;
                it++;
                flag = true;
            }
            // 没进去 it+1
            if(flag==false)
                ++it;
            len = max(len,curL);
        }
        return len;
    }
};



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            // 这是一个全新的数，前面没有连续的 查找
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;           
    }
};
