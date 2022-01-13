// 给定两个数组，编写一个函数来计算它们的交集
// 输入：nums1 = [1,2,2,1], nums2 = [2,2]
// 输出：[2]

// 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1,s2;
        for(int i=0;i<nums1.size();++i){
            if(!s1.count(nums1[i])){
                s1.insert(nums1[i]);
            }
        }
        for(auto i:nums2){
            if(!s2.count(i))
                s2.insert(i);
        }
        vector<int> ans;
        for(auto i:s2){
            if(s1.count(i))
                ans.push_back(i);
        }
        return ans;
    }
};


// 代码随想录
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};