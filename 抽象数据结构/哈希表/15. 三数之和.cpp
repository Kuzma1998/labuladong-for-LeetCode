


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 数组排序
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        //
        for(int i=0;i<nums.size();++i){
            vector<vector<int>> answers = twoSumTarget(nums,i+1,-nums[i]);
            for(auto ans:answers){
                ans.push_back(nums[i]);
                res.push_back(ans);
            }
            while(i<nums.size()-1&&nums[i]==nums[i+1]){
                ++i;
            }
        }
        return res;
    }
    
    vector<vector<int>> twoSumTarget(vector<int>& nums,int start, int target) {
        int l = start,r = nums.size()-1;
        vector<vector<int>> ans;
        while(l<r){
            int left = nums[l],right = nums[r];
            int sum = nums[l]+nums[r];
            // 利用有序来做
            if(sum>target){
                while(l<r&&nums[r]==right)
                    --r;
            }
            else if(sum<target){
                while(l<r&&nums[l]==left)
                    ++l;
            }
            else{
                ans.push_back({nums[l],nums[r]});
                while(l<r&&nums[l]==left)
                    ++l;
                while(l<r&&nums[r]==right)
                    --r;
            }
        }
        return ans;
    }
};