// nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。
// 给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。
// 对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，
// 并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。
// 返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。

// 输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
// 输出：[-1,3,-1]
// 解释：nums1 中每个值的下一个更大元素如下所述：
// - 4 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
// - 1 ，用加粗斜体标识，nums2 = [1,3,4,2]。下一个更大元素是 3 。
// - 2 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 

// 暴力法
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //存入nums2对应元素的索引
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();++i){
            mp[nums2[i]] = i;
        }
        vector<int> results(nums1.size(),-1);
        for(int i=0;i<nums1.size();++i){
            // 对于nums1里面的元素,找到其在nums2里面的下标
            int index = mp[nums1[i]];
            for(int j=index;j<nums2.size();++j){
                if(nums2[j]>nums1[i]){
                    results[i] = nums2[j]; //查找
                    break;
                }
            }
        }
        return results;
    }
};


// 单调栈
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> result(nums1.size(), -1);
        if (nums1.size() == 0) return result;

        // 遍历nums1建立映射
        unordered_map<int, int> umap; // key:下标元素，value：下标
        for (int i = 0; i < nums1.size(); i++) {
            umap[nums1[i]] = i;
        }
        st.push(0);
        //遍历nums2
        for (int i = 1; i < nums2.size(); i++) {
            if (nums2[i] <= nums2[st.top()]) {           // 情况一
                st.push(i);
            } else {                                    // 情况三
                while (!st.empty() && nums2[i] > nums2[st.top()]) {
                    if (umap.count(nums2[st.top()]) > 0) { // 看是否是nums1里面的
                        int index = umap[nums2[st.top()]]; // 根据map找到nums2[st.top()] 在 nums1中的下标
                        result[index] = nums2[i];
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};