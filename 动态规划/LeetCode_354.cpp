#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
// bool cmp(vector<int> a, vector<int> b)
//     {
//         if(a[0]!=b[0])
//             return a[0]<=b[0];
//         else
//             return a[1]>=b[1];
//     }
 
// int main()
// {
// 	vector<vector<int>> vec = { {1,8}, {2,3} , {5,4} , {5,2} , {6,7} , {6,4} };
	
// 	sort(vec.begin(), vec.end(), cmp);
 
// 	for(auto p : vec)
// 		cout<<p[0]<<' '<<p[1]<<' '<<endl;
// 	return 0;
// }

// 先对二维数组排序按宽升序，宽相同高逆序.然后把高送入LIS即可
// 给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。
// 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
// 请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
// 注意：不允许旋转信封。



class Solution {
private:
    static bool cmp(vector<int> a, vector<int> b)
    {
        if(a[0]!=b[0])
            return a[0]<=b[0];
        else
            return a[1]>=b[1];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> height(n);
        for(int i=0;i<=n-1;++i){
            height[i] = envelopes[i][1];
        }
        return lengthOfLIS(height);
    }
    int lengthOfLIS(vector<int>& nums) {
        int length = nums.size();
        vector<int> dp(length,1);//初始状态dp[0] =1;
        for(int i=0;i<=length-1;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){//选择条件
                    dp[i] = max(dp[i],1+dp[j]);//状态转移
                }
            }
        }
        int ans = 0;
        for(int i=0;i<=dp.size()-1;i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
 