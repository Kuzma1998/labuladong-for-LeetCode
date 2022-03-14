/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2022-03-14 21:17:18
 */
// 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
// 其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
// 示例
// 输入: [1,2,3,4,5]
// 输出: [120,60,40,30,24]
// 思路：维护两个数组，一个保存索引i左边的所有数的积，一个保存索引i右边所有数的积即可
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int sz = a.size();
        if(sz==0)
            return {};
        vector<int> left(sz,1);
        vector<int> right(sz,1);
        for(int i=1;i<sz;++i){
            left[i]=left[i-1]*a[i-1];
        }
        for(int i=sz-2;i>=0;--i){
            right[i] = right[i+1]*a[i+1];
        }
        vector<int> ans(sz,1);
        for(int i=0;i<sz;++i)
            ans[i] = right[i]*left[i];
        return ans;
    }
};