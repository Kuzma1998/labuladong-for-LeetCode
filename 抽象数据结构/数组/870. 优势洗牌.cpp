/*
 * @Descripttion: 
 * @version: 
 * @Author: Li Jiaxin
 * @Date: 2021-10-10 09:36:40
 * @LastEditors: Li Jiaxin
 * @LastEditTime: 2021-10-10 09:42:02
 * 
 */
// 给定两个大小相等的数组 A 和 B，A 相对于 B 的优势可以用满足 A[i] > B[i] 的索引 i 的数目来描述。
// 返回 A 的任意排列，使其相对于 B 的优势最大化。

// 输入：A = [2,7,11,15], B = [1,10,4,11]
// 输出：[2,11,7,15]

// 思路：A排序，B排序，用A的最大比B的最大，若A>B，则取A的最大放到的b最大的位置上，否则取A的最小放到此位置。


bool compare(const pair<int,int> a,const pair<int,int> b){
        return a.first>b.first;
    }

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n =nums2.size();
        // A,B排序
        sort(nums1.begin(),nums1.end());
        vector<pair<int,int>> sorted_b;
        for(int i=0;i<n;++i){
            sorted_b.push_back({nums2[i],i});
        }
        sort(sorted_b.begin(),sorted_b.end(),compare);// B降序

        vector<int> ans(n);
        int b_start =0,end = n-1,a_start=0;
        // 遍历b，寻找正确的位置
        while(b_start<n){
            if(nums1[end]>sorted_b[b_start].first){
                ans[sorted_b[b_start].second] = nums1[end];
                ++b_start;
                --end;
            }else{
                ans[sorted_b[b_start].second] = nums1[a_start];
                ++a_start;
                ++b_start;
            }      
        }
        return ans;
    }
};